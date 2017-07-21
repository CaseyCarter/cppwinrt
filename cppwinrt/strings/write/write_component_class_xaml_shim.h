
#pragma warning(suppress: 4067)
#if defined(WINRT_FORCE_INCLUDE_%_X_H) || __has_include("%.x.h")

#include "%.x.h"

#else

namespace winrt::@::implementation
{
    template <typename D, typename ... I>
    using %T = %_base<D, I ...>;
}

#endif
