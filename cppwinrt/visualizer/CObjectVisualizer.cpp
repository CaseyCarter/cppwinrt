#include "pch.h"
#include "CObjectVisualizer.h"
#include "CPropertyVisualizer.h"
#include "settings.h"

using namespace std::experimental::filesystem;
using namespace cppwinrt;
using namespace Microsoft::VisualStudio::Debugger;
using namespace Microsoft::VisualStudio::Debugger::Evaluation;

#define IID_IInspectableW L"AF86E2E0-B12D-4C6A-9C5A-D7AA65101E90"
#define IID_IStringable    "96369F54-8EB6-48F0-ABCE-C1B211E627C3"
#define IID_IStringableW  L"96369F54-8EB6-48F0-ABCE-C1B211E627C3"

//static 
HRESULT CObjectVisualizer::CreateEvaluationResult(_In_ DkmVisualizedExpression* pVisualizedExpression, _Deref_out_ DkmEvaluationResult** ppResultObject)
{
    winrt::com_ptr<CObjectVisualizer> pObjectVisualizer = winrt::make_self<CObjectVisualizer>(pVisualizedExpression);

    pVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, pObjectVisualizer.get());

    return pObjectVisualizer->CreateEvaluationResult(ppResultObject);
}

HRESULT CObjectVisualizer::CreateEvaluationResult(_Deref_out_ DkmEvaluationResult** ppResultObject)
{
    winrt::com_ptr<DkmRootVisualizedExpression> pRootVisualizedExpression = m_pVisualizedExpression.as<DkmRootVisualizedExpression>();

    auto pName = make_com_ptr(pRootVisualizedExpression->Name());
    auto pFullName = make_com_ptr(pRootVisualizedExpression->FullName());

    auto valueHome = make_com_ptr(m_pVisualizedExpression->ValueHome());
    winrt::com_ptr<DkmPointerValueHome> pPointerValueHome = valueHome.as<DkmPointerValueHome>();
    winrt::com_ptr<DkmString> pValue;

    winrt::com_ptr<DkmChildVisualizedExpression> pStringable;
    HRESULT hr = CPropertyVisualizer::CreateVisualizedExpression(L"Stringable", L"", IID_IStringableW, 0, L"s", m_pVisualizedExpression.get(), pStringable.put());
    if (SUCCEEDED(hr))
    {
        pStringable->GetUnderlyingString(pValue.put());
        if (pValue->Length() == 0)
        {
            IF_FAIL_RET(DkmString::Create(L"<Expand variable to view properties>", pValue.put()));
        }
    }
    else
    {
        IF_FAIL_RET(DkmString::Create(L"<Variable uninitialized or information unavailable>", pValue.put()));
    }

    winrt::com_ptr<DkmDataAddress> pAddress;
    IF_FAIL_RET(DkmDataAddress::Create(m_pVisualizedExpression->StackFrame()->RuntimeInstance(), pPointerValueHome->Address(), nullptr, pAddress.put()));

    winrt::com_ptr<DkmSuccessEvaluationResult> pSuccessEvaluationResult;
    IF_FAIL_RET(DkmSuccessEvaluationResult::Create(
        m_pVisualizedExpression->InspectionContext(),
        m_pVisualizedExpression->StackFrame(),
        pName.get(),
        pFullName.get(),
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

    *ppResultObject = (DkmEvaluationResult*)pSuccessEvaluationResult.detach();

    return hr;
}

struct natvis_property {
    std::string name;
    std::string cast;
    int32_t index;
    char const* field;
};

auto CObjectVisualizer::enum_natvis_interfaces(meta::type const& type)
{
    std::map<std::string, std::vector<natvis_property>> natvis_interfaces;
    bool is_stringable{};

    for (meta::required const& required : type.token.get_class_required())
    {
        std::vector<natvis_property> natvis_properties;
        int32_t property_index = -1;

        for (meta::method const& method : required.token.get_methods())
        {
            property_index++;

            if (!is_get_accessor(method))
            {
                continue;
            }

            meta::param const& param = method.return_type;
            meta::signature const signature = param.signature;
            CorElementType category = signature.get_category();
            char const* property_field = get_natvis_property_field(category);

            if (!property_field)
            {
                continue;
            }

            std::string property_cast;
            if (category == ELEMENT_TYPE_VALUETYPE)
            {
                meta::token property_token = signature.get_token();
                std::string property_typename = property_token.get_name();
                property_cast = "*(winrt::" + property_typename + "*)";
            }

            natvis_properties.push_back({ method.get_name(), property_cast, property_index, property_field });
        }

        meta::token required_type_def = required.token.get_definition();

        std::string iid = required_type_def.get_guid("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X");

        if (!natvis_properties.empty())
        {
            natvis_interfaces[iid] = std::move(natvis_properties);
        }
        else if (iid == IID_IStringable)
        {
            is_stringable = true;
        }
    }

    return std::make_pair(natvis_interfaces, is_stringable);
}

HRESULT CObjectVisualizer::GetChildren(
    _In_ UINT32 /*InitialRequestSize*/,
    _In_ DkmInspectionContext* pInspectionContext,
    _Out_ DkmArray<DkmChildVisualizedExpression*>* pInitialChildren,
    _Deref_out_ DkmEvaluationResultEnumContext** ppEnumContext
)
{
    add_input_spec(L"local");
    prepare_metadata();
    const meta::type *type = GetType();
    if (type == nullptr)
    {
        return E_FAIL;
    }

    UINT32 childCount = 0;
    auto interfaces = enum_natvis_interfaces(*type);
    for (const auto& interfaceItem : interfaces.first)
    {
        childCount += interfaceItem.second.size();
    }

    winrt::com_ptr<DkmEvaluationResultEnumContext> pEnumContext;
    IF_FAIL_RET(DkmEvaluationResultEnumContext::Create(
        childCount,
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

    add_input_spec(L"local");
    prepare_metadata();
    const meta::type *type = GetType();
    if (type == nullptr)
    {
        return E_FAIL;
    }

    HRESULT hr = S_OK;
    UINT current = 0;
    auto interfaces = enum_natvis_interfaces(*type);
    for (const auto& interfaceItem : interfaces.first)
    {
        for (const auto& propInfo : interfaceItem.second)
        {
            if ((current >= StartIndex) && (current < (StartIndex + Count)))
            {
                // Dkm objects all use wide chars
                wchar_t wszPropName[500];
                wchar_t wszCast[500];
                wchar_t wszIid[50];
                wchar_t wszType[5];
                swprintf_s(wszPropName, L"%S", propInfo.name.c_str());
                swprintf_s(wszCast, L"%S", propInfo.cast.c_str());
                swprintf_s(wszIid, L"%S", interfaceItem.first.c_str());
                swprintf_s(wszType, L"%S", propInfo.field);

                // Types come back from winmd files with '.', need to be '::'
                // Ex. Windows.Foundation.Uri needs to be Windows::Foundation::Uri
                if ((wcscmp(wszType, L"v") == 0) && (wcslen(wszCast) > 0))
                {
                    wchar_t wszCastReplaced[500];
                    size_t i, j;
                    for (i = 0, j = 0; i < (wcslen(wszCast) + 1); i++, j++)
                    {
                        if (wszCast[i] == '.')
                        {
                            wszCastReplaced[j++] = ':';
                            wszCastReplaced[j] = ':';
                        }
                        else
                        {
                            wszCastReplaced[j] = wszCast[i];
                        }
                    }

                    wcscpy_s(wszCast, wszCastReplaced);
                }

                if (wcscmp(wszType, L"cl") == 0)
                {
                    winrt::com_ptr<DkmChildVisualizedExpression> pPropertyVisualized;
                    hr = CPropertyVisualizer::CreateVisualizedExpression(wszPropName, wszCast, wszIid, propInfo.index, wszType, m_pVisualizedExpression.get(), pPropertyVisualized.put());
                    if (SUCCEEDED(hr))
                    {
                        childItems.push_back(pPropertyVisualized);
                    }
                }
                else
                {
                    winrt::com_ptr<DkmChildVisualizedExpression> pPropertyVisualized;
                    hr = CPropertyVisualizer::CreateVisualizedExpression(wszPropName, wszCast, wszIid, propInfo.index, wszType, m_pVisualizedExpression.get(), pPropertyVisualized.put());
                    if (SUCCEEDED(hr))
                    {
                        childItems.push_back(pPropertyVisualized);
                    }
                }
            }
            current++;
        }
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

    return hr;
}


bool CObjectVisualizer::is_get_accessor(meta::method const& method)
{
    if (method.is_special())
    {
        return starts_with(method.raw_name, "get_");
    }

    return false;
}

char const* CObjectVisualizer::get_natvis_property_field(CorElementType category)
{
    switch (category)
    {
    case ELEMENT_TYPE_BOOLEAN: return "b";
    case ELEMENT_TYPE_CHAR: return "c";
    case ELEMENT_TYPE_I1: return "i1";
    case ELEMENT_TYPE_I2: return "i2";
    case ELEMENT_TYPE_I4: return "i4";
    case ELEMENT_TYPE_I8: return "i8";
    case ELEMENT_TYPE_U1: return "u1";
    case ELEMENT_TYPE_U2: return "u2";
    case ELEMENT_TYPE_U4: return "u4";
    case ELEMENT_TYPE_U8: return "u8";
    case ELEMENT_TYPE_R4: return "r4";
    case ELEMENT_TYPE_R8: return "r8";
    case ELEMENT_TYPE_STRING: return "s";
    case ELEMENT_TYPE_VALUETYPE: return "v";
    case ELEMENT_TYPE_CLASS: return "cl";
    }
    return{};
}

const meta::type* CObjectVisualizer::GetType()
{
    winrt::com_ptr<DkmChildVisualizedExpression> pRuntimeClassNameVisualized;
    if (SUCCEEDED(CPropertyVisualizer::CreateVisualizedExpression(L"RuntimeClassName", L"", IID_IInspectableW, -2, L"s", m_pVisualizedExpression.get(), pRuntimeClassNameVisualized.put())))
    {
        winrt::com_ptr<DkmString> pValue;
        pRuntimeClassNameVisualized->GetUnderlyingString(pValue.put());
        std::string className = winrt::to_string(pValue->Value());

        return meta::find_type(className);
    }
    return nullptr;
}