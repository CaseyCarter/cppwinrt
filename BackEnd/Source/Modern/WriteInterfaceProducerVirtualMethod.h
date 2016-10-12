
    HRESULT __stdcall %(%) noexcept override
    {
        try
        {
            %;
            return S_OK;
        }
        catch (...)
        {%
            return impl::to_hresult();
        }
    }
