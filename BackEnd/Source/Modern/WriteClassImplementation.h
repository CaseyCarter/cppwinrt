
template <> struct traits<%::%>
{
    using abi = ABI::%::%;
    static constexpr const wchar_t * name() noexcept { return L"%"; }
};
