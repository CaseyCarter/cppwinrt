
#ifndef WINRT_SUPPRESS_MODULE_EXPORTS

using namespace winrt;

HRESULT __stdcall WINRT_CanUnloadNow()
{
    return S_OK;
}

HRESULT __stdcall WINRT_GetActivationFactory(HSTRING, void** factory)
{
    *factory = nullptr;
    return hresult_class_not_available().to_abi();
}

#endif
