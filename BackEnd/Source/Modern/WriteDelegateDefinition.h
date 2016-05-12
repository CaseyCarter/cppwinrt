
struct % : Windows::IUnknown
{
    %(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<%>(m_ptr); }
    template <typename H> %(H handler);
    template <typename O, typename M> %(O * object, M method);
    % operator()(%) const;
};
