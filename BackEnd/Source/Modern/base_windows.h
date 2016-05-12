
namespace Windows {

struct IUnknown
{
    IUnknown() noexcept = default;
    IUnknown(std::nullptr_t) noexcept {}
    void * operator new(size_t) = delete;

    IUnknown(const IUnknown & other) noexcept :
        m_ptr(other.m_ptr)
    {
        impl_addref();
    }

    IUnknown(IUnknown && other) noexcept :
        m_ptr(other.m_ptr)
    {
        other.m_ptr = nullptr;
    }

    ~IUnknown() noexcept
    {
        impl_release();
    }

    IUnknown & operator=(const IUnknown & other) noexcept
    {
        impl_copy(other);
        return *this;
    }

    IUnknown & operator=(IUnknown && other) noexcept
    {
        impl_move(std::forward<IUnknown>(other));
        return *this;
    }

    explicit operator bool() const noexcept
    {
        return nullptr != m_ptr;
    }

    auto operator->() const noexcept
    {
        return m_ptr;
    }

    IUnknown & operator=(std::nullptr_t) noexcept
    {
        impl_release();
        return *this;
    }

    template <typename U>
    auto as() const
    {
        std::conditional_t<std::is_base_of_v<IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        check_hresult(m_ptr->abi_QueryInterface(__uuidof(abi_default_interface<U>), reinterpret_cast<void **>(put(temp))));
        return temp;
    }

    friend auto impl_get(const IUnknown & object) noexcept
    {
        return object.m_ptr;
    }

    friend auto impl_put(IUnknown & object) noexcept
    {
        WINRT_ASSERT(!object);
        return &object.m_ptr;
    }

    friend auto impl_detach(IUnknown & object) noexcept
    {
        auto temp = object.m_ptr;
        object.m_ptr = nullptr;
        return temp;
    }

    friend void swap(IUnknown & left, IUnknown & right) noexcept
    {
        std::swap(left.m_ptr, right.m_ptr);
    }

protected:

    void impl_copy(ABI::Windows::IUnknown * other) noexcept
    {
        if (m_ptr != other)
        {
            impl_release();
            m_ptr = other;
            impl_addref();
        }
    }

    void impl_copy(const IUnknown & other) noexcept
    {
        if (this != &other)
        {
            impl_release();
            m_ptr = other.m_ptr;
            impl_addref();
        }
    }

    void impl_move(IUnknown && other) noexcept
    {
        if (this != &other)
        {
            impl_release();
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
    }

    ABI::Windows::IUnknown * m_ptr = nullptr;
    
private:

    void impl_addref() const noexcept
    {
        if (m_ptr)
        {
            m_ptr->abi_AddRef();
        }
    }

    void impl_release() noexcept
    {
        auto temp = m_ptr;

        if (temp)
        {
            m_ptr = nullptr;
            temp->abi_Release();
        }
    }
};

}

namespace impl {

template <> struct traits<Windows::IUnknown>
{
    using abi = ABI::Windows::IUnknown;
};

template <typename T>
struct accessors<T, std::enable_if_t<std::is_base_of<Windows::IUnknown, T>::value>>
{
    static auto get(const T & object) noexcept
    {
        return static_cast<abi_arg_in<T>>(impl_get(object));
    }

    static auto put(T & object) noexcept
    {
        return reinterpret_cast<abi_arg_out<T>>(impl_put(object));
    }

    static void attach(T & object, abi_arg_in<T> value) noexcept
    {
        object = nullptr;
        *put(object) = value;
    }

    static void copy_from(T & object, abi_arg_in<T> value) noexcept
    {
        object = nullptr;

        if (value)
        {
            value->abi_AddRef();
            *put(object) = value;
        }
    }

    template <typename V>
    static void copy_to(const T & object, V & value) noexcept
    {
        if (object)
        {
            value = get(object);
            value->abi_AddRef();
        }
        else
        {
            value = nullptr;
        }
    }

    static auto detach(T & object) noexcept
    {
        return static_cast<abi_arg_in<T>>(impl_detach(object));
    }
};

}

namespace Windows {

inline bool operator==(const IUnknown & left, const IUnknown & right) noexcept
{
    return get(left) == get(right);
}

inline bool operator!=(const IUnknown & left, const IUnknown & right) noexcept
{
    return !(left == right);
}

inline bool operator<(const IUnknown & left, const IUnknown & right) noexcept
{
    return get(left) < get(right);
}

inline bool operator>(const IUnknown & left, const IUnknown & right) noexcept
{
    return right < left;
}

inline bool operator<=(const IUnknown & left, const IUnknown & right) noexcept
{
    return !(right < left);
}

inline bool operator>=(const IUnknown & left, const IUnknown & right) noexcept
{
    return !(left < right);
}

}

namespace Windows {

struct IInspectable;
struct IAsyncInfo;
struct IActivationFactory;

template <typename T>
class impl_IInspectable
{
    auto shim() const { return impl::shim<T, IInspectable>(this); }

public:

