
template <> struct Traits<%::%>
{
	using Abi = ABI::%::%;
	template <typename T> using Methods = %::impl_%<T>;
};
