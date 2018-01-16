#include "pch.h"
#include "CObjectVisualizer.h"
#include "CPropertyVisualizer.h"
#include "settings.h"

using namespace std::experimental::filesystem;
using namespace cppwinrt;
using namespace Microsoft::VisualStudio::Debugger;
using namespace Microsoft::VisualStudio::Debugger::Evaluation;

#define IID_IInspectable L"AF86E2E0-B12D-4C6A-9C5A-D7AA65101E90"
#define IID_IStringable  L"96369F54-8EB6-48F0-ABCE-C1B211E627C3"

constexpr struct
{
    PCWSTR propField;
    PCWSTR displayType;
}
g_categoryData[] = 
{
    { L"b", L"bool" },
    { L"c", L"wchar_t" },
    { L"i1", L"int8_t" },
    { L"i2", L"int16_t" },
    { L"i4", L"int32_t" },
    { L"i8", L"int64_t" },
    { L"u1", L"uint8_t" },
    { L"u2", L"uint16_t" },
    { L"u4", L"uint32_t" },
    { L"u8", L"uint64_t" },
    { L"r4", L"float" },
    { L"r8", L"double" },
    { L"s", L"HSTRING" },
    { L"g", L"GUID" },
};

static HRESULT EvaluatePropertyExpression(
    _In_ PropertyData const& prop,
    _In_ DkmVisualizedExpression* pExpression,
    _In_ DkmPointerValueHome* pObject,
    bool isAbiObject,
    _Out_ winrt::com_ptr<DkmEvaluationResult>& pEvaluationResult
)
{
    wchar_t abiAddress[40];
    bool is64Bit = ((pExpression->RuntimeInstance()->Process()->SystemInformation()->Flags() & DefaultPort::DkmSystemInformationFlags::Is64Bit) != 0);
    swprintf_s(abiAddress, is64Bit ? L"%s0x%I64x" : L"%s0x%08x", isAbiObject ? L"(::IUnknown*)" : L"*(::IUnknown**)", pObject->Address());
    wchar_t wszEvalText[500];
    std::wstring propCast;
    PCWSTR propField;
    if (prop.category < PropertyCategory::Value)
    {
        propField = g_categoryData[(int)prop.category].propField;
    }
    else
    {
        propField = L"v";
        propCast = L"*(" + prop.abiType + L"*)";
    }
    swprintf_s(wszEvalText, L"%sWINRT_abi_val(%s, L\"{%s}\", %i).%s", propCast.c_str(), abiAddress, prop.iid.c_str(), prop.index, propField);
#ifdef _DEBUG
    OutputDebugStringW(wszEvalText);
    OutputDebugStringW(L"\n");
#endif

    winrt::com_ptr<DkmString> pEvalText;
    IF_FAIL_RET(DkmString::Create(DkmSourceString(wszEvalText), pEvalText.put()));

    auto evalFlags = DkmEvaluationFlags::TreatAsExpression | DkmEvaluationFlags::ForceEvaluationNow | DkmEvaluationFlags::ForceRealFuncEval;

    auto inspectionContext = pExpression->InspectionContext();
    winrt::com_ptr<DkmLanguageExpression> pLanguageExpression;
    IF_FAIL_RET(DkmLanguageExpression::Create(
        inspectionContext->Language(),
        evalFlags,
        pEvalText.get(),
        DkmDataItem::Null(),
        pLanguageExpression.put()
    ));

    winrt::com_ptr<DkmInspectionContext> pInspectionContext;
    if ( (pExpression->InspectionContext()->EvaluationFlags() & evalFlags) != evalFlags)
    {
        DkmInspectionContext::Create(
            inspectionContext->InspectionSession(),
            inspectionContext->RuntimeInstance(),
            inspectionContext->Thread(),
            inspectionContext->Timeout(),
            evalFlags,
            inspectionContext->FuncEvalFlags(),
            inspectionContext->Radix(),
            inspectionContext->Language(),
            inspectionContext->ReturnValue(),
            pInspectionContext.put()
        );
    }
    else
    {
        pInspectionContext.copy_from(inspectionContext);
    }

    IF_FAIL_RET(pExpression->EvaluateExpressionCallback(
        pInspectionContext.get(),
        pLanguageExpression.get(),
        pExpression->StackFrame(),
        pEvaluationResult.put()
    ));

    return S_OK;
}

