#pragma once

// VS 2017.3 Preview has a generator bug that causes premature destruction of the coroutine frame 
// in release (optimized) builds.  Work around by disabling optimizations for now.
#pragma message("WARNING: Build is unoptimized, to work around generator bug in VS 2017.3 Preview")
#pragma optimize("", off)

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
