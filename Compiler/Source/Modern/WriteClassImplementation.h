
template <> struct Traits<%::%>
{
	using Abi = ABI::%::%;
	using Default = %;
	static constexpr wchar_t const * Name() noexcept { return L"%"; }
	static constexpr unsigned NameLength = %;
};
