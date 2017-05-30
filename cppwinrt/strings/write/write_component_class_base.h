
template <typename D, typename ... I>
struct %Base
    : %implements<D%, I ...>%
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%%};
