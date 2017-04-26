
struct %% : Windows::Foundation::IUnknown
{
    %(std::nullptr_t = nullptr) noexcept {}
    template <typename L> %(L lambda);
    template <typename F> %(F* function);
    template <typename O, typename M> %(O* object, M method);
    % operator()(%) const;
};
