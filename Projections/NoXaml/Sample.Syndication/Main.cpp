#include "pch.h"

using namespace std;
using namespace winrt;

using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Web::Syndication;

std::future<void> Sample()
{
    Uri uri(L"http://kennykerr.ca/feed");
    SyndicationClient client;

    SyndicationFeed feed = await client.RetrieveFeedAsync(uri);

    for (SyndicationItem item : feed.Items())
    {
        String title = item.Title().Text();

        printf("%ls\n", title.Buffer());
    }
}

int main()
{
    Initialize();

    Sample().get();
}
