
template <typename D, typename ... R>
struct overrides : implements<D, R ...>
{
    template <typename Qi>
    Qi as() const
    {
        return m_inner.as<Qi>();
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept
    {
        HRESULT result = implements<D, R ...>::QueryInterface(id, object);

        if (result == E_NOINTERFACE)
        {
            result = get_abi(m_inner)->QueryInterface(id, object);
        }

        return result;
    }

protected:

    Windows::IInspectable m_inner;
};
