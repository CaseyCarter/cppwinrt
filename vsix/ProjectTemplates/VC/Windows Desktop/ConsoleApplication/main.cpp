// main.cpp : Defines the entry point for the console application.
//

#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

int main([[maybe_unused]] int argc, [[maybe_unused]] wchar_t** argv)
{
    init_apartment();
    Uri uri(L"https://github.com/microsoft/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}
