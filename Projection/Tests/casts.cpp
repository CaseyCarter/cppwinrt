#include "pch.h"
#include "catch.hpp"

// These tests ensure that projected type hierarchies can cast between
// types correctly, even when a null is supplied

using namespace winrt;
using namespace Windows::UI::Composition;

// Test cast of null via bases
TEST_CASE("cast_null_via_bases")
{
    static_assert(std::is_base_of<impl::bases_one<ContainerVisual, Visual>, ContainerVisual>::value, "Type relationship violated");
    ContainerVisual derived(nullptr);
    const Visual& base = derived;
    REQUIRE(!base);
}

// Test cast of null via requires
TEST_CASE("cast_null_via_requires")
{
    static_assert(std::is_base_of<impl::require_one<ContainerVisual, IVisual>, ContainerVisual>::value, "Type relationship violated");
    ContainerVisual derived(nullptr);
    const IVisual& base = derived;
    REQUIRE(!base);
}