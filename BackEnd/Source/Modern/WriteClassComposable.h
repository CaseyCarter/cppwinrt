
template <typename T, typename ... Interfaces> struct %T :
    overrides<T, %, Interfaces ...>,
    requires<T, %>
{
    using composable = %;

protected:
%};
