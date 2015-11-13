
template <typename T> struct impl_% : ImplementsDefault<%>
{
	impl_%(T handler) : m_handler(handler) {}
	T m_handler;

	virtual HRESULT __stdcall abi_Invoke(%) noexcept override
	{
		return call([&]{ m_handler(%); });
	}
};
