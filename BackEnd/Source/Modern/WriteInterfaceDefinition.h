
struct % :
    Windows::IInspectable,
    impl::consume<%>%
{
    %(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<%>(m_ptr); }
%};
