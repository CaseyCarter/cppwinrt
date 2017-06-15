
    HRESULT __stdcall %(%) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());%
            %;%
            return S_OK;
        }
        catch (...)
        {%
            return impl::to_hresult();
        }
    }
