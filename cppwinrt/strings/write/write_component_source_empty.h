
#ifndef WINRT_SUPPRESS_MODULE_EXPORTS

HRESULT __stdcall WINRT_CanUnloadNow()
{
    return S_OK;
}

HRESULT __stdcall WINRT_GetActivationFactory(HSTRING, void** factory)
{
    *factory = nullptr;
    return winrt::hresult_class_not_available().to_abi();
}

#endif
