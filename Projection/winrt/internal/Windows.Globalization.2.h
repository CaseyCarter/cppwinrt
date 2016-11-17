// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::Globalization {

struct IApplicationLanguagesStatics :
    Windows::IInspectable,
    impl::consume<IApplicationLanguagesStatics>
{
    IApplicationLanguagesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IApplicationLanguagesStatics>(m_ptr); }
};

struct ICalendar :
    Windows::IInspectable,
    impl::consume<ICalendar>
{
    ICalendar(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendar>(m_ptr); }
};

struct ICalendarFactory :
    Windows::IInspectable,
    impl::consume<ICalendarFactory>
{
    ICalendarFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarFactory>(m_ptr); }
};

struct ICalendarFactory2 :
    Windows::IInspectable,
    impl::consume<ICalendarFactory2>
{
    ICalendarFactory2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarFactory2>(m_ptr); }
};

struct ICalendarIdentifiersStatics :
    Windows::IInspectable,
    impl::consume<ICalendarIdentifiersStatics>
{
    ICalendarIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarIdentifiersStatics>(m_ptr); }
};

struct ICalendarIdentifiersStatics2 :
    Windows::IInspectable,
    impl::consume<ICalendarIdentifiersStatics2>
{
    ICalendarIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarIdentifiersStatics2>(m_ptr); }
};

struct ICalendarIdentifiersStatics3 :
    Windows::IInspectable,
    impl::consume<ICalendarIdentifiersStatics3>
{
    ICalendarIdentifiersStatics3(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICalendarIdentifiersStatics3>(m_ptr); }
};

struct IClockIdentifiersStatics :
    Windows::IInspectable,
    impl::consume<IClockIdentifiersStatics>
{
    IClockIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IClockIdentifiersStatics>(m_ptr); }
};

struct ICurrencyIdentifiersStatics :
    Windows::IInspectable,
    impl::consume<ICurrencyIdentifiersStatics>
{
    ICurrencyIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICurrencyIdentifiersStatics>(m_ptr); }
};

struct IGeographicRegion :
    Windows::IInspectable,
    impl::consume<IGeographicRegion>
{
    IGeographicRegion(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGeographicRegion>(m_ptr); }
};

struct IGeographicRegionFactory :
    Windows::IInspectable,
    impl::consume<IGeographicRegionFactory>
{
    IGeographicRegionFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGeographicRegionFactory>(m_ptr); }
};

struct IGeographicRegionStatics :
    Windows::IInspectable,
    impl::consume<IGeographicRegionStatics>
{
    IGeographicRegionStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IGeographicRegionStatics>(m_ptr); }
};

struct ILanguage :
    Windows::IInspectable,
    impl::consume<ILanguage>
{
    ILanguage(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguage>(m_ptr); }
};

struct ILanguageExtensionSubtags :
    Windows::IInspectable,
    impl::consume<ILanguageExtensionSubtags>
{
    ILanguageExtensionSubtags(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageExtensionSubtags>(m_ptr); }
};

struct ILanguageFactory :
    Windows::IInspectable,
    impl::consume<ILanguageFactory>
{
    ILanguageFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageFactory>(m_ptr); }
};

struct ILanguageStatics :
    Windows::IInspectable,
    impl::consume<ILanguageStatics>
{
    ILanguageStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageStatics>(m_ptr); }
};

struct ILanguageStatics2 :
    Windows::IInspectable,
    impl::consume<ILanguageStatics2>
{
    ILanguageStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ILanguageStatics2>(m_ptr); }
};

struct INumeralSystemIdentifiersStatics :
    Windows::IInspectable,
    impl::consume<INumeralSystemIdentifiersStatics>
{
    INumeralSystemIdentifiersStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INumeralSystemIdentifiersStatics>(m_ptr); }
};

struct INumeralSystemIdentifiersStatics2 :
    Windows::IInspectable,
    impl::consume<INumeralSystemIdentifiersStatics2>
{
    INumeralSystemIdentifiersStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<INumeralSystemIdentifiersStatics2>(m_ptr); }
};

struct ITimeZoneOnCalendar :
    Windows::IInspectable,
    impl::consume<ITimeZoneOnCalendar>
{
    ITimeZoneOnCalendar(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ITimeZoneOnCalendar>(m_ptr); }
};

}

}
