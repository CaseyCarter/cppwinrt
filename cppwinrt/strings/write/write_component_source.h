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
    return impl::s_module_lock ? S_FALSE : S_OK;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING classId, ::IUnknown** factory)
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
