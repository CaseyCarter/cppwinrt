
template <typename T>
class WINRT_EBO impl_consume_%
{
    auto shim() const { return impl::shim<T, %>(this); }

public:

%};

template <typename T> struct impl_produce_%;
