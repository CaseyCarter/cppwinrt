// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Data {

template <typename D, typename ... Interfaces> struct BindingT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::Data::IBinding, Windows::UI::Xaml::Data::IBinding2>
{
    using composable = Binding;

protected:

    BindingT()
    {
        GetActivationFactory<Binding, IBindingFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct BindingBaseT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase>
{
    using composable = BindingBase;

protected:

    BindingBaseT()
    {
        GetActivationFactory<BindingBase, IBindingBaseFactory>().CreateInstance(*this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CurrentChangingEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
{
    using composable = CurrentChangingEventArgs;

protected:

    CurrentChangingEventArgsT()
    {
        GetActivationFactory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateInstance(*this, m_inner);
    }

    CurrentChangingEventArgsT(bool isCancelable)
    {
        GetActivationFactory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateWithCancelableParameter(isCancelable, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemIndexRangeT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::IItemIndexRange>
{
    using composable = ItemIndexRange;

protected:

    ItemIndexRangeT(int32_t firstIndex, uint32_t length)
    {
        GetActivationFactory<ItemIndexRange, IItemIndexRangeFactory>().CreateInstance(firstIndex, length, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PropertyChangedEventArgsT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
    using composable = PropertyChangedEventArgs;

protected:

    PropertyChangedEventArgsT(hstring_ref name)
    {
        GetActivationFactory<PropertyChangedEventArgs, IPropertyChangedEventArgsFactory>().CreateInstance(name, *this, m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RelativeSourceT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IRelativeSource>
{
    using composable = RelativeSource;

protected:

    RelativeSourceT()
    {
        GetActivationFactory<RelativeSource, IRelativeSourceFactory>().CreateInstance(*this, m_inner);
    }
};

}

}
