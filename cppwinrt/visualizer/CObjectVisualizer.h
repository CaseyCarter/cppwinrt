#pragma once

struct __declspec(uuid("c7da92da-3bc9-4312-8a93-46f480663980"))
CObjectVisualizer : winrt::implements<CObjectVisualizer, ::IUnknown>
{
private:
    winrt::com_ptr<Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression> m_pVisualizedExpression;

public:
    CObjectVisualizer(Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression)
    {
        m_pVisualizedExpression = make_com_ptr(pVisualizedExpression);
    }

public:
    static HRESULT CreateEvaluationResult(_In_ Microsoft::VisualStudio::Debugger::Evaluation::DkmVisualizedExpression* pVisualizedExpression, _Deref_out_ Microsoft::VisualStudio::Debugger::Evaluation::DkmEvaluationResult** ppResultObject);

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
    static HRESULT EnsureIndex();

    const cppwinrt::meta::type* GetType();

    static auto enum_natvis_interfaces(cppwinrt::meta::type const& type);

    static bool is_get_accessor(cppwinrt::meta::method const& method);

    static char const* get_natvis_property_field(CorElementType category);

    static std::vector<std::experimental::filesystem::path> get_winmd_files(std::vector<std::wstring> const& winmd_specs);

    static void add_winmd_spec(std::vector<std::wstring>& winmd_specs, bool is_ref);

    static bool is_winmd(std::experimental::filesystem::path const& filename);

    static cppwinrt::generator<std::experimental::filesystem::path> enum_winmd_files(std::vector<std::wstring> const& winmd_specs);
};