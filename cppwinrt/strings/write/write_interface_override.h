
template <typename D>
class %T
{
    D& shim() noexcept { return *static_cast<D*>(this); }
    const D& shim() const noexcept { return *static_cast<const D*>(this); }
public:
    using % = winrt::%;
%};