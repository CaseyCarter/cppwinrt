// This test simply ensures that each namespace header may be included in isolation and allows
// all its namespace types to be defined. It does not test members since those may require
// additional namespaces to be included.

#pragma comment(lib, "windowsapp")
#include "winrt/%.h"

using namespace winrt;

int main()
{
%}
