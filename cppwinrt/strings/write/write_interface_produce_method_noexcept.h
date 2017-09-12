
    HRESULT __stdcall %(%) noexcept override
    {
        typename D::abi_guard guard(this->shim());%
        %;%
        return S_OK;
    }
