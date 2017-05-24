
template <typename D, typename ... I>
struct %T :
    impl::module_lock,
    %<D%, I ...>%
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%};
