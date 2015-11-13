
{
	%(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<%>>(m_ptr); }
