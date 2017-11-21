#pragma once

struct __declspec(uuid("87feab93-47a3-4f55-b48b-a29317fa52da"))
CPropertyVisualizer : winrt::implements<CPropertyVisualizer, ::IUnknown>
{
private:
    // The DkmVisualizedExpression created for this object.
    winrt::com_ptr<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression> m_pVisualizedExpression;

    // The original evaluation result returned from the expression evaluator.
    winrt::com_ptr<Microsoft::VisualStudio::Debugger::Evaluation::DkmSuccessEvaluationResult> m_pEEEvaluationResult;

public:
    CPropertyVisualizer(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression* pVisualizedExpression,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmSuccessEvaluationResult* pEEEvaluationResult)
    {
        m_pVisualizedExpression = make_com_ptr(pVisualizedExpression);
        m_pEEEvaluationResult = make_com_ptr(pEEEvaluationResult);
    }

public:    
    // Generate a new DkmChildVisualizedExpression. This will have an instance of CPropertyVisualizer
    // in its data container
    static HRESULT CreateVisualizedExpression(
		_In_ const wchar_t* propName,
        _In_ const wchar_t* cast,
        _In_ const wchar_t* iid,
        _In_ int index,
		_In_ const wchar_t* type,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pParent,
        _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression** ppResult
        );

    HRESULT GetChildren(
        _In_ UINT32 InitialRequestSize,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmInspectionContext* pInspectionContext,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression*>* pInitialChildren,
        _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResultEnumContext** ppEnumContext
        );

    HRESULT GetItems(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResultEnumContext* pEnumContext,
        _In_ UINT32 StartIndex,
        _In_ UINT32 Count,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression*>* pItems
        );

    HRESULT SetValueAsString(
        _In_ Microsoft::VisualStudio::Debugger::DkmString* pValue,
        _In_ UINT32 Timeout,
        _Deref_out_opt_ Microsoft::VisualStudio::Debugger::DkmString** ppErrorText
        );

    HRESULT GetUnderlyingString(
        _Deref_out_opt_ Microsoft::VisualStudio::Debugger::DkmString** ppStringValue
        );
};