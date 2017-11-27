﻿#pragma once

#include "Events.g.h"

namespace winrt::Component::implementation
{
    struct Events : EventsT<Events>
    {
        Events() = default;

        static event_token StaticEvent(Windows::Foundation::EventHandler<int32_t> const& handler);
        static void StaticEvent(event_token const& cookie);
        static void RaiseStaticEvent(int value);

        event_token SimpleEvent(Windows::Foundation::EventHandler<int32_t> const& handler);
        void SimpleEvent(event_token const& cookie);
        void RaiseSimpleEvent(int value);

        event_token TypedEvent(Windows::Foundation::TypedEventHandler<Component::Events, int32_t> const& handler);
        void TypedEvent(event_token const& cookie);
        void RaiseTypedEvent(int value);

        event_token CustomEvent(CustomDelegate const& handler);
        void CustomEvent(event_token const& cookie);
        void RaiseCustomEvent(int value);

    private:
        agile_event<Windows::Foundation::EventHandler<int32_t>> m_simple;
        agile_event<Windows::Foundation::TypedEventHandler<Component::Events, int32_t>> m_typed;
        agile_event<CustomDelegate> m_custom;

        // TODO: need a class template for the static store thing...
        static agile_event<Windows::Foundation::EventHandler<int32_t>> m_static;
    };
}

namespace winrt::Component::factory_implementation
{
    struct Events : EventsT<Events, implementation::Events>
    {
    };
}
