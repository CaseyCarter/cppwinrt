#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define NOMINMAX

#include <windows.h>
#include <vsdebugeng.h>
#include <vsdebugeng.templates.h>
#include <Dia2.h>
#include "base.h"
#include <rometadataapi.h>
#include <rometadata.h>
#include <filesystem>
#include <optional>
#include <set>
#include <variant>
#include "generator.h"
#include "winmd_reader.h"
#include "code_writer.h"
#include "sdk.h"
#include "winmd_access.h"

#ifndef IF_FAIL_RET
#define IF_FAIL_RET(expr) { HRESULT _hr = (expr); if(FAILED(_hr)) return(_hr); }
#endif

template<typename T>
winrt::com_ptr<T> make_com_ptr(T* ptr)
{
    winrt::com_ptr<T> result;
    result.copy_from(ptr);
    return result;
}