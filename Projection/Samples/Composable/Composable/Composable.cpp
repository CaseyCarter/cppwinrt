#include "pch.h"

using namespace winrt;

int main()
{
    init_apartment();
    LoadLibrary(L"Composable.Base.dll");
    Composable::Base::Root obj;
    return 0;
}
