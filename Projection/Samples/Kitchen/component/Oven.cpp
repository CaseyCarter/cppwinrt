#include "pch.h"
#include "Oven.h"
#include "Bread.h"
#include "BreadBakedEventArgs.h"
#include <future>

using namespace winrt::Windows::Foundation;
using namespace winrt::Microsoft::SDKSamples::Kitchen;

namespace winrt::Microsoft::SDKSamples::Kitchen::implementation
{
    Oven::Oven(Kitchen::Dimensions const& dimensions)
    {
        _dimensions = dimensions;
    }

    void Oven::ConfigurePreheatTemperature(OvenTemperature const& temperature)
    {
        if (temperature >= OvenTemperature::Low && temperature <= OvenTemperature::High)
        {
            _temperature = temperature;
        }
        else 
        {
            throw hresult_invalid_argument();
        }
    }

    TimeSpan Oven::GetPreheatTime()
    {
        using namespace std::chrono_literals;

        switch (_temperature)
        {
        case OvenTemperature::Low:
            return 100ms;
        case OvenTemperature::Medium:
            return 200ms;
        case OvenTemperature::High:
            return 300ms;
        default:
            throw hresult_invalid_argument();
        }
    }

    void Oven::BakeBread(hstring const& flavor)
    {
        auto preheatTime = GetPreheatTime();

        Kitchen::Oven oven{nullptr};
        copy_from_abi(oven, this);

        std::async(std::launch::async, [this, oven, preheatTime, flavor]()
        {
            std::this_thread::sleep_for(preheatTime);

            auto bread = make<Bread>(flavor).as<Kitchen::Bread>();
            auto eventArgs = make<BreadBakedEventArgs>(bread).as<Kitchen::BreadBakedEventArgs>();

            _breadBakedEvent(oven, eventArgs);
        });
    }

    event_token Oven::BreadBaked(Windows::Foundation::TypedEventHandler<Microsoft::SDKSamples::Kitchen::Oven, Microsoft::SDKSamples::Kitchen::BreadBakedEventArgs> const& handler)
    {
        return _breadBakedEvent.add(handler);
    }

    void Oven::BreadBaked(event_token const& token)
    {
        _breadBakedEvent.remove(token);
    }

    double Oven::Volume()
    {
        return _dimensions.Height * _dimensions.Width * _dimensions.Depth;
    }
}
