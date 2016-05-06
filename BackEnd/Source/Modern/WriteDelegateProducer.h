
template <typename T> struct impl_% : implements<impl_%<T>, abi<%>>
{
    T m_handler;
    impl_%(T handler) : m_handler(handler) {}

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
