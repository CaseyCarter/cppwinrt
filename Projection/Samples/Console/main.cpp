// This is a simple smoke test that can be used with both Visual C++ and Clang.

#pragma comment(lib, "windowsapp")
#include "winrt/Windows.Foundation.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

struct __declspec(uuid("847bd694-79c7-5471-8391-050a10ea625f")) check_guid;

int main()
{
    init_apartment();
    Uri uri(L"https://moderncpp.com/windows-runtime/");
    assert(uri.Domain() == L"moderncpp.com");

    IVector<IReference<int>> values = single_threaded_vector<IReference<int>>({ 1,2 });
    assert(values.Size() == 2);
    assert(values.GetAt(0).Value() == 1);
    assert(values.GetAt(1).Value() == 2);

    std::wstring_view name = name_of<IVector<IReference<int>>>();
    assert(name == L"Windows.Foundation.Collections.IVector`1<Windows.Foundation.IReference`1<Int32>>");

    GUID guid = guid_of<IVector<IReference<int>>>();
    assert(guid == __uuidof(check_guid));

    event<EventHandler<hstring>> handlers;
    
    handlers.add([](IInspectable const&, hstring const& args)
    {
        printf("%ls\n", args.c_str());
    });

    handlers(nullptr, L"OK!\n");
}
