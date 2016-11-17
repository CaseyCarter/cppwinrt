// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.Interactions.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Composition.1.h"
#include "Windows.UI.Composition.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
#define WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
template <> struct __declspec(uuid("719cc2ba-3e76-5def-9f1a-38d85a145ea8")) __declspec(novtable) IReference<float> : impl_IReference<float> {};
#endif

#ifndef WINRT_GENERIC_1ee770ff_c954_59ca_a754_6199a9be282c
#define WINRT_GENERIC_1ee770ff_c954_59ca_a754_6199a9be282c
template <> struct __declspec(uuid("1ee770ff-c954-59ca-a754-6199a9be282c")) __declspec(novtable) IReference<Windows::Foundation::Numerics::float3> : impl_IReference<Windows::Foundation::Numerics::float3> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_17c50e21_cb70_5a2b_b797_a8dc01a99113
#define WINRT_GENERIC_17c50e21_cb70_5a2b_b797_a8dc01a99113
template <> struct __declspec(uuid("17c50e21-cb70-5a2b-b797-a8dc01a99113")) __declspec(novtable) IIterable<Windows::UI::Composition::Interactions::ICompositionInteractionSource> : impl_IIterable<Windows::UI::Composition::Interactions::ICompositionInteractionSource> {};
#endif

#ifndef WINRT_GENERIC_9a245c40_aae6_59fb_87f5_4bb05599f0b1
#define WINRT_GENERIC_9a245c40_aae6_59fb_87f5_4bb05599f0b1
template <> struct __declspec(uuid("9a245c40-aae6-59fb-87f5-4bb05599f0b1")) __declspec(novtable) IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> : impl_IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> {};
#endif

#ifndef WINRT_GENERIC_20259ef3_9f4b_5257_8581_6d3eabbbd690
#define WINRT_GENERIC_20259ef3_9f4b_5257_8581_6d3eabbbd690
template <> struct __declspec(uuid("20259ef3-9f4b-5257-8581-6d3eabbbd690")) __declspec(novtable) IIterator<Windows::UI::Composition::Interactions::ICompositionInteractionSource> : impl_IIterator<Windows::UI::Composition::Interactions::ICompositionInteractionSource> {};
#endif

#ifndef WINRT_GENERIC_46617d87_2cd2_5e31_9a30_ea86f8aa7ca1
#define WINRT_GENERIC_46617d87_2cd2_5e31_9a30_ea86f8aa7ca1
template <> struct __declspec(uuid("46617d87-2cd2-5e31-9a30-ea86f8aa7ca1")) __declspec(novtable) IIterator<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> : impl_IIterator<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> {};
#endif


}

namespace Windows::UI::Composition::Interactions {

struct ICompositionInteractionSource :
    Windows::IInspectable,
    impl::consume<ICompositionInteractionSource>
{
    ICompositionInteractionSource(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICompositionInteractionSource>(m_ptr); }
};

struct ICompositionInteractionSourceCollection :
    Windows::IInspectable,
    impl::consume<ICompositionInteractionSourceCollection>,
    impl::require<ICompositionInteractionSourceCollection, Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::ICompositionInteractionSource>>
{
    ICompositionInteractionSourceCollection(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICompositionInteractionSourceCollection>(m_ptr); }
};

struct IInteractionTracker :
    Windows::IInspectable,
    impl::consume<IInteractionTracker>
{
    IInteractionTracker(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTracker>(m_ptr); }
};

struct IInteractionTrackerCustomAnimationStateEnteredArgs :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerCustomAnimationStateEnteredArgs>
{
    IInteractionTrackerCustomAnimationStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerCustomAnimationStateEnteredArgs>(m_ptr); }
};

struct IInteractionTrackerIdleStateEnteredArgs :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerIdleStateEnteredArgs>
{
    IInteractionTrackerIdleStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerIdleStateEnteredArgs>(m_ptr); }
};

struct IInteractionTrackerInertiaModifier :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaModifier>
{
    IInteractionTrackerInertiaModifier(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaModifier>(m_ptr); }
};

struct IInteractionTrackerInertiaModifierFactory :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaModifierFactory>
{
    IInteractionTrackerInertiaModifierFactory(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaModifierFactory>(m_ptr); }
};

struct IInteractionTrackerInertiaMotion :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaMotion>
{
    IInteractionTrackerInertiaMotion(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaMotion>(m_ptr); }
};

struct IInteractionTrackerInertiaMotionStatics :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaMotionStatics>
{
    IInteractionTrackerInertiaMotionStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaMotionStatics>(m_ptr); }
};

struct IInteractionTrackerInertiaRestingValue :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaRestingValue>
{
    IInteractionTrackerInertiaRestingValue(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaRestingValue>(m_ptr); }
};

struct IInteractionTrackerInertiaRestingValueStatics :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaRestingValueStatics>
{
    IInteractionTrackerInertiaRestingValueStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaRestingValueStatics>(m_ptr); }
};

struct IInteractionTrackerInertiaStateEnteredArgs :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInertiaStateEnteredArgs>
{
    IInteractionTrackerInertiaStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInertiaStateEnteredArgs>(m_ptr); }
};

struct IInteractionTrackerInteractingStateEnteredArgs :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerInteractingStateEnteredArgs>
{
    IInteractionTrackerInteractingStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerInteractingStateEnteredArgs>(m_ptr); }
};

struct IInteractionTrackerOwner :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerOwner>
{
    IInteractionTrackerOwner(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerOwner>(m_ptr); }
};

struct IInteractionTrackerRequestIgnoredArgs :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerRequestIgnoredArgs>
{
    IInteractionTrackerRequestIgnoredArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerRequestIgnoredArgs>(m_ptr); }
};

struct IInteractionTrackerStatics :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerStatics>
{
    IInteractionTrackerStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerStatics>(m_ptr); }
};

struct IInteractionTrackerValuesChangedArgs :
    Windows::IInspectable,
    impl::consume<IInteractionTrackerValuesChangedArgs>
{
    IInteractionTrackerValuesChangedArgs(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IInteractionTrackerValuesChangedArgs>(m_ptr); }
};

struct IVisualInteractionSource :
    Windows::IInspectable,
    impl::consume<IVisualInteractionSource>
{
    IVisualInteractionSource(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVisualInteractionSource>(m_ptr); }
};

struct IVisualInteractionSourceStatics :
    Windows::IInspectable,
    impl::consume<IVisualInteractionSourceStatics>
{
    IVisualInteractionSourceStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IVisualInteractionSourceStatics>(m_ptr); }
};

}

}
