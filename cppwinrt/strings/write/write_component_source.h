#include "module.g.h"

#ifndef WINRT_SUPPRESS_MODULE_EXPORTS

%
using namespace winrt;

HRESULT __stdcall WINRT_CanUnloadNow()
{
#ifdef _WRL_MODULE_H_
    if (!::Microsoft::WRL::Module<::Microsoft::WRL::InProc>::GetModule().Terminate())
    {
        return S_FALSE;
    }
#endif

    if (get_module_lock())
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
#ifdef _WRL_MODULE_H_
        return ::Microsoft::WRL::Module<::Microsoft::WRL::InProc>::GetModule().GetActivationFactory(classId, reinterpret_cast<::IActivationFactory**>(factory));
#else
        return hresult_class_not_available().to_abi();
#endif
    }
    catch (...)
    {
        return to_hresult();
    }
}

#endif
