#include "pch.h"

using namespace winrt;

std::future<void> Sample()
{
    using namespace Windows::Foundation;
    using namespace Windows::Web::Syndication;

    Uri uri(L"http://kennykerr.ca/feed");
    SyndicationClient client;

    SyndicationFeed feed = await client.RetrieveFeedAsync(uri);

    for (SyndicationItem item : feed.Items())
    {
        hstring title = item.Title().Text();

        printf("%ls\n", title.c_str());
    }
}

int main()
{
    Initialize();

    Sample().get();
}
