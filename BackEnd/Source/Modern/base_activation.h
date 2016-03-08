
namespace winrt {

namespace impl {

inline void ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
	check_hresult(RoActivateInstance(classId, put(instance)));
}

template <typename Interface>
void ActivateInstance(HSTRING classId, Interface & result)
{
	Windows::IInspectable instance;
	ActivateInstance(classId, instance);
	result = instance.As<Interface>();
}

}

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check_hresult(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

inline void Uninitialize() noexcept
{
	RoUninitialize();
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
	check_hresult(RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
	return factory;
}

}
