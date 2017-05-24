// This test focuses on consuming interface members. It instantiates each interface and class and
// calls each method and includes all required interfaces. Thus, it requires a lot of memory to
// compile with Visual C++ and you must use the x64 cross compiler and the following suggested
// compiler options:
//
//    cl /I .. /EHsc /bigobj /std:c++latest consume.cpp

#pragma comment(lib, "windowsapp")
%
using namespace winrt;

template <typename T>
T arg()
{
    throw hresult_not_implemented();
}

%
int main()
{
}
