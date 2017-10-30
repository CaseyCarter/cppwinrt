
template <typename D, typename... I>
struct WINRT_EBO %_base : %implements<D%@, I...>%%%
{
    using class_type = @;
    @
    operator class_type() const noexcept
    {
        static_assert(std::is_same_v<typename D::first_interface, impl::default_interface_t<class_type>>);
        class_type result{ nullptr };
        attach_abi(result, detach_abi(static_cast<impl::default_interface_t<class_type>>(*this)));
        return result;
    }

    hstring GetRuntimeClassName() const
    {
        return L"%";
    }
%%};
