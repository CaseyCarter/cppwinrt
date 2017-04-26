
template <typename D>
struct consume_%
{
%};
template <> struct consume<%> { template <typename D> using type = consume_%<D>; };
