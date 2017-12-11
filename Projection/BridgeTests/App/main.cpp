#include "pch.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

using namespace winrt;

int main(int argc, char * argv[])
{
    std::set_terminate([] { ExitProcess(1); });
    winrt::init_apartment();

    try
    {
        Component::Parameters params;
    }
    catch (hresult_error const& e)
    {
        printf("Tests must be run from the packaging project. 0x%8X\n", e.code());
        return 1;
    }

    int const result = Catch::Session().run(argc, argv);

    // Completely unnecessary in an app, but useful for testing DllCanUnloadNow behavior.
    // If all goes well, the get_module_lock() value should be zero and the DllCanUnloadNow
    // implementation should return S_OK.
    //
    // Normally, we can simply tear down the MTA, which causes the CoreApplication to be
    // torn down as well as any static_lifetime factories. That however prevents us from
    // testing DllCanUnloadNow since it will never be called. Instead, we forcefully clear
    // out the CoreApplication cache to release any static_lifetime factories so that we 
    // can check that DllCanUnloadNow is behaving properly.

    param::hstring classId{ L"Windows.ApplicationModel.Core.CoreApplication" };
    com_ptr<impl::IStaticLifetime> factory;
    check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), guid_of<impl::IStaticLifetime>(), factory.put_void()));
    Windows::Foundation::IUnknown collection;
    check_hresult(factory->GetCollection(put_abi(collection)));
    auto map = collection.as<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>>();
    map.Clear();

    clear_factory_cache();
    CoFreeUnusedLibrariesEx(0, 0);

    // The app container tears down the console immediately so this just gives you a moment
    // to visually check the green status of the tests during debugging and before it disappears.

    Sleep(1000);
    return result;
}
