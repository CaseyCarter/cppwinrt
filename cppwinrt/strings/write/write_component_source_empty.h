
using namespace winrt;

HRESULT __stdcall DllCanUnloadNow()
{
    return S_OK;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING, void** factory)
{
    *factory = nullptr;
    return hresult_class_not_available().to_abi();
}
