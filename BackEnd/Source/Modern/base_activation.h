
namespace impl {

inline void ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
    check_hresult(WINRT_RoActivateInstance(classId, reinterpret_cast<void **>(put(instance))));
}

template <typename Interface>
void ActivateInstance(HSTRING classId, Interface & result)
{
    Windows::IInspectable instance;
    ActivateInstance(classId, instance);
    result = instance.as<Interface>();
}

}

enum class InitializeType
{
    SingleThreaded,
    MultiThreaded
};

inline void Initialize(const InitializeType type = InitializeType::MultiThreaded)
{
    check_hresult(WINRT_RoInitialize(static_cast<uint32_t>(type)));
}

inline void Uninitialize() noexcept
{
    WINRT_RoUninitialize();
}

template <typename Class, typename Instance = Class>
Instance ActivateInstance()
{
    hstring_ref classId(impl::traits<Class>::name());

    Instance instance = nullptr;
    impl::ActivateInstance(get(classId), instance);
    return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
    hstring_ref classId(impl::traits<Class>::name());

    Interface factory;
    check_hresult(WINRT_RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
    return factory;
}
