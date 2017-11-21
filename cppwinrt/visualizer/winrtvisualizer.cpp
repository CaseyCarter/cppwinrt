#include "pch.h"
#include "winrtvisualizer.h"
#include "CObjectVisualizer.h"
#include "CPropertyVisualizer.h"

using namespace Microsoft::VisualStudio::Debugger;
using namespace Microsoft::VisualStudio::Debugger::Evaluation;

HRESULT CWinrtVisualizer::EvaluateVisualizedExpression(
    _In_ DkmVisualizedExpression* pVisualizedExpression,
    _Deref_out_ DkmEvaluationResult** ppResultObject
)
{
    try
    {
        winrt::com_ptr<IUnknown> pUnkTypeSymbol;
        IF_FAIL_RET(pVisualizedExpression->GetSymbolInterface(__uuidof(IDiaSymbol), pUnkTypeSymbol.put()));

        winrt::com_ptr<IDiaSymbol> pTypeSymbol = pUnkTypeSymbol.as<IDiaSymbol>();

        CComBSTR bstrTypeName;
        IF_FAIL_RET(pTypeSymbol->get_name(&bstrTypeName));

        if (wcscmp(bstrTypeName, L"winrt::Windows::Foundation::IInspectable") == 0)
        {
            IF_FAIL_RET(CObjectVisualizer::CreateEvaluationResult(pVisualizedExpression, ppResultObject));
        }

        IF_FAIL_RET(pVisualizedExpression->SetDataItem(DkmDataCreationDisposition::CreateNew, *ppResultObject));

        return S_OK;
    }
    catch (...)
    {
        // If something goes wrong, just fail to display object/property.  Don't take down VS.
        return E_FAIL;
    }
}

HRESULT CWinrtVisualizer::UseDefaultEvaluationBehavior(
    _In_ DkmVisualizedExpression* /*pVisualizedExpression*/,
    _Out_ bool* pUseDefaultEvaluationBehavior,
    _Deref_out_opt_ DkmEvaluationResult** ppDefaultEvaluationResult
)
{
    *pUseDefaultEvaluationBehavior = false;
    *ppDefaultEvaluationResult = nullptr;

    return S_OK;
}

HRESULT CWinrtVisualizer::GetChildren(
    _In_ DkmVisualizedExpression* pVisualizedExpression,
    _In_ UINT32 InitialRequestSize,
    _In_ DkmInspectionContext* pInspectionContext,
    _Out_ DkmArray<DkmChildVisualizedExpression*>* pInitialChildren,
    _Deref_out_ DkmEvaluationResultEnumContext** ppEnumContext
)
{
    try
    {
        winrt::com_ptr<CObjectVisualizer> pObjectVisualizer;
        HRESULT hr = pVisualizedExpression->GetDataItem(pObjectVisualizer.put());
        if (SUCCEEDED(hr))
        {
            IF_FAIL_RET(pObjectVisualizer->GetChildren(InitialRequestSize, pInspectionContext, pInitialChildren, ppEnumContext));
        }
        else
        {
            winrt::com_ptr<CPropertyVisualizer> pPropertyVisualizer;
            hr = pVisualizedExpression->GetDataItem(pPropertyVisualizer.put());
            if (SUCCEEDED(hr))
            {
                IF_FAIL_RET(pPropertyVisualizer->GetChildren(InitialRequestSize, pInspectionContext, pInitialChildren, ppEnumContext));
            }
        }

        return hr;
    }
    catch (...)
    {
        // If something goes wrong, just fail to display object/property.  Don't take down VS.
        return E_FAIL;
    }
}

HRESULT CWinrtVisualizer::GetItems(
    _In_ DkmVisualizedExpression* pVisualizedExpression,
    _In_ DkmEvaluationResultEnumContext* pEnumContext,
    _In_ UINT32 StartIndex,
    _In_ UINT32 Count,
    _Out_ DkmArray<DkmChildVisualizedExpression*>* pItems
)
{
    try
    {
        winrt::com_ptr<CObjectVisualizer> pObjectVisualizer;
        HRESULT hr = pVisualizedExpression->GetDataItem(pObjectVisualizer.put());
        if (SUCCEEDED(hr))
        {
            IF_FAIL_RET(pObjectVisualizer->GetItems(pVisualizedExpression, pEnumContext, StartIndex, Count, pItems));
        }
        else
        {
            winrt::com_ptr<CPropertyVisualizer> pPropertyVisualizer;
            hr = pVisualizedExpression->GetDataItem(pPropertyVisualizer.put());
            if (SUCCEEDED(hr))
            {
                IF_FAIL_RET(pPropertyVisualizer->GetItems(pEnumContext, StartIndex, Count, pItems));
            }
        }

        return hr;
    }
    catch (...)
    {
        // If something goes wrong, just fail to display object/property.  Don't take down VS.
        return E_FAIL;
    }
}

HRESULT CWinrtVisualizer::SetValueAsString(
    _In_ DkmVisualizedExpression* pVisualizedExpression,
    _In_ DkmString* pValue,
    _In_ UINT32 Timeout,
    _Deref_out_opt_ DkmString** ppErrorText
)
{
    try
    {
        winrt::com_ptr<CPropertyVisualizer> pPropertyVisualizer;
        HRESULT hr = pVisualizedExpression->GetDataItem(pPropertyVisualizer.put());
        if (SUCCEEDED(hr))
        {
            IF_FAIL_RET(pPropertyVisualizer->SetValueAsString(pValue, Timeout, ppErrorText));
        }

        return hr;
    }
    catch (...)
    {
        // If something goes wrong, just fail to update object/property.  Don't take down VS.
        return E_FAIL;
    }
}

HRESULT CWinrtVisualizer::GetUnderlyingString(
    _In_ DkmVisualizedExpression* pVisualizedExpression,
    _Deref_out_opt_ DkmString** ppStringValue
)
{
    try
    {
        HRESULT hr = E_NOTIMPL;

        winrt::com_ptr<CPropertyVisualizer> pPropertyVisualizer;
        hr = pVisualizedExpression->GetDataItem(pPropertyVisualizer.put());
        if (SUCCEEDED(hr))
        {
            IF_FAIL_RET(pPropertyVisualizer->GetUnderlyingString(ppStringValue));
        }

        return hr;
    }
    catch (...)
    {
        // If something goes wrong, just fail to display object/property.  Don't take down VS.
        return E_FAIL;
    }
}

HRESULT CWinrtVisualizer::Execute(
    _In_ Evaluation::IL::DkmILExecuteIntrinsic* /*pExecuteIntrinsic*/,
    _In_ Evaluation::DkmILContext* /*pILContext*/,
    _In_ Evaluation::IL::DkmCompiledILInspectionQuery* /*pInspectionQuery*/,
    _In_ const DkmArray<Evaluation::IL::DkmILEvaluationResult*>& /*Arguments*/,
    _In_opt_ DkmReadOnlyCollection<Evaluation::DkmCompiledInspectionQuery*>* /*pSubroutines*/,
    _Out_ DkmArray<Evaluation::IL::DkmILEvaluationResult*>* /*pResults*/,
    _Out_ Evaluation::IL::DkmILFailureReason_t* /*pFailureReason*/
)
{
    return E_NOTIMPL;
}

HRESULT CWinrtVisualizer::ResolveILFailureReason(
    _In_ Evaluation::DkmCompiledInspectionQuery* /*pQuery*/,
    _In_ Evaluation::IL::DkmILFailureReason_t /*ErrorCode*/,
    _Deref_out_ DkmString** /*ppErrorMessage*/
)
{
    return E_NOTIMPL;
}