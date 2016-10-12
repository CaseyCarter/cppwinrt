#include "pch.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char * argv[])
{
    winrt::initialize();

    return Catch::Session().run(argc, argv);
}
