#pragma once

// Metatdata for resolving a runtime class property value
struct PropertyData {
    std::wstring iid;
    int32_t index;
    std::wstring abiType;
    std::wstring displayType;
    std::wstring displayName;
    bool isObject;
};

// CObjectVisualizer provides the visualization data model for WinRT objects, 
// both for root-level RAII IInspectables, and for nested ABI IInspectable properties.
struct __declspec(uuid("c7da92da-3bc9-4312-8a93-46f480663980"))
CObjectVisualizer : winrt::implements<CObjectVisualizer, ::IUnknown>
{
    CObjectVisualizer(Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression, bool isAbiObject)
    {
        m_pVisualizedExpression = make_com_ptr(pVisualizedExpression);
        m_isAbiObject = isAbiObject;
    }

    ~CObjectVisualizer()
    {
    }

    static HRESULT CreateEvaluationResult(_In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression, _In_ bool isAbiObject, _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResult** ppResultObject);

    HRESULT CreateEvaluationResult(_Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResult** ppResultObject);

    HRESULT GetChildren(
        _In_ UINT32 InitialRequestSize,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmInspectionContext* pInspectionContext,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression*>* pInitialChildren,
        _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResultEnumContext** ppEnumContext
    );

    HRESULT GetItems(
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression,
        _In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResultEnumContext* pEnumContext,
        _In_ UINT32 StartIndex,
        _In_ UINT32 Count,
        _Out_ Microsoft::VisualStudio::Debugger::DkmArray<Microsoft::VisualStudio::Debugger::Evaluation::DkmChildVisualizedExpression*>* pItems
    );

private:
    HRESULT GetPropertyData();
    winrt::com_ptr<Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression> m_pVisualizedExpression;
    bool m_isAbiObject;
    std::vector<PropertyData> m_propertyData;
    bool m_isStringable{ false };
};
