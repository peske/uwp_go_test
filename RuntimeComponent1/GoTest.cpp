#include "pch.h"
#include "GoTest.h"

namespace winrt::RuntimeComponent1::implementation
{
    int32_t GoTest::GoTestFunction(int32_t a)
    {
		static goTestFunctionExt goTestFunction{ NULL };

		if (goTestFunction == NULL)
		{
			// Initializing Go function pointer

			HMODULE goModule = LoadPackagedLibrary(L"test.dll", 0);

			if (goModule == NULL)
			{
				DWORD err = GetLastError();

				return static_cast<int>(err);
			}

			goTestFunction = (goTestFunctionExt) GetProcAddress(goModule, "goTestFunction");

			if (goTestFunction == NULL)
			{
				DWORD err = GetLastError();

				return static_cast<int>(err);
			}
		}
		
		return goTestFunction(a);
    }
}
