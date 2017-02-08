struct IUnknown;

#pragma comment(lib, "windowsapp") 

#include "winrt\Windows.Foundation.h"

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();

    Uri uri(L"http://host/path");

    printf("%ls\n", uri.ToString().c_str());
}
