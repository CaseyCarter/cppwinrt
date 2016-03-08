
template <> struct traits<%::%>
{
	using abi = ABI::%::%;
	template <typename T> using methods = %::impl_%<T>;
};
