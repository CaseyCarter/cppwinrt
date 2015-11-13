#pragma once

#include <Modern\Base.h>

namespace Modern {

inline void ThrowWindowsError(DWORD const error = GetLastError())
{
	throw Exception(HRESULT_FROM_WIN32(error));
}

}
