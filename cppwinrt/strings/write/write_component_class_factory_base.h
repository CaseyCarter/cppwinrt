
template <typename D, typename T, typename ... I>
struct %FactoryBase : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory%, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%};
