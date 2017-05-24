
template <typename D>
class %T
{
    D& shim() noexcept { return *static_cast<D*>(this); }
    D const& shim() const noexcept { return *static_cast<const D*>(this); }

public:

    using % = winrt::@;

%};
