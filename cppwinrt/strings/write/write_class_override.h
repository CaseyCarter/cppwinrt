
template <typename D, typename... Interfaces>
struct %T :
    implements<D@, composing, Interfaces...>,
    impl::require<D@>%
{
    using composable = %;

protected:
%};
