
#pragma comment(lib, "runtimeobject")
#pragma comment(lib, "ole32")

#include <inspectable.h>
#include <winstring.h>
#include <set>
#include <memory>
#include <vector>
#include <utility>
#include <type_traits>

extern "C"
{
	enum RO_INIT_TYPE;

	BOOL __stdcall RoOriginateErrorW(HRESULT error, unsigned length, wchar_t const * message);
	HRESULT __stdcall RoInitialize(RO_INIT_TYPE type);
	HRESULT __stdcall RoGetActivationFactory(HSTRING classId, GUID const & iid, void ** factory);
	HRESULT __stdcall RoActivateInstance(HSTRING classId, ::IInspectable ** instance);
}
