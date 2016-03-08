
template <> struct traits<%::%>
{
	using abi = ABI::%::%;
	using default_interface = %;
	static constexpr wchar_t const * name() noexcept { return L"%"; }
	static constexpr unsigned name_length = %;
};
