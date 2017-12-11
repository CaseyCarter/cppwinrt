
template <typename D, typename T, typename... I>
struct WINRT_EBO %T : implements<D, Windows::Foundation::IActivationFactory%, I...>
{
    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%};
