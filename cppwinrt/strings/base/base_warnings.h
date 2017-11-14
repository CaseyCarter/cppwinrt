
#ifndef WINRT_HAS_CXX17
#if defined(_MSVC_LANG)
#if _MSVC_LANG > 201402
#define WINRT_HAS_CXX17	1
#else
#define WINRT_HAS_CXX17	0
#endif
#else
#if __cplusplus > 201402
#define WINRT_HAS_CXX17	1
#els
#define WINRT_HAS_CXX17	0
#endif
#endif
#endif
#if !WINRT_HAS_CXX17
#error C++/WinRT requires language features only available with C++17.
#endif 
#undef WINRT_HAS_CXX17

#if defined(_MSC_FULL_VER) && _MSC_FULL_VER < 191125506
#define WINRT_STRINGIZE_(x) #x
#define WINRT_STRINGIZE(x) WINRT_STRINGIZE_(x)
#pragma message(__FILE__ "(" WINRT_STRINGIZE(__LINE__) ") : warning: Visual Studio 2017 version 15.3 or later is recommended.")
#endif

#if defined(__clang__) 
#define WINRT_WARNING_PUSH \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
_Pragma("clang diagnostic ignored \"-Wdeprecated-implementations\"")
#define WINRT_WARNING_POP \
_Pragma("clang diagnostic pop")
#else
#define WINRT_WARNING_PUSH \
__pragma(warning(push)) \
__pragma(warning(disable: 4996))
#define WINRT_WARNING_POP \
__pragma(warning(pop))
#endif
