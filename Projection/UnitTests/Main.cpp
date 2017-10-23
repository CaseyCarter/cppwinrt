#include "pch.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char * argv[])
{
    winrt::init_apartment();

    std::set_terminate([]{ ExitProcess(1); });
    return Catch::Session().run(argc, argv);
}
