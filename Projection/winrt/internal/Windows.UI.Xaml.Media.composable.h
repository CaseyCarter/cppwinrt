// C++ for the Windows Runtime v1.29
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
        GetActivationFactory<Brush, IBrushFactory>().CreateInstance(*this, m_inner);
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
        GetActivationFactory<CacheMode, ICacheModeFactory>().CreateInstance(*this, m_inner);
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
        GetActivationFactory<FontFamily, IFontFamilyFactory>().CreateInstanceWithName(familyName, *this, m_inner);
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
        GetActivationFactory<GeneralTransform, IGeneralTransformFactory>().CreateInstance(*this, m_inner);
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
        GetActivationFactory<GradientBrush, IGradientBrushFactory>().CreateInstance(*this, m_inner);
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
        GetActivationFactory<Projection, IProjectionFactory>().CreateInstance(*this, m_inner);
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
        GetActivationFactory<TileBrush, ITileBrushFactory>().CreateInstance(*this, m_inner);
    }
};

}

}
