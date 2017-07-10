#include "pch.h"
#include "catch.hpp"

using namespace winrt;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;

namespace
{
    struct Source : implements<Source, IFrameworkViewSource>
    {
        IFrameworkView CreateView()
        {
            throw hresult_not_implemented();
        }
    };

    struct App : implements<App, ICoreApplication>
    {
        hstring Id() const
        {
            throw hresult_not_implemented();
        }
        event_token Suspending(Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> const& /*handler*/) const
        {
            throw hresult_not_implemented();
        }
        void Suspending(event_token const&) const
        {
            throw hresult_not_implemented();
        }
        event_token Resuming(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const&) const
        {
            throw hresult_not_implemented();
        }
        void Resuming(event_token const&) const
        {
            throw hresult_not_implemented();
        }
        Windows::Foundation::Collections::IPropertySet Properties() const
        {
            throw hresult_not_implemented();
        }
        Windows::ApplicationModel::Core::CoreApplicationView GetCurrentView() const
        {
            throw hresult_not_implemented();
        }
        void Run(Windows::ApplicationModel::Core::IFrameworkViewSource const& /*viewSource*/) const
        {
            throw hresult_not_implemented();
        }
        void RunWithActivationFactories(Windows::Foundation::IGetActivationFactory const&) const
        {
            throw hresult_not_implemented();
        }

    };
}

TEST_CASE("produce_validate")
{
    IFrameworkViewSource source = make<Source>();
    ICoreApplication app = make<App>();

    REQUIRE_THROWS_AS(app.Suspending([](auto&&...) {}), hresult_not_implemented);
    REQUIRE_THROWS_AS(app.Run(source), hresult_not_implemented);

    try
    {
        app.Suspending(nullptr);
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const& e)
    {
        REQUIRE(e.message() == L"handler");
    }

    try
    {
        app.Run(nullptr);
        REQUIRE(false);
    }
    catch (hresult_invalid_argument const& e)
    {
        REQUIRE(e.message() == L"viewSource");
    }
}