static HRESULT EvaluatePropertyString(
    _In_ PropertyData const& prop,
    _In_ DkmVisualizedExpression* pExpression,
    _In_ DkmPointerValueHome* pObject,
    bool isAbiObject,
    _Out_ winrt::com_ptr<DkmString>& pValue
)
{
    winrt::com_ptr<DkmEvaluationResult> pEvaluationResult;
    IF_FAIL_RET(EvaluatePropertyExpression(prop, pExpression, pObject, isAbiObject, pEvaluationResult));
    if (pEvaluationResult->TagValue() != DkmEvaluationResult::Tag::SuccessResult)
    {
        return E_FAIL;
    }
    winrt::com_ptr<DkmSuccessEvaluationResult> pSuccessEvaluationResult = pEvaluationResult.as<DkmSuccessEvaluationResult>();
    if (pSuccessEvaluationResult->Address()->Value() != 0)
    {
        pValue.copy_from(pSuccessEvaluationResult->Value());
    }
    return S_OK;
}

static HRESULT ObjectToString(
    _In_ DkmVisualizedExpression* pExpression,
    _In_ DkmPointerValueHome* pObject,
    bool isAbiObject,
    _Out_ winrt::com_ptr<DkmString>& pValue
)
{
    if (SUCCEEDED(EvaluatePropertyString({ IID_IStringable, 0, PropertyCategory::String }, pExpression, pObject, isAbiObject, pValue)))
    {
        if (!pValue || pValue->Length() == 0)
        {
            pValue = nullptr;
            IF_FAIL_RET(DkmString::Create(L"<Expand object to view properties>", pValue.put()));
        }
    }
    else
	{
		IF_FAIL_RET(DkmString::Create(L"<Object uninitialized or information unavailable>", pValue.put()));
	}

    return S_OK;
}

