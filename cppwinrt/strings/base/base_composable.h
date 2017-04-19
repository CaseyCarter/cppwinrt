
template <typename D, typename ... R>
struct overrides : implements<D, R ...>
{
    template <typename Qi>
    Qi as() const
    {
        return m_inner.as<Qi>();
    }

    HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept
    {
        HRESULT result = implements<D, R ...>::QueryInterface(id, object);

        if (result == E_NOINTERFACE)
        {
            result = get_abi(m_inner)->QueryInterface(id, object);
        }

        return result;
    }

protected:

    Windows::Foundation::IInspectable m_inner;
};

namespace impl
{
    struct INonDelegatingInspectable : Windows::Foundation::IUnknown
    {
        INonDelegatingInspectable(std::nullptr_t = nullptr) noexcept {}
    };

    template <> struct abi<INonDelegatingInspectable>
    {
        using type = ::IInspectable;
    };

    template <typename D>
    struct produce<D, INonDelegatingInspectable> : produce_base<D, INonDelegatingInspectable>
    {
        HRESULT __stdcall QueryInterface(const GUID& id, void** object) noexcept final
        {
            return this->shim().NonDelegatingQueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept final
        {
            return this->shim().NonDelegatingAddRef();
        }

        unsigned long __stdcall Release() noexcept final
        {
            return this->shim().NonDelegatingRelease();
        }

        HRESULT __stdcall GetIids(uint32_t* count, GUID** array) noexcept final
        {
            return this->shim().NonDelegatingGetIids(count, array);
        }

        HRESULT __stdcall GetRuntimeClassName(HSTRING* name) noexcept final
        {
            return this->shim().NonDelegatingGetRuntimeClassName(name);
        }

        HRESULT __stdcall GetTrustLevel(TrustLevel* trustLevel) noexcept final
        {
            return this->shim().NonDelegatingGetTrustLevel(trustLevel);
        }
    };

    template <typename D>
    struct composable_factory
    {
        template <typename I>
        static I CreateInstance(const Windows::Foundation::IInspectable& outer, Windows::Foundation::IInspectable& inner)
        {
            static_assert(std::is_base_of_v<Windows::Foundation::IInspectable, I>, "Requested interface must derive from winrt::Windows::Foundation::IInspectable");
            // Very specific dance here. The return value must have a ref on the outer, while inner must have a ref count of 1.
            // Be sure not to make a delegating QueryInterface call because the controlling outer is not fully constructed yet.
            com_ptr<D> instance = make_self<D>();
            D& object = *instance;
            detach_abi(instance);

            object.m_outer = get_abi(outer);
            attach_abi(inner, to_abi<INonDelegatingInspectable>(&object));
            return inner.as<I>();
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
            if (shim().IsComposed())
            {
                check_hresult(shim().QueryInterface(impl::guid_v<I>, reinterpret_cast<void**>(put_abi(result))));
            }
            return result;
        }
    };

    template <typename T, typename D, typename I>
    class produce_dispatch_to_super;

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
            wrapper(wrapper&&) = default;
        };

    public:
        wrapper super() noexcept
        {
            return wrapper{ static_cast<D&>(*this) };
        }
    };
}

template <typename D, typename ... R>
class composable_base : public implements<D, R...>, public impl::producer<D, impl::INonDelegatingInspectable>
{
    using base_type = implements<D, R...>;
    ::IInspectable* m_outer = nullptr;

public:
    HRESULT __stdcall QueryInterface(const GUID& id, void** object) noexcept
    {
        if (IsComposed())
        {
            return m_outer->QueryInterface(id, object);
        }
        return base_type::QueryInterface(id, object);
    }

    unsigned long __stdcall AddRef() noexcept
    {
        if (IsComposed())
        {
            return m_outer->AddRef();
        }
        return base_type::AddRef();
    }

    unsigned long __stdcall Release() noexcept
    {
        if (IsComposed())
        {
            return m_outer->Release();
        }
        return base_type::Release();
    }

    HRESULT __stdcall GetIids(uint32_t* count, GUID** array) noexcept
    {
        if (IsComposed())
        {
            return m_outer->GetIids(reinterpret_cast<ULONG*>(count), array);
        }
        return base_type::GetIids(count, array);
    }

    HRESULT __stdcall GetRuntimeClassName(HSTRING* name) noexcept
    {
        if (IsComposed())
        {
            return m_outer->GetRuntimeClassName(name);
        }
        return base_type::GetRuntimeClassName(name);
    }

    HRESULT __stdcall GetTrustLevel(TrustLevel* trustLevel) noexcept
    {
        if (IsComposed())
        {
            return m_outer->GetTrustLevel(trustLevel);
        }
        return base_type::GetTrustLevel(trustLevel);
    }

    bool IsComposed() const noexcept
    {
        return m_outer != nullptr;
    }

protected:
    HRESULT __stdcall NonDelegatingQueryInterface(const GUID& id, void** object) noexcept
    {
        if (id == __uuidof(::IUnknown) || id == __uuidof(::IInspectable))
        {
            ::IInspectable* result = to_abi<impl::INonDelegatingInspectable>(this);
            NonDelegatingAddRef();
            *object = result;
            return S_OK;
        }
        return base_type::QueryInterface(id, object);
    }

    unsigned long __stdcall NonDelegatingAddRef() noexcept
    {
        return base_type::AddRef();
    }

    unsigned long __stdcall NonDelegatingRelease() noexcept
    {
        return base_type::Release();
    }

    HRESULT __stdcall NonDelegatingGetIids(uint32_t* count, GUID** array) noexcept
    {
        return base_type::GetIids(count, array);
    }

    HRESULT __stdcall NonDelegatingGetRuntimeClassName(HSTRING* name) noexcept
    {
        return base_type::GetRuntimeClassName(name);
    }

    HRESULT __stdcall NonDelegatingGetTrustLevel(TrustLevel* trustLevel) noexcept
    {
        return base_type::GetTrustLevel(trustLevel);
    }

    template <typename D, typename I>
    friend struct impl::produce_base;

    template <typename D, typename I>
    friend struct impl::produce;

    template <typename D>
    friend struct impl::composable_factory;
};

template <typename D, typename... R>
class composable_base_overrides : public composable_base<D, R...>
{
    using base_type = composable_base<D, R...>;
public:
    template <typename Qi>
    Qi as() const
    {
        return m_inner.as<Qi>();
    }

    HRESULT __stdcall NonDelegatingQueryInterface(const GUID& id, void** object) noexcept
    {
        HRESULT result = base_type::NonDelegatingQueryInterface(id, object);
        if (result == E_NOINTERFACE)
        {
            result = get_abi(m_inner)->QueryInterface(id, object);
        }
        return result;
    }

    HRESULT __stdcall QueryInterface(const GUID& id, void** object) noexcept
    {
        HRESULT result = base_type::QueryInterface(id, object);
        if (result == E_NOINTERFACE)
        {
            result = get_abi(m_inner)->QueryInterface(id, object);
        }
        return result;
    }

    explicit operator bool() const noexcept
    {
        return m_inner.operator bool();
    }

protected:
    Windows::Foundation::IInspectable m_inner;
};
