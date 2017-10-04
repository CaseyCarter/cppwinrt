
template <typename D, typename T, typename ... I>
struct WINRT_EBO %T : impl::module_lock, implements<D, Windows::Foundation::IActivationFactory%, I ...>
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%};
