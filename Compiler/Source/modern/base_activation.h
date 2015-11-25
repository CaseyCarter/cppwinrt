
namespace Modern {

inline void impl_ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
	check(RoActivateInstance(classId, put(instance)));
}

template <typename Interface>
void impl_ActivateInstance(HSTRING classId, Interface & result)
{
	Windows::IInspectable instance;
	impl_ActivateInstance(classId, instance);
	result = instance.As<Interface>();
}

template <typename Class, typename Instance = Class>
Instance ActivateInstance()
{
	StringReference classId(Traits<Class>::Name(),
							Traits<Class>::NameLength);

	Instance instance = nullptr;
	impl_ActivateInstance(get(classId), instance);
	return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(Traits<Class>::Name(),
							Traits<Class>::NameLength);

	Interface factory;
	check(RoGetActivationFactory(get(classId), __uuidof(Abi<Interface>), reinterpret_cast<void **>(put(factory))));
	return factory;
}

}
