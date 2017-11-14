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

    return Catch::Session().run(argc, argv);
}
