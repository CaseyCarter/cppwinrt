
#ifndef MODERN_REMOVE_ADDREF_RELEASE
#define MODERN_REMOVE_ADDREF_RELEASE

namespace Modern { namespace Interop {

template <typename Interface>
class RemoveAddRefRelease : public Interface
{
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
};

}}

#endif
