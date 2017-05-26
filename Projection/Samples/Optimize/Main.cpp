#include "pch.h"
#include "Iterable.h"

namespace cx
{
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Numerics;
    using namespace Windows::Foundation::Collections;
    using namespace Windows::ApplicationModel;
    using namespace Windows::ApplicationModel::Appointments;
    using namespace Windows::ApplicationModel::Chat;
    using namespace Windows::Security::Cryptography::Certificates;
    using namespace Windows::UI::Input::Inking;
}

namespace winrt
{
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Numerics;
    using namespace Windows::Foundation::Collections;
    using namespace Windows::ApplicationModel;
    using namespace Windows::ApplicationModel::Appointments;
    using namespace Windows::ApplicationModel::Chat;
    using namespace Windows::Security::Cryptography::Certificates;
    using namespace Windows::UI::Input::Inking;
}

static constexpr uint64_t TestPasses = 1'000'000;

//
// Illustrates calling factory methods - logical constructors and static methods (via RoGetActivationFactory).
//
uint64_t factory_sample_cx()
{
    uint64_t check = 0;

    for (unsigned i = 0; i != TestPasses; ++i)
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

    for (unsigned i = 0; i != TestPasses; ++i)
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
    auto uriFactory = winrt::get_activation_factory<winrt::Uri, winrt::IUriRuntimeClassFactory>();
    auto designModeFactory = winrt::get_activation_factory<winrt::DesignMode, winrt::IDesignModeStatics>();

    for (unsigned i = 0; i != TestPasses; ++i)
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

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
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

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
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

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
    {
        auto result = stringable.ToString();

        check += result.size();
    }

    return check;
}

//
// Illustrates the performance of fast-pass strings
//
struct Sample : winrt::implements<Sample, winrt::IChatQueryOptions>
{
    uint64_t m_check = 0;

    winrt::hstring SearchString() { return L""; }

    void SearchString(winrt::hstring const& value)
    {
        m_check += value.size();
    }
};

uint64_t fast_strings_cx()
{
    winrt::IChatQueryOptions winrt_sample = winrt::make<Sample>();
    cx::IChatQueryOptions ^ sample = reinterpret_cast<cx::IChatQueryOptions ^>(winrt::get_abi(winrt_sample));

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
    {
        sample->SearchString = L"value";
    }

    Sample * s = winrt::from_abi<Sample>(winrt_sample);
    return s->m_check;
}

uint64_t fast_strings()
{
    winrt::IChatQueryOptions sample = winrt::make<Sample>();

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
    {
        sample.SearchString(L"value");
    }

    Sample * s = winrt::from_abi<Sample>(sample);
    return s->m_check;
}

//
// Illustrates the performance of calling factory functions (without the overhead of arguments)
//
uint64_t isolated_factory_sample_cx()
{
    uint64_t check = 0;

    for (unsigned i = 0; i != 4 * TestPasses; ++i)
    {
        check += (cx::PropertyValue::CreateEmpty(), 1);
    }

    return check;
}

uint64_t isolated_factory_sample()
{
    uint64_t check = 0;

    for (unsigned i = 0; i != 4 * TestPasses; ++i)
    {
        check += (winrt::PropertyValue::CreateEmpty(), 1);
    }

    return check;
}

//
// Illustrates the performance of array input parameters
//
uint64_t array_input_cx()
{
    cx::CertificateQuery query;
    uint64_t check = 0;

    std::vector<byte> values { 1, 2, 3 };

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
    {
        query.Thumbprint = ref new Platform::Array<byte>(values.data(),
                                                         static_cast<uint32_t>(values.size()));
        check += 1;
    }

    return check;
}

uint64_t array_input_cx_undocumented()
{
    cx::CertificateQuery query;
    uint64_t check = 0;

    std::vector<byte> values{ 1, 2, 3 };

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
    {
        query.Thumbprint = Platform::ArrayReference<byte>(values.data(),
                                                          static_cast<uint32_t>(values.size()));
        check += 1;
    }

    return check;
}

uint64_t array_input()
{
    winrt::CertificateQuery query;
    uint64_t check = 0;

    std::vector<byte> values{ 1, 2, 3 };

    for (unsigned i = 0; i != 10 * TestPasses; ++i)
    {
        query.Thumbprint(values);
        check += 1;
    }

    return check;
}

//
// Illustrates the performance of collection input parameters
//

uint64_t collection_input_copy_cx()
{
    cx::InkStrokeBuilder builder;
    uint64_t check = 0;

    std::vector<cx::Point> points;

    for (unsigned i = 0; i < 200; ++i)
    {
        points.emplace_back(10.0f * i, 10.0f * i);
    }

    cx::IIterable<cx::Point> ^ vector = ref new Platform::Collections::Vector<cx::Point>(points);

    for (unsigned i = 0; i != TestPasses / 100; ++i)
    {
        builder.CreateStroke(vector);
        check += 1;
    }

    return check;
}

uint64_t collection_input_copy()
{
    winrt::InkStrokeBuilder builder;
    uint64_t check = 0;

    std::vector<winrt::Point> points;

    for (unsigned i = 0; i < 200; ++i)
    {
        points.emplace_back(10.0f * i, 10.0f * i);
    }

    winrt::IIterable<winrt::Point> vector = winrt::make<winrt::Iterable<winrt::Point>>(points);

    for (unsigned i = 0; i != TestPasses / 100; ++i)
    {
        builder.CreateStroke(vector);
        check += 1;
    }

    return check;
}

//
// Test runner
//

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
    winrt::init_apartment();

    printf("\nCalling factory and static methods via RoGetActivationFactory\n");
    measure("C++/CX", factory_sample_cx);
    measure("C++/WinRT", factory_sample);
    measure("C++/WinRT (Dev15)", factory_sample_optimized);

    printf("\nCalling required methods via QueryInterface\n");
    measure("C++/CX", required_sample_cx);
    measure("C++/WinRT", required_sample);
    measure("C++/WinRT (Dev15)", required_sample_optimized);

    printf("\nCalling a static factory method with no arguments\n");
    measure("C++/CX", isolated_factory_sample_cx);
    measure("C++/WinRT", isolated_factory_sample);

    printf("\nCalling methods with fast-pass strings\n");
    measure("C++/CX", fast_strings_cx);
    measure("C++/WinRT", fast_strings);

    printf("\nCalling methods with array input parameters\n");
    measure("C++/CX", array_input_cx);
    measure("C++/CX (undocumented)", array_input_cx_undocumented);
    measure("C++/WinRT", array_input);

    printf("\nCalling methods with collection input parameters (copy)\n");
    measure("C++/CX", collection_input_copy_cx);
    measure("C++/WinRT", collection_input_copy);
}
