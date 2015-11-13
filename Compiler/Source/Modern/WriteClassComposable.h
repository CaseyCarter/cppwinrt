
template <typename T> struct %T :
	Overrides<%>,
	Requires<T, %>
{
	using Composable = %;

protected:
%};
