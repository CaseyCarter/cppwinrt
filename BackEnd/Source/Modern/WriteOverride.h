
template <typename D, typename A = ABI::%::%>
class %T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using % = winrt::%::%;
%%};
