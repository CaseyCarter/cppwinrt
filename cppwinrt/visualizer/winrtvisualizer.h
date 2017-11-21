#pragma once

struct CWinrtVisualizer : winrt::implements<CWinrtVisualizer,
                                           ::Microsoft::VisualStudio::Debugger::ComponentInterfaces::IDkmCustomVisualizer,
                                           ::Microsoft::VisualStudio::Debugger::ComponentInterfaces::IDkmIntrinsicFunctionEvaluator140,
                                           ::Microsoft::VisualStudio::Debugger::ComponentInterfaces::IDkmILFailureReasonResolver>
{

public:
    CWinrtVisualizer()
    {
    }

    // IDkmCustomVisualizer
public:
    STDMETHOD(EvaluateVisualizedExpression)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResult** ppResultObject
        );
    STDMETHOD(UseDefaultEvaluationBehavior)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _Out_ bool* pUseDefaultEvaluationBehavior,
        _Deref_out_opt_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResult** ppDefaultEvaluationResult
        );
    STDMETHOD(GetChildren)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _In_ UINT32 InitialRequestSize,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmInspectionContext* pInspectionContext,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression*>* pInitialChildren,
        _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResultEnumContext** ppEnumContext
        );
    STDMETHOD(GetItems)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResultEnumContext* pEnumContext,
        _In_ UINT32 StartIndex,
        _In_ UINT32 Count,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression*>* pItems
        );
    STDMETHOD(SetValueAsString)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _In_ Microsoft::VisualStudio::Debugger::DkmString* pValue,
        _In_ UINT32 Timeout,
        _Deref_out_opt_ Microsoft::VisualStudio::Debugger::DkmString** ppErrorText
        );
    STDMETHOD(GetUnderlyingString)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _Deref_out_opt_ Microsoft::VisualStudio::Debugger::DkmString** ppStringValue
        );

    //IDkmIntrinsicFunctionEvaluator140
    STDMETHOD(Execute)(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::IL::DkmILExecuteIntrinsic* pExecuteIntrinsic,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmILContext* pILContext,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::IL::DkmCompiledILInspectionQuery* pInspectionQuery,
        _In_ const Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::IL::DkmILEvaluationResult*>& Arguments,
        _In_opt_ Microsoft::VisualStudio::Debugger::DkmReadOnlyCollection<Microsoft::VisualStudio::Debugger::Evaluation::DkmCompiledInspectionQuery*>* pSubroutines,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::IL::DkmILEvaluationResult*>* pResults,
        _Out_ Microsoft::VisualStudio::Debugger::Evaluation::IL::DkmILFailureReason_t* pFailureReason
        );

    // IDkmILFailureReasonResolver
    virtual HRESULT STDMETHODCALLTYPE ResolveILFailureReason(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmCompiledInspectionQuery* pQuery,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::IL::DkmILFailureReason_t ErrorCode,
        _Deref_out_ Microsoft::VisualStudio::Debugger::DkmString** ppErrorMessage
    );

};
