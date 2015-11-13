#pragma once

#include <shlwapi.h>
#include <shlobj.h>
#include <string>
#include <Modern\Handle.h>
#include "ThrowWindowsError.h"

#pragma comment(lib, "shlwapi")

namespace Modern { namespace Path { namespace Internal {

inline void Trim(std::string & path)
{
	path.resize(strlen(path.c_str()));
}

inline void Append(std::string & path, char const * more, size_t size)
{
    if (!path.empty() && path.back() != '\\')
    {
        path.append(1, '\\');
    }

    while (size)
    {
        if (*more != '\\')
        {
            break;
        }

        ++more;
        --size;
    }

    path.append(more, size);
}

inline bool CreateDirectory(std::string const & path)
{
    if (!::CreateDirectoryA(path.c_str(), nullptr))
    {
        DWORD const result = GetLastError();

        if (ERROR_ALREADY_EXISTS != result)
        {
            ThrowWindowsError(result);
        }
        else
        {
            return false;
        }
    }

    return true;
}

struct TaskMemTraits : HandleTraits<wchar_t *>
{
    static void Close(Type value) noexcept
    {
        CoTaskMemFree(value);
    }
};

struct FindFileTraits : HandleTraits<HANDLE>
{
	inline static void Close(Type value) noexcept
	{
		MODERN_VERIFY(FindClose(value));
	}
};

using FindFile = Handle<FindFileTraits>;

}}}

namespace Modern { namespace Path {

inline std::string ToRelative(std::string const & from, bool const fromFolder, std::string const & to, bool const toFolder)
{
    std::string result(MAX_PATH, ' ');

    MODERN_VERIFY(PathRelativePathToA(&result[0],
                  from.c_str(), 
                  fromFolder ? FILE_ATTRIBUTE_DIRECTORY : 0,
                  to.c_str(),
                  toFolder ? FILE_ATTRIBUTE_DIRECTORY : 0));

    Internal::Trim(result);
    return result;
}

inline bool IsRelative(char const * path) noexcept
{
	return 0 != PathIsRelativeA(path);
}

inline bool IsRelative(std::string const & path) noexcept
{
	return IsRelative(path.c_str());
}

inline bool Exists(char const * filename)
{
    return INVALID_FILE_ATTRIBUTES != GetFileAttributesA(filename);
}

inline bool Exists(std::string const & filename)
{
    return Exists(filename.c_str());
}

template <unsigned Count>
inline std::string Combine(std::string path, char const (&more)[Count])
{
    Internal::Append(path, more, Count - 1);
    return path;
}

template <unsigned Count>
inline void Append(std::string & path, char const (&more)[Count])
{
    Internal::Append(path, more, Count - 1);
}

inline void Append(std::string & path, std::string const & more)
{
    Internal::Append(path, more.c_str(), more.size());
}

inline void CombineIntoSecond(std::string first, std::string & second)
{
    Append(first, second);
    second = std::move(first);
}

inline void RemoveFilename(std::string & path)
{
    MODERN_ASSERT(!path.empty());

    if (PathRemoveFileSpecA(&path[0]))
    {
        Internal::Trim(path);
    }
}

inline void RenameExtension(std::string & path, char const * const extension)
{
    MODERN_ASSERT(!path.empty());
    path.resize(MAX_PATH);

    MODERN_VERIFY(PathRenameExtensionA(&path[0], extension));
    Internal::Trim(path);
}

inline char const * FindExtension(char const * path) noexcept
{
	return PathFindExtensionA(path);
}

inline char const * FindExtension(std::string const & path)
{
	return PathFindExtensionA(path.c_str());
}

inline std::string GetCurrentDirectory()
{
	unsigned const size = GetCurrentDirectoryA(0, nullptr);
	if (0 == size) ThrowWindowsError();
	std::string result(size - 1, ' ');

	if (size - 1 != ::GetCurrentDirectoryA(size, &result[0]))
	{
		ThrowWindowsError();
	}

	return result;
}

inline void SetCurrentDirectory(char const * path)
{
    if (!::SetCurrentDirectoryA(path))
    {
        ThrowWindowsError();
    }
}

inline void SetCurrentDirectory(std::string const & path)
{
    Path::SetCurrentDirectory(path.c_str());
}

inline bool CreateDirectory(std::string path)
{
    for (auto i = path.find('\\');
         i != std::string::npos;
         i = path.find('\\', i + 1))
    {
        // \\?\C:\path

        if (i == 0) continue;
        if (path[i - 1] == '\\') continue;
        if (path[i - 1] == '?') continue;
        if (path[i - 1] == ':') continue;

        path[i] = 0;
        Internal::CreateDirectory(path);
        path[i] = '\\';
    }

    return Internal::CreateDirectory(path);
}

inline std::string GetKnownFolder(GUID const & id)
{
    Handle<Internal::TaskMemTraits> buffer;
    check(SHGetKnownFolderPath(id, 0, nullptr, put(buffer)));

    std::string result(MAX_PATH, ' ');
    result.resize(snprintf(&result[0], MAX_PATH, "%ls", get(buffer)));
    return result;
}

template <typename Callback>
void FindFiles(char const * query, Callback callback)
{
	std::string buffer;

	if (IsRelative(query))
	{
		buffer = GetCurrentDirectory();
		Append(buffer, query);
		query = buffer.c_str();
	}

	WIN32_FIND_DATAA data {};
	Internal::FindFile ff(FindFirstFileA(query, &data));

	if (ff)
	{
		do
		{
			if (FILE_ATTRIBUTE_DIRECTORY == (FILE_ATTRIBUTE_DIRECTORY & data.dwFileAttributes))
			{
				continue;
			}

			callback(data.cFileName);
		}
		while (FindNextFileA(get(ff), &data));
	}
}

template <typename Callback>
void FindFiles(std::string const & query, Callback callback)
{
    FindFiles(query.c_str(), callback);
}

template <typename Callback>
void FindFolders(char const * query, Callback callback)
{
    std::string buffer;

    if (IsRelative(query))
    {
        buffer = GetCurrentDirectory();
        Append(buffer, query);
        query = buffer.c_str();
    }

    WIN32_FIND_DATAA data{};
    Internal::FindFile ff(FindFirstFileA(query, &data));

    if (ff)
    {
        do
        {
            if (0 == strcmp(data.cFileName, ".") || 0 == strcmp(data.cFileName, ".."))
            {
                continue;
            }

            callback(data.cFileName);
        }
        while (FindNextFileA(get(ff), &data));
    }
}

template <typename Callback>
void FindFolders(std::string const & query, Callback callback)
{
    FindFolders(query.c_str(), callback);
}

}}
