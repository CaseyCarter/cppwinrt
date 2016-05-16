
template <typename T, typename ... R>
struct overrides : implements<T, R ...>
{
    template <typename Qi>
    Qi as() const
    {
        return m_inner.as<Qi>();
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
    {
        *object = query_interface(id);

        if (*object == nullptr)
        {
            return m_inner->QueryInterface(id, object);
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }

protected:

    Windows::IInspectable m_inner;
};
