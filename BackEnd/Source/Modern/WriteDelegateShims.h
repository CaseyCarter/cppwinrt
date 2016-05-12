
template <typename H> %::%(H handler) :
    %(make<impl_%<H>, %>(handler))
{}

template <typename O, typename M> %::%(O * object, M method) :
    %(std::bind(std::mem_fn(method), object%))
{}

inline % %::operator()(%%