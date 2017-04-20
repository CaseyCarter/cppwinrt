
using namespace winrt;
using namespace Windows::Foundation;

HRESULT __stdcall DllCanUnloadNow()
{
    return S_OK;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING, ::IUnknown** factory)
{
    *factory = nullptr;
    return hresult_class_not_available().to_abi();
}
