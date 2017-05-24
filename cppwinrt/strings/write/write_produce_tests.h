// This test focuses on producing interfaces.It defines an implementation of each interface with
// each method simply throwing an exception.It ensures that each produce specialization is
// instantiated.This requires a lot of memory to compile with Visual C++ and you must use the x64
// cross compiler and the following suggested compiler options:
//
//    cl /I .. /EHsc /bigobj /std:c++latest produce.cpp

#pragma comment(lib, "windowsapp")
%
using namespace winrt;
%
int main()
{
}
