
    virtual HRESULT __stdcall %(%) noexcept override
    {
        return call([&]
        {
            %static_cast<T *>(this)->%(%);
        });
    }
