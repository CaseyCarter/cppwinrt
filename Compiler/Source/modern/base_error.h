
#ifdef _DEBUG

#include <crtdbg.h>

#define WINRT_ASSERT _ASSERTE
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(char const * const message, Args ... args) noexcept
{
	char buffer[1024] = {};
	sprintf_s(buffer, message, args ...);
	OutputDebugStringA(buffer);
}

#else

#define WINRT_ASSERT __noop
#define WINRT_VERIFY(expression) (expression)
#define WINRT_VERIFY_(result, expression) (expression)
#define WINRT_TRACE __noop

#endif

namespace winrt {

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

	if (E_BOUNDS == result)
	{
		throw std::out_of_range("");
	}

	throw Exception(result);
}

template <typename T>
HRESULT call(T inner) noexcept
{
	try
	{
		inner();
	}
	catch (Exception const & e)
	{
		return e.Result;
	}
	catch (std::bad_alloc const &)
	{
		return E_OUTOFMEMORY;
	}
	catch (std::out_of_range const &)
	{
		return E_BOUNDS;
	}
	catch (std::exception const &)
	{
		return E_FAIL;
	}

	return S_OK;
}

}