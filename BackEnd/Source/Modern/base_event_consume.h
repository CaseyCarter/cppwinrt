
struct event_token
{
    int64_t value;
};

inline bool operator==(const event_token & left, const event_token & right) noexcept
{
    return left.value == right.value;
}

struct auto_revoke_t {};
constexpr auto_revoke_t auto_revoke{};

template <typename I>
struct event_revoker
{
    using method_type = HRESULT(__stdcall abi<I>::*)(event_token);

    event_revoker() noexcept = default;
    event_revoker(const event_revoker &) = delete;
    event_revoker & operator=(const event_revoker &) = delete;
    event_revoker(event_revoker &&) = default;
    event_revoker & operator=(event_revoker &&) = default;

    event_revoker(const I & object, method_type method, event_token token) :
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
            ((*get_abi(object)).*(m_method))(m_token);
        }

        m_object = nullptr;
    }

private:

    weak_ref<I> m_object;
    method_type m_method{};
    event_token m_token{};
};

template <typename I>
struct factory_event_revoker
{
    using method_type = HRESULT(__stdcall abi<I>::*)(event_token);

    factory_event_revoker() noexcept = default;
    factory_event_revoker(const factory_event_revoker &) = delete;
    factory_event_revoker & operator=(const factory_event_revoker &) = delete;
    factory_event_revoker(factory_event_revoker &&) = default;
    factory_event_revoker & operator=(factory_event_revoker &&) = default;

    factory_event_revoker(const I & object, method_type method, event_token token) :
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

        ((*get_abi(m_object)).*(m_method))(m_token);
        m_object = nullptr;
    }

private:

    I m_object;
    method_type m_method{};
    event_token m_token{};
};

namespace impl
{
    template <typename D, typename I, typename S, typename M>
    auto make_event_revoker(S source, M method, event_token token)
    {
        return event_revoker<I>(static_cast<const I &>(static_cast<const D &>(*source)), method, token);
    }
}
