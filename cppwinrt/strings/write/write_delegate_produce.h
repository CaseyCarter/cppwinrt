
template <> struct delegate<%>
{
    template <typename H>
    struct type : implements_delegate<%, H>
    {
        type(H&& handler) : implements_delegate<%, H>(std::forward<H>(handler)) {}

        HRESULT __stdcall Invoke(%) noexcept final
        {
            try
            {
                %;
                return S_OK;
            }
            catch (...)
            {%
                return to_hresult();
            }
        }
    };
};
