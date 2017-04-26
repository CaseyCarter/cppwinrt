
template <typename D, typename T, typename ... I>
struct %FactoryT : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory%, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%};
