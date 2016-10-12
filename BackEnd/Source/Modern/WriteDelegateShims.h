
template <typename L> %::%(L lambda) :
    %(impl::make_delegate<impl_%<L>, %>(std::forward<L>(lambda)))
{}

template <typename F> %::%(F * function) :
    %([=](auto && ... args) { %function(args ...); })
{}

template <typename O, typename M> %::%(O * object, M method) :
    %([=](auto && ... args) { %((*object).*(method))(args ...); })
{}

inline % %::operator()(%%