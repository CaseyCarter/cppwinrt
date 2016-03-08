
template <typename T> struct %T :
	overrides<%>,
	requires<T, %>
{
	using composable = %;

protected:
%};