static HRESULT CreateChildVisualizedExpression(
    _In_ PropertyData const& prop,
    _In_ DkmVisualizedExpression* pParent,
    bool isAbiObject,
    _Deref_out_ DkmChildVisualizedExpression** ppResult
)
{
    *ppResult = nullptr;

    winrt::com_ptr<DkmEvaluationResult> pEvaluationResult;
    auto valueHome = make_com_ptr(pParent->ValueHome());
    winrt::com_ptr<DkmPointerValueHome> pParentPointer = valueHome.as<DkmPointerValueHome>();
    IF_FAIL_RET(EvaluatePropertyExpression(prop, pParent, pParentPointer.get(), isAbiObject, pEvaluationResult));
    if (pEvaluationResult->TagValue() != DkmEvaluationResult::Tag::SuccessResult)
    {
        return E_FAIL;
    }

    winrt::com_ptr<DkmSuccessEvaluationResult> pSuccessEvaluationResult = pEvaluationResult.as<DkmSuccessEvaluationResult>();
    winrt::com_ptr<DkmString> pValue;
    winrt::com_ptr<DkmPointerValueHome> pChildPointer;
    bool isNonNullObject = false;
    if (prop.category == PropertyCategory::Class)
    {
        auto childObjectAddress = pSuccessEvaluationResult->Address()->Value();
        if (childObjectAddress)
        {
            isNonNullObject = true;
            IF_FAIL_RET(DkmPointerValueHome::Create(childObjectAddress, pChildPointer.put()));
            IF_FAIL_RET(ObjectToString(pParent, pChildPointer.get(), true, pValue));
        }
    }
    if(!isNonNullObject)
    {
        winrt::com_ptr<DkmExpressionValueHome> expressionValueHome = make_com_ptr(pParent->ValueHome());
        pChildPointer = expressionValueHome.as<DkmPointerValueHome>();
        pValue.copy_from(pSuccessEvaluationResult->Value());
    }

    winrt::com_ptr<DkmString> pDisplayName;
    IF_FAIL_RET(DkmString::Create(prop.displayName.c_str(), pDisplayName.put()));

    PCWSTR displayType;
    if (prop.category < PropertyCategory::Value)
    {
        displayType = g_categoryData[(int)prop.category].displayType;
    }
    else
    {
        displayType = prop.displayType.c_str();
    }
    winrt::com_ptr<DkmString> pDisplayType;
    IF_FAIL_RET(DkmString::Create(displayType, pDisplayType.put()));

    winrt::com_ptr<DkmSuccessEvaluationResult> pVisualizedResult;
    IF_FAIL_RET(DkmSuccessEvaluationResult::Create(
        pParent->InspectionContext(),
        pParent->StackFrame(),
        pDisplayName.get(),
        pSuccessEvaluationResult->FullName(),
        pSuccessEvaluationResult->Flags(),
        pValue.get(),
        pSuccessEvaluationResult->EditableValue(),
        pDisplayType.get(),
        pSuccessEvaluationResult->Category(),
        pSuccessEvaluationResult->Access(),
        pSuccessEvaluationResult->StorageType(),
        pSuccessEvaluationResult->TypeModifierFlags(),
        pSuccessEvaluationResult->Address(),
        pSuccessEvaluationResult->CustomUIVisualizers(),
        pSuccessEvaluationResult->ExternalModules(),
        DkmDataItem::Null(),
        pVisualizedResult.put()
    ));

    winrt::com_ptr<DkmChildVisualizedExpression> pChildVisualizedExpression;
    IF_FAIL_RET(DkmChildVisualizedExpression::Create(
        pParent->InspectionContext(),
        pParent->VisualizerId(),
        pParent->SourceId(),
        pParent->StackFrame(),
        pChildPointer.get(),
        pVisualizedResult.get(),
        pParent,
        2,
        DkmDataItem::Null(),
        pChildVisualizedExpression.put()
    ));

    if (isNonNullObject)
    {
        winrt::com_ptr<CObjectVisualizer> pObjectVisualizer = winrt::make_self<CObjectVisualizer>(pChildVisualizedExpression.get(), true);
        IF_FAIL_RET(pChildVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, pObjectVisualizer.get()));
    }
    else
    {
        winrt::com_ptr<CPropertyVisualizer> pPropertyVisualizer = winrt::make_self<CPropertyVisualizer>(pChildVisualizedExpression.get(), pSuccessEvaluationResult.get());
        IF_FAIL_RET(pChildVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, pPropertyVisualizer.get()));
    }

    *ppResult = pChildVisualizedExpression.detach();

    return S_OK;
}

