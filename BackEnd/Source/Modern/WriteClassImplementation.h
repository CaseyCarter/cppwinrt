
template <> struct traits<%::%>
{
    using abi = ABI::%::%;
    using default_interface = %;
    static constexpr const wchar_t * name() noexcept { return L"%"; }
};
