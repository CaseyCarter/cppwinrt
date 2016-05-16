#include "pch.h"

namespace cx
{
    using namespace Windows::Foundation;
    using namespace Windows::ApplicationModel;
    using namespace Windows::ApplicationModel::Appointments;
}

namespace winrt
{
    using namespace Windows::Foundation;
    using namespace Windows::ApplicationModel;
    using namespace Windows::ApplicationModel::Appointments;
}

//
// Illustrates calling factory methods - logical constructors and static methods (via RoGetActivationFactory).
//
uint64_t factory_sample_cx()
{
    uint64_t check = 0;

    for (unsigned i = 0; i != 1'000'000; ++i)
    {
        cx::Uri uri(L"http://host/path");

        bool design = cx::DesignMode::DesignModeEnabled;

        check += uri.Host->Length() + design;
    }

    return check;
}

uint64_t factory_sample()
{
    uint64_t check = 0;

    for (unsigned i = 0; i != 1'000'000; ++i)
    {
        winrt::Uri uri(L"http://host/path");

        bool design = winrt::DesignMode::DesignModeEnabled();

        check += uri.Host().size() + design;
    }

    return check;
}

uint64_t factory_sample_optimized()
{
    uint64_t check = 0;
    auto uriFactory = winrt::GetActivationFactory<winrt::Uri, winrt::IUriRuntimeClassFactory>();
    auto designModeFactory = winrt::GetActivationFactory<winrt::DesignMode, winrt::IDesignModeStatics>();

    for (unsigned i = 0; i != 1'000'000; ++i)
    {
        auto uri = uriFactory.CreateUri(L"http://host/path");

        bool design = designModeFactory.DesignModeEnabled();

        check += uri.Host().size() + design;
    }

    return check;
}

//
// Illustrates calling required methods (via QueryInterface).
//
uint64_t required_sample_cx()
{
    uint64_t check = 0;
    cx::Uri uri(L"http://host/path");

    for (unsigned i = 0; i != 10'000'000; ++i)
    {
        auto result = uri.ToString();

        check += result->Length();
    }

    return check;
}

uint64_t required_sample()
{
    uint64_t check = 0;
    winrt::Uri uri(L"http://host/path");

    for (unsigned i = 0; i != 10'000'000; ++i)
    {
        auto result = uri.ToString();

        check += result.size();
    }

    return check;
}

uint64_t required_sample_optimized()
{
    uint64_t check = 0;
    winrt::Uri uri(L"http://host/path");
    auto stringable = uri.as<winrt::IStringable>();

    for (unsigned i = 0; i != 10'000'000; ++i)
    {
        auto result = stringable.ToString();

        check += result.size();
    }

    return check;
}

template <typename F>
void measure(char const * name, F function)
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    uint64_t check = function();

    auto finish = high_resolution_clock::now();
    double elapsed = duration_cast<duration<double>>(finish - start).count();

    printf("%.2fs (%lld) -- %s\n", elapsed, check, name);
}

int main()
{
    winrt::Initialize();

    printf("\nCalling factory and static methods via RoGetActivationFactory\n");
    measure("cx", factory_sample_cx);
    measure("modern", factory_sample);
    measure("optimized", factory_sample_optimized);

    printf("\nCalling required methods via QueryInterface\n");
    measure("cx", required_sample_cx);
    measure("modern", required_sample);
    measure("optimized", required_sample_optimized);
}
