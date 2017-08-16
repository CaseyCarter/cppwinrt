
// WINRT_version is used by Microsoft to analyze C++/WinRT library adoption and inform future product decisions.
extern "C"
__declspec(selectany)
char const * const WINRT_version = "C++/WinRT version:%";

#ifdef _M_IX86
#pragma comment(linker, "/include:_WINRT_version")
#else
#pragma comment(linker, "/include:WINRT_version")
#endif
