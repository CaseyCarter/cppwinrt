#include "pch.h"
#include "CPropertyVisualizer.h"

using namespace Microsoft::VisualStudio::Debugger;
using namespace Microsoft::VisualStudio::Debugger::Evaluation;

//static 
HRESULT CPropertyVisualizer::CreateVisualizedExpression(
        _In_ const wchar_t* propName,
        _In_ const wchar_t* cast,
        _In_ const wchar_t* iid,
        _In_ int index,
        _In_ const wchar_t* type,
        _In_ DkmVisualizedExpression* pParent,
        _Deref_out_ DkmChildVisualizedExpression** ppResult
        )
{
    *ppResult = nullptr;

    auto valueHome = make_com_ptr(pParent->ValueHome());
    winrt::com_ptr<DkmPointerValueHome> pParentPointerValueHome = valueHome.as<DkmPointerValueHome>();
    UINT64 addrMember = pParentPointerValueHome->Address();

    wchar_t wszEvalText[500];

    if((pParent->RuntimeInstance()->Process()->SystemInformation()->Flags() & DefaultPort::DkmSystemInformationFlags::Is64Bit) != 0)
    {
        swprintf_s(wszEvalText, sizeof(wszEvalText) / sizeof(wchar_t), L"%sWINRT_get_val(((winrt::Windows::Foundation::IInspectable*)0x%I64x), L\"{%s}\", %i).%s", cast, addrMember, iid, index, type);
    }
    else
    {
        swprintf_s(wszEvalText, sizeof(wszEvalText) / sizeof(wchar_t), L"%sWINRT_get_val(((winrt::Windows::Foundation::IInspectable*)0x%08x), L\"{%s}\", %i).%s", cast, (DWORD)addrMember, iid, index, type);
    }
    winrt::com_ptr<DkmString> pEvalText;
    IF_FAIL_RET(DkmString::Create(DkmSourceString(wszEvalText), pEvalText.put()));

    winrt::com_ptr<DkmLanguageExpression> pLanguageExpression;
    IF_FAIL_RET(DkmLanguageExpression::Create(
        pParent->InspectionContext()->Language(),
        DkmEvaluationFlags::TreatAsExpression,
        pEvalText.get(),
        DkmDataItem::Null(),
        pLanguageExpression.put()
        ));

    winrt::com_ptr<DkmEvaluationResult> pPropertyEvaluationResult;
    IF_FAIL_RET(pParent->EvaluateExpressionCallback(
        pParent->InspectionContext(),
        pLanguageExpression.get(),
        pParent->StackFrame(),
        pPropertyEvaluationResult.put()
        ));

    if (pPropertyEvaluationResult->TagValue() == DkmEvaluationResult::Tag::SuccessResult)
    {
        winrt::com_ptr<DkmSuccessEvaluationResult> pPropertySuccessEvaluationResult = pPropertyEvaluationResult.as<DkmSuccessEvaluationResult>();

        winrt::com_ptr<DkmString> pName;
        IF_FAIL_RET(DkmString::Create(propName, pName.put()));

        winrt::com_ptr<DkmString> pType;
        if (wcscmp(type, L"s") == 0)
        {
            IF_FAIL_RET(DkmString::Create(L"winrt::hstring", pType.put()));
        }
        else
        {
            IF_FAIL_RET(DkmString::Create(pPropertySuccessEvaluationResult->Type(), pType.put()));
        }

        winrt::com_ptr<DkmSuccessEvaluationResult> pSuccessEvaluationResult;
        IF_FAIL_RET(DkmSuccessEvaluationResult::Create(
            pParent->InspectionContext(),
            pParent->StackFrame(),
            pName.get(),
            pPropertySuccessEvaluationResult->FullName(),
            pPropertySuccessEvaluationResult->Flags(),
            pPropertySuccessEvaluationResult->Value(),
            pPropertySuccessEvaluationResult->EditableValue(),
            pType.get(),
            pPropertySuccessEvaluationResult->Category(),
            pPropertySuccessEvaluationResult->Access(),
            pPropertySuccessEvaluationResult->StorageType(),
            pPropertySuccessEvaluationResult->TypeModifierFlags(),
            pPropertySuccessEvaluationResult->Address(),
            pPropertySuccessEvaluationResult->CustomUIVisualizers(),
            pPropertySuccessEvaluationResult->ExternalModules(),
            DkmDataItem::Null(),
            pSuccessEvaluationResult.put()
            ));

        winrt::com_ptr<DkmPointerValueHome> pPointerValueHome;
        IF_FAIL_RET(DkmPointerValueHome::Create(addrMember, pPointerValueHome.put()));

        winrt::com_ptr<DkmChildVisualizedExpression> pChildVisualizedExpression;
        IF_FAIL_RET(DkmChildVisualizedExpression::Create(
                pParent->InspectionContext(),
                pParent->VisualizerId(),
                pParent->SourceId(),
                pParent->StackFrame(),
                pPointerValueHome.get(),
                pSuccessEvaluationResult.get(),
                pParent,
                2,
                DkmDataItem::Null(),
                pChildVisualizedExpression.put()
                ));

        winrt::com_ptr<CPropertyVisualizer> pPropertyVisualizer = winrt::make_self<CPropertyVisualizer>(pChildVisualizedExpression.get(), pPropertySuccessEvaluationResult.get());
        IF_FAIL_RET(pChildVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, pPropertyVisualizer.get()));

        *ppResult = pChildVisualizedExpression.detach();
    }
    else
    {
        // The evalauation failed. This is unexpected 
        return E_FAIL;
    }

    return S_OK;
}


