#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

int main()
{
    initialize();

    Uri uri(L"https://github.com/microsoft/cppwinrt");

    DisplayPropertiesEventHandler handler = [] (auto && sender)
    {
        printf("%ls\n", sender.as<IStringable>().ToString().c_str());
    };

    handler(uri);
}
