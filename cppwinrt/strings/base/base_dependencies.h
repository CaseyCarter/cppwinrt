
#include <restrictederrorinfo.h>
#include <winstring.h>
#include <ctxtcall.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <clocale>
#include <cstddef>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <optional>
#include <shared_mutex>
#include <string>
#include <string_view>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <vector>
#include <experimental/coroutine>

extern "C"
{
    HRESULT __stdcall WINRT_GetRestrictedErrorInfo(IRestrictedErrorInfo** info);
    HRESULT __stdcall WINRT_RoGetActivationFactory(HSTRING classId, GUID const& iid, void** factory);
    HRESULT __stdcall WINRT_RoInitialize(uint32_t type);
    BOOL    __stdcall WINRT_RoOriginateLanguageException(HRESULT error, HSTRING message, IUnknown* exception);
    void    __stdcall WINRT_RoUninitialize();
    HRESULT __stdcall WINRT_SetRestrictedErrorInfo(IRestrictedErrorInfo* info);
    HRESULT __stdcall WINRT_RoGetAgileReference(uint32_t options, GUID const& iid, void* object, void** reference);
}

#ifdef _M_IX86
#pragma comment(linker, "/alternatename:_WINRT_GetRestrictedErrorInfo@4=_GetRestrictedErrorInfo@4")
#pragma comment(linker, "/alternatename:_WINRT_RoGetActivationFactory@12=_RoGetActivationFactory@12")
#pragma comment(linker, "/alternatename:_WINRT_RoInitialize@4=_RoInitialize@4")
#pragma comment(linker, "/alternatename:_WINRT_RoOriginateLanguageException@12=_RoOriginateLanguageException@12")
#pragma comment(linker, "/alternatename:_WINRT_RoUninitialize@0=_RoUninitialize@0")
#pragma comment(linker, "/alternatename:_WINRT_SetRestrictedErrorInfo@4=_SetRestrictedErrorInfo@4")
#pragma comment(linker, "/alternatename:_WINRT_RoGetAgileReference@16=_RoGetAgileReference@16")
#else
#pragma comment(linker, "/alternatename:WINRT_GetRestrictedErrorInfo=GetRestrictedErrorInfo")
#pragma comment(linker, "/alternatename:WINRT_RoGetActivationFactory=RoGetActivationFactory")
#pragma comment(linker, "/alternatename:WINRT_RoInitialize=RoInitialize")
#pragma comment(linker, "/alternatename:WINRT_RoOriginateLanguageException=RoOriginateLanguageException")
#pragma comment(linker, "/alternatename:WINRT_RoUninitialize=RoUninitialize")
#pragma comment(linker, "/alternatename:WINRT_SetRestrictedErrorInfo=SetRestrictedErrorInfo")
#pragma comment(linker, "/alternatename:WINRT_RoGetAgileReference=RoGetAgileReference")
#endif
