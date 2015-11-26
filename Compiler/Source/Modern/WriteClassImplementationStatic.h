
template <> struct traits<%::%>
{
	static constexpr wchar_t const * name() noexcept { return L"%"; }
	static constexpr unsigned name_length = %;
};
