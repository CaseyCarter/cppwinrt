
template <typename T>
struct impl_produce_% : abi<%>
{
    using % = winrt::%::%;

    operator %() const noexcept
    {
        return impl::winrt_cast<%>(this);
    }
%%};
