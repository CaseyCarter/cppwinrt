
template <> struct traits<%::%>
{
    using abi = ABI::%::%;
    template <typename D> using consume = %::impl_%<D>;
};
