
template <typename H> struct impl_% : implements<impl_%<H>, abi<%>>, H
{
    impl_%(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(%) noexcept override
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
};