HRESULT CObjectVisualizer::GetPropertyData()
{
    winrt::com_ptr<DkmString> pValue;

    winrt::com_ptr<DkmChildVisualizedExpression> pPropertyVisualized;
    IF_FAIL_RET(CreateChildVisualizedExpression({ IID_IInspectable, -2, PropertyCategory::String }, m_pVisualizedExpression.get(), m_isAbiObject, pPropertyVisualized.put()));
    pPropertyVisualized->GetUnderlyingString(pValue.put());
    auto runtimeClassName = winrt::to_string(pValue->Value());
    auto type = meta::find_type(runtimeClassName);
    if (type == nullptr)
    {
        return E_FAIL;
    }

    for (meta::required const& required : type->token.get_class_required())
    {
        meta::token required_type_def = required.token.get_definition();
        std::string guid = required_type_def.get_guid("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X");
        std::wstring propIid(guid.cbegin(), guid.cend());

        if (propIid == IID_IStringable)
        {
            m_isStringable = true;
            continue;
        }

        int32_t propIndex = -1;
        for (meta::method const& method : required.token.get_methods())
        {
            propIndex++;

            auto isGetter = method.is_special() && starts_with(method.raw_name, "get_");
            if (!isGetter)
            {
                continue;
            }

            meta::param const& param = method.return_type;
            meta::signature const signature = param.signature;
            CorElementType category = signature.get_category();

            PropertyCategory propCategory;
            std::wstring propAbiType;
            std::wstring propDisplayType;
            if ((category == ELEMENT_TYPE_VALUETYPE) || (category == ELEMENT_TYPE_CLASS))
            {
                meta::token token = signature.get_token();
                std::string typeName = token.get_name();
                
                if (typeName == "GUID")
                {
                    propCategory = PropertyCategory::Guid;
                }
                else
                {
                    std::wstring metadataTypename(typeName.cbegin(), typeName.cend());

                    // Types come back from winmd files with '.', need to be '::'
                    // Ex. Windows.Foundation.Uri needs to be Windows::Foundation::Uri
                    wchar_t cppTypename[500];
                    size_t i, j;
                    for (i = 0, j = 0; i < (metadataTypename.length() + 1); i++, j++)
                    {
                        if (metadataTypename[i] == L'.')
                        {
                            cppTypename[j++] = L':';
                            cppTypename[j] = L':';
                        }
                        else
                        {
                            cppTypename[j] = metadataTypename[i];
                        }
                    }

                    propDisplayType = std::wstring(L"winrt::") + cppTypename;
                    if (category == ELEMENT_TYPE_CLASS)
                    {
                        propCategory = PropertyCategory::Class;
                        propAbiType = L"winrt::impl::IInspectable*";
                    }
                    else
                    {
                        propCategory = PropertyCategory::Value;
                        propAbiType = propDisplayType;
                    }
                }
            }
            else
            {
                if( (category < ELEMENT_TYPE_BOOLEAN) || (category > ELEMENT_TYPE_STRING) )
                {
                    continue;
                }
                propCategory = (PropertyCategory)(category - ELEMENT_TYPE_BOOLEAN);
            }

            auto methodName = method.get_name();
            std::wstring propDisplayName(methodName.cbegin(), methodName.cend());
            m_propertyData.push_back({ propIid, propIndex, propCategory, propAbiType, propDisplayType, propDisplayName });
        }
    }

    return S_OK;
}

HRESULT CObjectVisualizer::CreateEvaluationResult(_In_ DkmVisualizedExpression* pVisualizedExpression, _In_ bool isAbiObject, _Deref_out_ DkmEvaluationResult** ppResultObject)
{
    winrt::com_ptr<CObjectVisualizer> pObjectVisualizer = winrt::make_self<CObjectVisualizer>(pVisualizedExpression, isAbiObject);

    pVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, pObjectVisualizer.get());

    IF_FAIL_RET(pObjectVisualizer->CreateEvaluationResult(ppResultObject));

    IF_FAIL_RET(pVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, *ppResultObject));

    return S_OK;
}

