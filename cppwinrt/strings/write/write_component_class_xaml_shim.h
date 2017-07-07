
#pragma warning(suppress: 4067)
#if defined(WINRT_FORCE_INCLUDE_%_X_H) || __has_include("%.x.h")

#include "%.x.h"

#else

template <typename D, typename ... I>
using %T = %Base<D, I ...>;

template <typename D, typename T, typename ... I>
using %FactoryT = %FactoryBase<D, T, I ...>;

#endif
