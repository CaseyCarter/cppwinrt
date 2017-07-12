
template <typename D, typename ... I>
struct %Base : %implements<D%, I ...>%
{
    using class_type = @;

    operator class_type() const noexcept
    {
        class_type result{ nullptr };
        attach_abi(result, detach_abi(static_cast<D::first_interface>(*this)));
        return result;
    }

    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%%};
