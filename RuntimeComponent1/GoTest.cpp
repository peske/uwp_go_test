#include "pch.h"
#include "GoTest.h"

namespace winrt::RuntimeComponent1::implementation
{
    int32_t GoTest::GoTestFunction(int32_t a)
    {
		HMODULE goModule = LoadPackagedLibrary(L"test.dll", 0);

		if (goModule == NULL)
		{
			DWORD err = GetLastError();

			return static_cast<int>(err);
		}

		goTestFunctionExt goTestFunction = (goTestFunctionExt)GetProcAddress(goModule, "goTestFunction");

		if (goTestFunction == NULL)
		{
			DWORD err = GetLastError();

			return static_cast<int>(err);
		}

		int result = goTestFunction(a);

		//FreeLibrary(goModule);

		return result;
    }
}