    hstring RuntimeClassName() const;
    com_array<GUID> Iids() const;
};

template <typename T>
class impl_IAsyncInfo
{
    auto shim() const { return impl::shim<T, IAsyncInfo>(this); }

public:

    uint32_t Id() const;
    AsyncStatus Status() const;
    HRESULT ErrorCode() const;
    void Cancel() const;
    void Close() const;
};

template <typename T>
class impl_IActivationFactory
{
    auto shim() const { return impl::shim<T, IActivationFactory>(this); }

public:

    IInspectable ActivateInstance() const;
};

}

namespace impl {

template <> struct traits<Windows::IInspectable>
{
    using abi = ABI::Windows::IInspectable;
    template <typename T> using consume = Windows::impl_IInspectable<T>;
};

template <> struct traits<Windows::IAsyncInfo>
{
    using abi = ABI::Windows::IAsyncInfo;
    template <typename T> using consume = Windows::impl_IAsyncInfo<T>;
};

template <> struct traits<Windows::IActivationFactory>
{
    using abi = ABI::Windows::IActivationFactory;
    template <typename T> using consume = Windows::impl_IActivationFactory<T>;
};

}

namespace Windows {

struct IInspectable :
    IUnknown,
    impl_IInspectable<IInspectable>
{
    IInspectable(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInspectable>(m_ptr); }
};

struct IAsyncInfo :
    IUnknown,
    impl_IAsyncInfo<IAsyncInfo>
{
    IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsyncInfo>(m_ptr); }
};

struct IActivationFactory :
    IUnknown,
    impl_IActivationFactory<IActivationFactory>
{
    IActivationFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IActivationFactory>(m_ptr); }
};

template <typename T> hstring impl_IInspectable<T>::RuntimeClassName() const
{
    hstring name;
    check_hresult(shim()->get_RuntimeClassName(put(name)));
    return name;
}

template <typename T> com_array<GUID> impl_IInspectable<T>::Iids() const
{
    com_array<GUID> result;
    check_hresult(shim()->get_Iids(put_size(result), put(result)));
    return result;
}

template <typename T> uint32_t impl_IAsyncInfo<T>::Id() const
{
    uint32_t id = 0;
    check_hresult(shim()->get_Id(&id));
    return id;
}

template <typename T> AsyncStatus impl_IAsyncInfo<T>::Status() const
{
    AsyncStatus status = {};
    check_hresult(shim()->get_Status(&status));
    return status;
}

template <typename T> HRESULT impl_IAsyncInfo<T>::ErrorCode() const
{
    HRESULT code = S_OK;
    check_hresult(shim()->get_ErrorCode(&code));
    return code;
}

template <typename T> void impl_IAsyncInfo<T>::Cancel() const
{
    check_hresult(shim()->abi_Cancel());
}

template <typename T> void impl_IAsyncInfo<T>::Close() const
{
    check_hresult(shim()->abi_Close());
}

template <typename T> IInspectable impl_IActivationFactory<T>::ActivateInstance() const
{
    IInspectable instance;
    check_hresult(shim()->abi_ActivateInstance(put(instance)));
    return instance;
}

}

template <typename T, typename I = typename T::default_interface, typename ... Args, std::enable_if_t<!impl::has_composable<T>::value> * = nullptr>
auto make(Args && ... args)
{
    std::conditional_t<std::is_base_of_v<Windows::IUnknown, I>, I, com_ptr<I>> instance = nullptr;
    *put(instance) = new T(std::forward<Args>(args) ...);
    return instance;
}

template <typename T, typename I = typename T::default_interface, typename ... Args, std::enable_if_t<impl::has_composable<T>::value> * = nullptr>
auto make(Args && ... args)
{
    com_ptr<I> instance;
    *put(instance) = new T(std::forward<Args>(args) ...);
    return instance.template as<typename T::composable>();
}

template <typename T, typename ... Args>
auto make_self(Args && ... args)
{
    com_ptr<T> instance;
    *put(instance) = new T(std::forward<Args>(args) ...);
    return instance;
}
