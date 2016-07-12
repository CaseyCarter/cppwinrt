// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml {

template <typename D, typename ... Interfaces> struct AdaptiveTriggerT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected, Windows::UI::Xaml::IAdaptiveTrigger>
{
    using composable = AdaptiveTrigger;

protected:

    AdaptiveTriggerT()
    {
        GetActivationFactory<AdaptiveTrigger, IAdaptiveTriggerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ApplicationT :
    overrides<D, Windows::UI::Xaml::IApplicationOverridesT<D>, Windows::UI::Xaml::IApplicationOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IApplication, Windows::UI::Xaml::IApplication2>
{
    using composable = Application;

protected:

    ApplicationT()
    {
        GetActivationFactory<Application, IApplicationFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDataTemplate, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    using composable = DataTemplate;

protected:

    DataTemplateT()
    {
        GetActivationFactory<DataTemplate, IDataTemplateFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateKeyT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDataTemplateKey>
{
    using composable = DataTemplateKey;

protected:

    DataTemplateKeyT()
    {
        GetActivationFactory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstance(*this, m_inner);
    }

    DataTemplateKeyT(const Windows::IInspectable & dataType)
    {
        GetActivationFactory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstanceWithType(dataType, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DependencyObjectT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = DependencyObject;

protected:

    DependencyObjectT()
    {
        GetActivationFactory<DependencyObject, IDependencyObjectFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DependencyObjectCollectionT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>>
{
    using composable = DependencyObjectCollection;

protected:

    DependencyObjectCollectionT()
    {
        GetActivationFactory<DependencyObjectCollection, IDependencyObjectCollectionFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DispatcherTimerT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDispatcherTimer>
{
    using composable = DispatcherTimer;

protected:

    DispatcherTimerT()
    {
        GetActivationFactory<DispatcherTimer, IDispatcherTimerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkElementT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = FrameworkElement;

protected:

    FrameworkElementT()
    {
        GetActivationFactory<FrameworkElement, IFrameworkElementFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkTemplateT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    using composable = FrameworkTemplate;

protected:

    FrameworkTemplateT()
    {
        GetActivationFactory<FrameworkTemplate, IFrameworkTemplateFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PropertyMetadataT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IPropertyMetadata>
{
    using composable = PropertyMetadata;

protected:

    PropertyMetadataT(const Windows::IInspectable & defaultValue)
    {
        GetActivationFactory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValue(defaultValue, *this, m_inner);
    }

    PropertyMetadataT(const Windows::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback)
    {
        GetActivationFactory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValueAndCallback(defaultValue, propertyChangedCallback, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ResourceDictionaryT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IResourceDictionary, Windows::Foundation::Collections::IMap<Windows::IInspectable, Windows::IInspectable>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Windows::IInspectable, Windows::IInspectable>>>
{
    using composable = ResourceDictionary;

protected:

    ResourceDictionaryT()
    {
        GetActivationFactory<ResourceDictionary, IResourceDictionaryFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RoutedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = RoutedEventArgs;

protected:

    RoutedEventArgsT()
    {
        GetActivationFactory<RoutedEventArgs, IRoutedEventArgsFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StateTriggerBaseT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected>
{
    using composable = StateTriggerBase;

protected:

    StateTriggerBaseT()
    {
        GetActivationFactory<StateTriggerBase, IStateTriggerBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct VisualStateManagerT :
    overrides<D, Windows::UI::Xaml::IVisualStateManagerOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualStateManager, Windows::UI::Xaml::IVisualStateManagerProtected>
{
    using composable = VisualStateManager;

protected:

    VisualStateManagerT()
    {
        GetActivationFactory<VisualStateManager, IVisualStateManagerFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct VisualTransitionT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualTransition>
{
    using composable = VisualTransition;

protected:

    VisualTransitionT()
    {
        GetActivationFactory<VisualTransition, IVisualTransitionFactory>().CreateInstance(*this, m_inner);
    }
};

}

}
