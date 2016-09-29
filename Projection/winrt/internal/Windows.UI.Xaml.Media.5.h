// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media {

template <typename D, typename ... Interfaces> struct BrushT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush>
{
    using composable = Brush;

protected:

    BrushT()
    {
        get_activation_factory<Brush, IBrushFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CacheModeT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::ICacheMode>
{
    using composable = CacheMode;

protected:

    CacheModeT()
    {
        get_activation_factory<CacheMode, ICacheModeFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FontFamilyT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Media::IFontFamily>
{
    using composable = FontFamily;

protected:

    FontFamilyT(hstring_ref familyName)
    {
        get_activation_factory<FontFamily, IFontFamilyFactory>().CreateInstanceWithName(familyName, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GeneralTransformT :
    overrides<D, Windows::UI::Xaml::Media::IGeneralTransformOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform>
{
    using composable = GeneralTransform;

protected:

    GeneralTransformT()
    {
        get_activation_factory<GeneralTransform, IGeneralTransformFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GradientBrushT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::IGradientBrush>
{
    using composable = GradientBrush;

protected:

    GradientBrushT()
    {
        get_activation_factory<GradientBrush, IGradientBrushFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProjectionT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IProjection>
{
    using composable = Projection;

protected:

    ProjectionT()
    {
        get_activation_factory<Projection, IProjectionFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TileBrushT :
    overrides<D, Windows::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::ITileBrush>
{
    using composable = TileBrush;

protected:

    TileBrushT()
    {
        get_activation_factory<TileBrush, ITileBrushFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
