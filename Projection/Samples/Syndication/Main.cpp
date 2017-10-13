#include "pch.h"

using namespace winrt;

using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

IAsyncAction Sample()
{
    Uri uri(L"http://kennykerr.ca/feed");
    SyndicationClient client;
    SyndicationFeed feed = co_await client.RetrieveFeedAsync(uri);

    for (SyndicationItem item : feed.Items())
    {
        hstring title = item.Title().Text();

        printf("%ls\n", title.c_str());
    }
}

void print_diagnostics_info()
{
#ifdef WINRT_DIAGNOSTICS
    auto info = get_diagnostics_info();

    printf("\nFactories:\n");

    for (auto&&[name, info] : info.factories)
    {
        printf("%4d %.*ls", info.requests, static_cast<int>(name.size()), name.data());

        if (!info.is_agile)
        {
            printf(" [Warning non-agile factory]");
        }

        printf("\n");
    }

    printf("Queries:\n");

    for (auto&&[name, count] : info.queries)
    {
        printf("%4d %.*ls\n", count, static_cast<int>(name.size()), name.data());
    }
#endif
}

int main()
{
    init_apartment();

    Sample().get();

    print_diagnostics_info();
}
