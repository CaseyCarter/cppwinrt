
	virtual HRESULT __stdcall %(%) noexcept override
	{
		try { %static_cast<T *>(this)->%(%); return S_OK; }
		catch (...) { return impl::to_hresult(); }
	}
