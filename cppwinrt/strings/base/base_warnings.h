
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
