%
namespace winrt::impl
{
    namespace
    {
        std::atomic<uint32_t> s_module_lock{};
    }

    module_lock::module_lock()
    {
        ++s_module_lock;
    }

    module_lock::~module_lock()
    {
        --s_module_lock;
    }
}

using namespace winrt;

HRESULT __stdcall WINRT_CanUnloadNow()
{
    if (impl::s_module_lock)
    {
        return S_FALSE;
    }

    clear_factory_cache();
    return S_OK;
}

HRESULT __stdcall WINRT_GetActivationFactory(HSTRING classId, void** factory)
{
    try
    {
        *factory = nullptr;
        wchar_t const* const name = WindowsGetStringRawBuffer(classId, nullptr);
%
        return hresult_class_not_available().to_abi();
    }
    catch (...)
    {
        return to_hresult();
    }
}
