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

    // The app container tears down the console immediately so this just gives you a moment
    // to visually check the green status of the tests during debugging and before it disappears.
    Sleep(1000);
    return result;
}
