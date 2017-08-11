
WINRT_EXPORT namespace winrt
{
    struct event_token
    {
        int64_t value{};

        explicit operator bool() const noexcept
        {
            return value != 0;
        }
    };

    inline bool operator==(event_token const& left, event_token const& right) noexcept
    {
        return left.value == right.value;
    }

    struct auto_revoke_t {};
    constexpr auto_revoke_t auto_revoke{};

    template <typename I>
    struct event_revoker
    {
        using method_type = HRESULT(__stdcall abi_t<I>::*)(event_token);

        event_revoker() noexcept = default;
        event_revoker(event_revoker const&) = delete;
        event_revoker& operator=(event_revoker const&) = delete;
        event_revoker(event_revoker&&) = default;
        event_revoker& operator=(event_revoker&&) = default;

        event_revoker(I const& object, method_type method, event_token token) :
            m_object(object),
            m_method(method),
            m_token(token)
        {}

        ~event_revoker() noexcept
        {
            revoke();
        }

        void revoke() noexcept
        {
            if (!m_object)
            {
                return;
            }

            if (I object = m_object.get())
            {
                ((*reinterpret_cast<abi_t<I>**>(&object))->*(m_method))(m_token);
            }

            m_object = nullptr;
        }

        explicit operator bool() const noexcept
        {
            return m_object != nullptr;
        }

    private:

        weak_ref<I> m_object;
        method_type m_method{};
        event_token m_token{};
    };

    template <typename I>
    struct factory_event_revoker
    {
        using method_type = HRESULT(__stdcall abi_t<I>::*)(event_token);

        factory_event_revoker() noexcept = default;
        factory_event_revoker(factory_event_revoker const&) = delete;
        factory_event_revoker& operator=(factory_event_revoker const&) = delete;
        factory_event_revoker(factory_event_revoker&&) = default;
        factory_event_revoker& operator=(factory_event_revoker&&) = default;

        factory_event_revoker(I const& object, method_type method, event_token token) :
            m_object(object),
            m_method(method),
            m_token(token)
        {}

        ~factory_event_revoker() noexcept
        {
            revoke();
        }

        void revoke() noexcept
        {
            if (!m_object)
            {
                return;
            }

            ((*reinterpret_cast<abi_t<I>**>(&m_object))->*(m_method))(m_token);
            m_object = nullptr;
        }

        explicit operator bool() const noexcept
        {
            return m_object != nullptr;
        }

    private:

        I m_object;
        method_type m_method{};
        event_token m_token{};
    };
}

namespace winrt::impl
{
    template <typename D, typename I, typename S, typename M>
    auto make_event_revoker(S source, M method, event_token token)
    {
        return event_revoker<I>(static_cast<I const&>(static_cast<D const&>(*source)), method, token);
    }
}
