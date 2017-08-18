
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
