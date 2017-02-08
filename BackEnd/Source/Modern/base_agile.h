
#ifndef WINRT_NO_AGILE_REFERENCE

template <typename T>
struct agile_ref
{
    agile_ref(std::nullptr_t = nullptr) noexcept {}

    agile_ref(const T & object)
    {
#ifdef WINRT_DEBUG
        if (object.template try_as<IAgileObject>())
        {
            WINRT_TRACE("winrt::agile_ref - wrapping an agile object is unnecessary.\n");
        }
#endif

        check_hresult(RoGetAgileReference(AGILEREFERENCE_DEFAULT,
                                          __uuidof(impl::abi_default_interface<T>),
                                          winrt::get_abi(object),
                                          put_abi(m_ref)));
    }

    T get() const
    {
        T result = nullptr;
        check_hresult(m_ref->Resolve(put_abi(result)));
        return result;
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_ref);
    }

private:

    com_ptr<IAgileReference> m_ref;
};

template <typename T>
agile_ref<T> make_agile(const T & object)
{
    return object;
}

#endif
