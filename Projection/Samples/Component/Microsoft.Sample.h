#pragma once

namespace winrt::Microsoft::Sample
{
    struct Hen {};

    template <typename D>
    struct HenT : implements<D, Windows::Foundation::IStringable>
    {
    };

    template <typename D, typename T>
    struct HenFactoryT : implements<D, Windows::Foundation::IActivationFactory>
    {
        Windows::Foundation::IInspectable ActivateInstance()
        {
            return make<T>();
        }
    };

}
