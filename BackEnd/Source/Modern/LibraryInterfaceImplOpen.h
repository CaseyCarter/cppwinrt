
template <typename T>
class impl_%
{
	auto shim() const { return impl::shim<T, %>(this); }

public:

