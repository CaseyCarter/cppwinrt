// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::Globalization {

struct IApplicationLanguagesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationLanguagesStatics>
{
    IApplicationLanguagesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendar :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendar>
{
    ICalendar(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarFactory>
{
    ICalendarFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarFactory2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarFactory2>
{
    ICalendarFactory2(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarIdentifiersStatics>
{
    ICalendarIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarIdentifiersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarIdentifiersStatics2>
{
    ICalendarIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarIdentifiersStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarIdentifiersStatics3>
{
    ICalendarIdentifiersStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IClockIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IClockIdentifiersStatics>
{
    IClockIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrencyIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrencyIdentifiersStatics>
{
    ICurrencyIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrencyIdentifiersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrencyIdentifiersStatics2>
{
    ICurrencyIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IGeographicRegion :
    Windows::Foundation::IInspectable,
    impl::consume<IGeographicRegion>
{
    IGeographicRegion(std::nullptr_t = nullptr) noexcept {}
};

struct IGeographicRegionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IGeographicRegionFactory>
{
    IGeographicRegionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGeographicRegionStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGeographicRegionStatics>
{
    IGeographicRegionStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguage :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguage>
{
    ILanguage(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageExtensionSubtags :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageExtensionSubtags>
{
    ILanguageExtensionSubtags(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageFactory>
{
    ILanguageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageStatics>
{
    ILanguageStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageStatics2>
{
    ILanguageStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct INumeralSystemIdentifiersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<INumeralSystemIdentifiersStatics>
{
    INumeralSystemIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct INumeralSystemIdentifiersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<INumeralSystemIdentifiersStatics2>
{
    INumeralSystemIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ITimeZoneOnCalendar :
    Windows::Foundation::IInspectable,
    impl::consume<ITimeZoneOnCalendar>
{
    ITimeZoneOnCalendar(std::nullptr_t = nullptr) noexcept {}
};

}

}
