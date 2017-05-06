#pragma once

#include "module.h"

namespace winrt::Microsoft::SDKSamples::Kitchen::implementation
{
    struct Oven : OvenT<Oven>
    {
        Oven() = default;
        Oven(Microsoft::SDKSamples::Kitchen::Dimensions const& dimensions);

        void ConfigurePreheatTemperature(Microsoft::SDKSamples::Kitchen::OvenTemperature const& temperature);
        void BakeBread(hstring const& flavor);
        event_token BreadBaked(Windows::Foundation::TypedEventHandler<Microsoft::SDKSamples::Kitchen::Oven, Microsoft::SDKSamples::Kitchen::BreadBakedEventArgs> const& handler);
        void BreadBaked(event_token const& token);
        double Volume();

    private:
        winrt::Windows::Foundation::TimeSpan GetPreheatTime();
        Microsoft::SDKSamples::Kitchen::Dimensions _dimensions{};
        Microsoft::SDKSamples::Kitchen::OvenTemperature _temperature{};
        winrt::agile_event<Windows::Foundation::TypedEventHandler<Microsoft::SDKSamples::Kitchen::Oven, Microsoft::SDKSamples::Kitchen::BreadBakedEventArgs>> _breadBakedEvent; 
    };

    struct OvenFactory : OvenFactoryT<OvenFactory, Oven>
    {
    };
}
