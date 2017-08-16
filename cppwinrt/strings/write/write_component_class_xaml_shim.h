
#pragma warning(suppress: 4067)
#if defined(WINRT_FORCE_INCLUDE_%_XAML_G_H) || __has_include("%.xaml.g.h")

#include "%.xaml.g.h"

#else

namespace winrt::@::implementation
{
    template <typename D, typename ... I>
    using %T = %_base<D, I ...>;
}

#endif
