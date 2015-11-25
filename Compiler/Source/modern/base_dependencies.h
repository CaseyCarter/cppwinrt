
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef GetCurrentTime
#pragma comment(lib, "runtimeobject")

#include <inspectable.h>
#include <eventtoken.h>
#include <winstring.h>
#include <set>
#include <memory>
#include <vector>
#include <utility>

extern "C"
{
	enum RO_INIT_TYPE;

	BOOL __stdcall RoOriginateErrorW(HRESULT error, unsigned length, wchar_t const * message);
	HRESULT __stdcall RoInitialize(RO_INIT_TYPE type);
	HRESULT __stdcall RoGetActivationFactory(HSTRING classId, GUID const & iid, void ** factory);
	HRESULT __stdcall RoActivateInstance(HSTRING classId, ::IInspectable ** instance);
}
