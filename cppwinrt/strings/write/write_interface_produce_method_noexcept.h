
    HRESULT __stdcall %(%) noexcept final
    {
        typename D::abi_guard guard(this->shim());%
        %;%
        return S_OK;
    }
