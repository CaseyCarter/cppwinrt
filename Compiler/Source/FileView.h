#pragma once

#include "handle.h"
#include <string>

namespace Modern {

struct NullHandleTraits : HandleTraits<HANDLE>
{
	static void Close(Type value) noexcept
	{
		MODERN_VERIFY(CloseHandle(value));
	}
};

struct InvalidHandleTraits : HandleTraits<HANDLE>
{
	static void Close(Type value) noexcept
	{
		MODERN_VERIFY(CloseHandle(value));
	}
};

class FileView
{
	char const * m_begin = nullptr;
	char const * m_end = nullptr;

	void Open(Handle<InvalidHandleTraits> const & file) noexcept
	{
		if (!file)
		{
			return;
		}

		Handle<NullHandleTraits> map(CreateFileMapping(get(file),
													   nullptr, // default security
													   PAGE_READONLY,
													   0, 0, // entire file
													   nullptr)); // unnamed

		if (!map)
		{
			return;
		}

		LARGE_INTEGER size = {};

		if (!GetFileSizeEx(get(file), &size))
		{
			return;
		}

		m_begin = static_cast<char *>(MapViewOfFile(get(map),
													FILE_MAP_READ,
													0, 0, // offset
													0)); // entire file

		if (!m_begin)
		{
			return;
		}

		m_end = m_begin + size.QuadPart;
	}

	template <typename F, typename C>
	void Open(F function, C const * filename) noexcept
	{
		Handle<InvalidHandleTraits> file(function(filename,
												  GENERIC_READ,
												  FILE_SHARE_READ,
												  nullptr, // default security
												  OPEN_EXISTING,
												  FILE_ATTRIBUTE_NORMAL,
												  nullptr)); // no template

		Open(file);
	}

public:

	FileView(FileView const &) = delete;
	auto operator=(FileView const &)->FileView & = delete;
	bool operator==(FileView const &) = delete;
	bool operator!=(FileView const &) = delete;

	FileView() noexcept = default;
	FileView(FileView && other) noexcept = default;
	FileView & operator=(FileView && other) noexcept = default;

	~FileView() noexcept
	{
		if (m_begin)
		{
			MODERN_VERIFY(UnmapViewOfFile(m_begin));
		}
	}

	explicit FileView(wchar_t const * filename) noexcept
	{
		Open(CreateFileW, filename);
	}

	explicit FileView(char const * filename) noexcept
	{
		Open(CreateFileA, filename);
	}

	explicit FileView(std::wstring const & filename) noexcept :
		FileView(filename.c_str())
	{}

	explicit FileView(std::string const & filename) noexcept :
		FileView(filename.c_str())
	{}

		explicit operator bool() const noexcept
	{
		return m_begin != nullptr;
	}

	char const * Begin() const noexcept
	{
		return m_begin;
	}

	char const * End() const noexcept
	{
		return m_end;
	}

	size_t Size() const noexcept
	{
		return m_end - m_begin;
	}
};

inline char const * begin(FileView const & file) noexcept
{
	return file.Begin();
}

inline char const * end(FileView const & file) noexcept
{
	return file.End();
}

}
