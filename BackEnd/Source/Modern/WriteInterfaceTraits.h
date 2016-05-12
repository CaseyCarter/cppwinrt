
template <> struct traits<%::%>
{
    using abi = ABI::%::%;
    template <typename T> using consume = %::impl_consume_%<T>;
    template <typename T> using produce = %::impl_produce_%<T>;
};
