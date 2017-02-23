
template<>
struct std::hash<winrt::%::%>
{
    size_t operator()(const winrt::%::% & value) const noexcept
    {
        return winrt::impl::hash_unknown(value);
    }
};
