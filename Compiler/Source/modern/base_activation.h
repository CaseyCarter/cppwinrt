
namespace winrt { namespace impl {

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

}}

namespace winrt {

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check_hresult(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

template <typename Class, typename Instance = Class>
Instance ActivateInstance()
{
	StringReference classId(impl::traits<Class>::name(),
							impl::traits<Class>::name_length);

	Instance instance = nullptr;
	impl::ActivateInstance(get(classId), instance);
	return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(impl::traits<Class>::name(),
							impl::traits<Class>::name_length);

	Interface factory;
	check_hresult(RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
	return factory;
}

}
