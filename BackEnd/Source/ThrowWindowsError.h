#pragma once

namespace Modern {

struct Exception
{
	HRESULT Result;

	explicit Exception(HRESULT const value) : Result(value)
	{}

	template <unsigned Count>
	Exception(HRESULT const value, wchar_t const (&message)[Count]) : Result(value)
	{
		RoOriginateErrorW(value, Count - 1, message);
	}
};

inline void check(HRESULT const result)
{
	if (S_OK == result)
	{
		return;
	}

	if (E_OUTOFMEMORY == result)
	{
		throw std::bad_alloc();
	}

	throw Exception(result);
}

inline void ThrowWindowsError(DWORD const error = GetLastError())
{
	throw Exception(HRESULT_FROM_WIN32(error));
}

}
