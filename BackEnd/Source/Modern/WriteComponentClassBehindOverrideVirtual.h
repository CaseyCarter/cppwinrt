
	virtual HRESULT __stdcall %(%) noexcept override
	{
		try
		{
			%static_cast<T *>(this)->%(%);
		}
		catch (...) { return impl::to_hresult(); }
	}
