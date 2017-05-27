
namespace impl
{
    template <typename D>
    struct composable_factory
    {
        template <typename I>
        static I CreateInstance(const Windows::Foundation::IInspectable& outer, Windows::Foundation::IInspectable& inner)
        {
            static_assert(std::is_base_of_v<Windows::Foundation::IInspectable, I>, "Requested interface must derive from winrt::Windows::Foundation::IInspectable");
            Windows::Foundation::IInspectable local_inner = CreateInstanceImpl(outer);
            I instance = local_inner.as<I>();

            if (&inner)
            {
                inner = std::move(local_inner);
            }

            return instance;
        }

    private:
        static Windows::Foundation::IInspectable CreateInstanceImpl(const Windows::Foundation::IInspectable& outer)
        {
            // Very specific dance here. The return value must have a ref on the outer, while inner must have a ref count of 1.
            // Be sure not to make a delegating QueryInterface call because the controlling outer is not fully constructed yet.
            com_ptr<D> instance = make_self<D>();
            instance->m_outer = static_cast<::IInspectable*>(get_abi(outer));
            Windows::Foundation::IInspectable inner;
            attach_abi(inner, to_abi<INonDelegatingInspectable>(detach_abi(instance)));
            return inner;
        }
    };

    template <typename T, typename D, typename I>
    class WINRT_EBO produce_dispatch_to_super_base
    {
    protected:
        D& shim() noexcept
        {
            return static_cast<T&>(*this).instance;
        }

        I shim_super()
        {
            I result;
            if (shim().outer())
            {
                check_hresult(shim().QueryInterface(impl::guid_v<I>, reinterpret_cast<void**>(put_abi(result))));
            }
            return result;
        }
    };

    template <typename T, typename D, typename I>
    struct produce_dispatch_to_super;

    template <typename D, typename ... I>
    class dispatch_to_super
    {
        class wrapper : public produce_dispatch_to_super<wrapper, D, I> ...
        {
            D& instance;

            template <typename T, typename D, typename I>
            friend class produce_dispatch_to_super_base;

            template <typename D, typename ... I>
            friend class dispatch_to_super;

            explicit wrapper(D& d) : instance(d) {}
            wrapper(const wrapper&) = delete;
        public:
            wrapper(wrapper&&) = default;
        };

    public:
        static wrapper super(D& instance) noexcept
        {
            return wrapper{ instance };
        }
    };
}
