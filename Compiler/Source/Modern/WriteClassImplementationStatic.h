
template <> struct Traits<%::%>
{
	static constexpr wchar_t const * Name() noexcept { return L"%"; }
	static constexpr unsigned NameLength = %;
};
