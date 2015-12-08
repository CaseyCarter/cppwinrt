
    Windows::IInspectable ActivateInstance()
    {
        return make<%>();
    }

    virtual HRESULT __stdcall abi_ActivateInstance(::IInspectable ** instance) noexcept override
    {
        return call([&] { *instance = detach(static_cast<T *>(this)->ActivateInstance()); });
    }
