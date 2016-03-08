
template <typename T> struct impl_% : impl::implements<%>, T
{
	impl_%(T handler) : T(handler) {}

	virtual HRESULT __stdcall abi_Invoke(%) noexcept override
	{
		try { (*this)(%); return S_OK; }
		catch (...) { return impl::to_hresult(); }
	}
};
