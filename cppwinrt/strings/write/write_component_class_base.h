
template <typename D, typename ... I>
struct %T
    : %implements<D%, I ...>%
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%%};
