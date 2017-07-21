#pragma once

#if _MSC_FULL_VER <= 191125505
// VS 2017.3 Preview 3 and Preview 4 have a generator bug that causes premature destruction of the coroutine frame 
// in release (optimized) builds.  Work around by disabling optimizations for now.
#pragma message("WARNING: Build is unoptimized, to work around generator bug in VS 2017.3 Preview 3 and Preview 4")
#pragma optimize("", off)
#endif

#include <cor.h>
#include <corerror.h>
#include <corhdr.h>

#include "base.h"
#include <functional>
#include <rometadataapi.h>
#include <rometadata.h>
#include <filesystem>
#include <optional>
#include <set>

#include "generator.h"
