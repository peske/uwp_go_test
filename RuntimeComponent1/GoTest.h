#pragma once

#include "GoTest.g.h"

namespace winrt::RuntimeComponent1::implementation
{
    struct GoTest : GoTestT<GoTest>
    {
		GoTest() = default;

		typedef int(*goTestFunctionExt)(int a);
        int32_t GoTestFunction(int32_t a);
    };
}

namespace winrt::RuntimeComponent1::factory_implementation
{
    struct GoTest : GoTestT<GoTest, implementation::GoTest>
    {
    };
}
