
	Windows::IInspectable ActivateInstance()
	{
		return make<%>();
	}

	virtual HRESULT __stdcall abi_ActivateInstance(::IInspectable ** instance) noexcept override
	{
		try
		{
			*instance = detach(static_cast<T *>(this)->ActivateInstance());
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
