
template <typename D, typename ... Interfaces> struct %T :
    overrides<D, %, Interfaces ...>,
    impl::require<D, %>
{
    using composable = %;

protected:
%};
