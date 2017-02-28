#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

int main()
{
    init_apartment();

    Uri uri(L"https://github.com/microsoft/cppwinrt");

    DisplayPropertiesEventHandler handler = [] (auto && sender)
    {
        printf("%ls\n", sender.as<IStringable>().ToString().c_str());
    };

    handler(uri);
}
