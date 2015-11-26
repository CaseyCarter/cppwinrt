
namespace winrt { namespace impl {

inline void ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
	check(RoActivateInstance(classId, put(instance)));
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

template <typename Class, typename Instance = Class>
Instance ActivateInstance()
{
	StringReference classId(impl::traits<Class>::name(),
							impl::traits<Class>::name_length);

	Instance instance = nullptr;
	impl_ActivateInstance(get(classId), instance);
	return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(impl::traits<Class>::name(),
							impl::traits<Class>::name_length);

	Interface factory;
	check(RoGetActivationFactory(get(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put(factory))));
	return factory;
}

}
