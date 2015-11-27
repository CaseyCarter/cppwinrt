
template <typename T> struct impl_% : impl::implements<%>, T
{
	impl_%(T handler) : T(handler) {}

	virtual HRESULT __stdcall abi_Invoke(%) noexcept override
	{
		return call([&]{ (*this)(%); });
	}
};
