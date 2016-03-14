#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    Initialize();

    Uri uri(L"http://host/path");

    printf("%ls\n", uri.Path().Buffer());
}