HRESULT CObjectVisualizer::CreateEvaluationResult(_Deref_out_ DkmEvaluationResult** ppResultObject)
{
    winrt::com_ptr<DkmRootVisualizedExpression> pRootVisualizedExpression = m_pVisualizedExpression.as<DkmRootVisualizedExpression>();

    auto valueHome = make_com_ptr(m_pVisualizedExpression->ValueHome());
    winrt::com_ptr<DkmPointerValueHome> pPointerValueHome = valueHome.as<DkmPointerValueHome>();

    winrt::com_ptr<DkmString> pValue;
    IF_FAIL_RET(ObjectToString(m_pVisualizedExpression.get(), pPointerValueHome.get(), m_isAbiObject, pValue));

    winrt::com_ptr<DkmDataAddress> pAddress;
    IF_FAIL_RET(DkmDataAddress::Create(m_pVisualizedExpression->StackFrame()->RuntimeInstance(), pPointerValueHome->Address(), nullptr, pAddress.put()));

    winrt::com_ptr<DkmSuccessEvaluationResult> pSuccessEvaluationResult;
    IF_FAIL_RET(DkmSuccessEvaluationResult::Create(
        m_pVisualizedExpression->InspectionContext(),
        m_pVisualizedExpression->StackFrame(),
        pRootVisualizedExpression->Name(),
        pRootVisualizedExpression->FullName(),
        DkmEvaluationResultFlags::Expandable | DkmEvaluationResultFlags::ReadOnly,
        pValue.get(),
        pValue.get(),
        pRootVisualizedExpression->Type(),
        DkmEvaluationResultCategory::Class,
        DkmEvaluationResultAccessType::None,
        DkmEvaluationResultStorageType::None,
        DkmEvaluationResultTypeModifierFlags::None,
        pAddress.get(),
        (DkmReadOnlyCollection<DkmCustomUIVisualizerInfo*>*)nullptr,
        (DkmReadOnlyCollection<DkmModuleInstance*>*)nullptr,
        DkmDataItem::Null(),
        pSuccessEvaluationResult.put()
    ));

    pSuccessEvaluationResult->SetDataItem(DkmDataCreationDisposition::CreateNew, this);

    *ppResultObject = (DkmEvaluationResult*)pSuccessEvaluationResult.detach();

    return S_OK;
}

HRESULT CObjectVisualizer::GetChildren(
    _In_ UINT32 /*InitialRequestSize*/,
    _In_ DkmInspectionContext* pInspectionContext,
    _Out_ DkmArray<DkmChildVisualizedExpression*>* pInitialChildren,
    _Deref_out_ DkmEvaluationResultEnumContext** ppEnumContext
)
{
    IF_FAIL_RET(GetPropertyData());

    winrt::com_ptr<DkmEvaluationResultEnumContext> pEnumContext;
    IF_FAIL_RET(DkmEvaluationResultEnumContext::Create(
        m_propertyData.size(),
        m_pVisualizedExpression->StackFrame(),
        pInspectionContext,
        this,
        pEnumContext.put()));

    DkmAllocArray(0, pInitialChildren);
    *ppEnumContext = pEnumContext.detach();

    return S_OK;
}

HRESULT CObjectVisualizer::GetItems(
    _In_ DkmVisualizedExpression* /*pVisualizedExpression*/,
    _In_ DkmEvaluationResultEnumContext* /*pEnumContext*/,
    _In_ UINT32 StartIndex,
    _In_ UINT32 Count,
    _Out_ DkmArray<DkmChildVisualizedExpression*>* pItems
)
{
    std::list<winrt::com_ptr<DkmChildVisualizedExpression>> childItems;

    for( auto childIndex = StartIndex; childIndex < StartIndex + Count; ++childIndex)
    {
        auto& prop = m_propertyData[childIndex];
        winrt::com_ptr<DkmChildVisualizedExpression> pPropertyVisualized;
        IF_FAIL_RET(CreateChildVisualizedExpression(prop, m_pVisualizedExpression.get(), m_isAbiObject, pPropertyVisualized.put()));
        childItems.push_back(pPropertyVisualized);
    }

    CAutoDkmArray<DkmChildVisualizedExpression*> resultValues;
    IF_FAIL_RET(DkmAllocArray(childItems.size(), &resultValues));

    UINT32 j = 0;
    auto pos = childItems.begin();
    while (pos != childItems.end())
    {
        winrt::com_ptr<DkmChildVisualizedExpression> pCurr = *pos;
        resultValues.Members[j++] = pCurr.detach();
        pos++;
    }

    *pItems = resultValues.Detach();

    return S_OK;
}
