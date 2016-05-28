
#ifndef WINRT_NO_DEFAULT_LIB 
#pragma comment(lib, "windowsapp") 
#endif

#include <ctxtcall.h>
#include <restrictederrorinfo.h>
#include <winstring.h>

#include <atomic>
#include <chrono>
#include <functional>
#include <vector>

extern "C"
{
    HRESULT __stdcall WINRT_GetRestrictedErrorInfo(IRestrictedErrorInfo ** info);
    HRESULT __stdcall WINRT_RoActivateInstance(HSTRING classId, void ** instance);
    HRESULT __stdcall WINRT_RoGetActivationFactory(HSTRING classId, const GUID & iid, void ** factory);
    HRESULT __stdcall WINRT_RoInitialize(uint32_t type);
    BOOL    __stdcall WINRT_RoOriginateError(HRESULT error, HSTRING message);
    void    __stdcall WINRT_RoUninitialize();
    HRESULT __stdcall WINRT_SetRestrictedErrorInfo(IRestrictedErrorInfo * info);
}

#ifdef _M_IX86
#pragma comment(linker, "/alternatename:_WINRT_GetRestrictedErrorInfo@4=_GetRestrictedErrorInfo@4")
#pragma comment(linker, "/alternatename:_WINRT_RoActivateInstance@8=_RoActivateInstance@8")
#pragma comment(linker, "/alternatename:_WINRT_RoGetActivationFactory@12=_RoGetActivationFactory@12")
#pragma comment(linker, "/alternatename:_WINRT_RoInitialize@4=_RoInitialize@4")
#pragma comment(linker, "/alternatename:_WINRT_RoOriginateError@8=_RoOriginateError@8")
#pragma comment(linker, "/alternatename:_WINRT_RoUninitialize@0=_RoUninitialize@0")
#pragma comment(linker, "/alternatename:_WINRT_SetRestrictedErrorInfo@4=_SetRestrictedErrorInfo@4")
#else
#pragma comment(linker, "/alternatename:WINRT_GetRestrictedErrorInfo=GetRestrictedErrorInfo")
#pragma comment(linker, "/alternatename:WINRT_RoActivateInstance=RoActivateInstance")
#pragma comment(linker, "/alternatename:WINRT_RoGetActivationFactory=RoGetActivationFactory")
#pragma comment(linker, "/alternatename:WINRT_RoInitialize=RoInitialize")
#pragma comment(linker, "/alternatename:WINRT_RoOriginateError=RoOriginateError")
#pragma comment(linker, "/alternatename:WINRT_RoUninitialize=RoUninitialize")
#pragma comment(linker, "/alternatename:WINRT_SetRestrictedErrorInfo=SetRestrictedErrorInfo")
#endif

#define _WINDOWS_NUMERICS_NAMESPACE_ winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_BEGIN_NAMESPACE_ namespace winrt { namespace Windows { namespace Foundation { namespace Numerics
#define _WINDOWS_NUMERICS_END_NAMESPACE_ }}}

#ifdef __clang__
#define _XM_NO_INTRINSICS_
#endif

#include "WindowsNumerics.impl.h"

#ifdef __clang__
#undef _XM_NO_INTRINSICS_
#endif

#undef _WINDOWS_NUMERICS_NAMESPACE_
#undef _WINDOWS_NUMERICS_BEGIN_NAMESPACE_
#undef _WINDOWS_NUMERICS_END_NAMESPACE_
