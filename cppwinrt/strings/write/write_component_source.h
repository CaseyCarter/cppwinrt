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

HRESULT __stdcall DllCanUnloadNow()
{
    if (impl::s_module_lock)
    {
        return S_FALSE;
    }

    clear_factory_cache();
    return S_OK;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING classId, void** factory)
{
    try
    {
        wchar_t const* const name = WindowsGetStringRawBuffer(classId, nullptr);
%
        *factory = nullptr;
        return hresult_class_not_available().to_abi();
    }
    catch (...)
    {
        *factory = nullptr;
        return impl::to_hresult();
    }
}
