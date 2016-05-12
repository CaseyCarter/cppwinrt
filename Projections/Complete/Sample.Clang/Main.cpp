
#include "winrt.h"

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    Initialize();

    Uri uri(L"http://host/path");

    printf("%ls\n", uri.ToString().c_str());
}
