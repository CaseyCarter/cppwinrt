
template <typename L> %::%(L handler) :
    %(impl::make_delegate<%>(std::forward<L>(handler)))
{}

template <typename F> %::%(F* handler) :
    %([=](auto&& ... args) { handler(args ...); })
{}

template <typename O, typename M> %::%(O* object, M method) :
    %([=](auto&& ... args) { ((*object).*(method))(args ...); })
{}

inline % %::operator()(%) const
{%
    check_hresult((*(abi_t<%>**)this)->Invoke(%));%
}