HRESULT CPropertyVisualizer::GetChildren(
        _In_ UINT32 InitialRequestSize,
        _In_ DkmInspectionContext* pInspectionContext,
        _Out_ DkmArray<DkmChildVisualizedExpression*>* pVisualizedInitialChildren,
        _Deref_out_ DkmEvaluationResultEnumContext** ppEnumContext
        )
{
    // Forward this on to the EE. 
    CAutoDkmArray<DkmEvaluationResult*> initialChildren;
    IF_FAIL_RET(m_pVisualizedExpression->GetChildrenCallback(m_pEEEvaluationResult.get(), InitialRequestSize, pInspectionContext, &initialChildren, ppEnumContext));

    // Need to create a DkmArray of DkmChildVisualizedExpression that contain the evaluation results and return that.
    DkmAllocArray(initialChildren.Length, pVisualizedInitialChildren);
    
    for (DWORD i = 0; i < initialChildren.Length; i++)
    {
        auto pCurrEvaluationResult = make_com_ptr(initialChildren.Members[i]);
        
        if (pCurrEvaluationResult->TagValue() != DkmEvaluationResult::Tag::SuccessResult)
        {
            return E_FAIL;
        }

        DkmSuccessEvaluationResult* pCurrSuccessEvaluationResult = (DkmSuccessEvaluationResult*)(pCurrEvaluationResult.get());

        winrt::com_ptr<DkmPointerValueHome> pPointerValueHome;
        IF_FAIL_RET(DkmPointerValueHome::Create(pCurrSuccessEvaluationResult->Address()->Value(), pPointerValueHome.put()));

        winrt::com_ptr<DkmChildVisualizedExpression> pChildVisualizedExpression;
        IF_FAIL_RET(DkmChildVisualizedExpression::Create(
            pInspectionContext,
            pChildVisualizedExpression->Parent()->VisualizerId(),
            pChildVisualizedExpression->Parent()->SourceId(),
            pChildVisualizedExpression->Parent()->StackFrame(),
            pPointerValueHome.get(),
            pCurrEvaluationResult.get(),
            m_pVisualizedExpression.get(), // (parent)
            i,
            this,
            pChildVisualizedExpression.put()
            ));

        pVisualizedInitialChildren->Members[i] = pChildVisualizedExpression.detach();
    }

    return S_OK;
}

HRESULT CPropertyVisualizer::GetItems(
        _In_ DkmEvaluationResultEnumContext* pEnumContext,
        _In_ UINT32 StartIndex,
        _In_ UINT32 Count,
        _Out_ DkmArray<DkmChildVisualizedExpression*>* pItems
        )
{
    // Forward this on to the EE. 
    CAutoDkmArray<DkmEvaluationResult*> evaluationResults;
    IF_FAIL_RET(m_pVisualizedExpression->GetItemsCallback(pEnumContext, StartIndex, Count, &evaluationResults));

    DkmAllocArray(evaluationResults.Length, pItems);
    
    for (DWORD i = 0; i < evaluationResults.Length; i++)
    {
        auto pCurrEvaluationResult = make_com_ptr(evaluationResults.Members[i]);
        
        if (pCurrEvaluationResult->TagValue() != DkmEvaluationResult::Tag::SuccessResult)
        {
            return E_FAIL;
        }

        DkmSuccessEvaluationResult* pCurrSuccessEvaluationResult = (DkmSuccessEvaluationResult*)(pCurrEvaluationResult.get());

        winrt::com_ptr<DkmPointerValueHome> pPointerValueHome;
        IF_FAIL_RET(DkmPointerValueHome::Create(pCurrSuccessEvaluationResult->Address() ? pCurrSuccessEvaluationResult->Address()->Value() : 0, pPointerValueHome.put()));

        winrt::com_ptr<DkmChildVisualizedExpression> pChildVisualizedExpression;
        IF_FAIL_RET(DkmChildVisualizedExpression::Create(
            m_pVisualizedExpression->InspectionContext(),
            m_pVisualizedExpression->Parent()->VisualizerId(),
            m_pVisualizedExpression->Parent()->SourceId(),
            m_pVisualizedExpression->Parent()->StackFrame(),
            pPointerValueHome.get(),
            pCurrEvaluationResult.get(),
            m_pVisualizedExpression.get(), // (parent)
            i,
            this,
            pChildVisualizedExpression.put()
            ));

        pItems->Members[i] = pChildVisualizedExpression.detach();
    }


    return S_OK;
}

HRESULT CPropertyVisualizer::SetValueAsString(
    _In_ DkmString* pValue,
    _In_ UINT32 Timeout,
    _Deref_out_opt_ DkmString** ppErrorText
    )
{
    // Forward this on to the EE. 
    IF_FAIL_RET(m_pVisualizedExpression->SetValueAsStringCallback(m_pEEEvaluationResult.get(), pValue, Timeout, ppErrorText));

    return S_OK;
}

HRESULT CPropertyVisualizer::GetUnderlyingString(
        _Deref_out_opt_ DkmString** ppStringValue
        )
{
    // Forward this on to the EE. 
    IF_FAIL_RET(m_pVisualizedExpression->GetUnderlyingStringCallback(m_pEEEvaluationResult.get(), ppStringValue));

    return S_OK;
}