
template <typename D>
class WINRT_EBO impl_%
{
    auto shim() const { return impl::shim<D, %>(this); }

public:

%};
