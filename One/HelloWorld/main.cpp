#include <Windows.h>
int main()
{
	double(__cdecl *kigDoubleAddition) (double, double);
	HINSTANCE hDLL;
	FARPROC pcci;
	//MyAdd Add;
	double uReturnVal;
	LPCWSTR file = L"HelloWorldDll";

	hDLL = LoadLibrary(file);
	if (hDLL != NULL)
	{
		//Add = (MyAdd)GetProcAddress(hDLL, "Subtract");
		pcci = GetProcAddress(hDLL, "kigDoubleAddition");
		if (!pcci)
		{
			FreeLibrary(hDLL);
			return E_UNEXPECTED;
		}
		else
		{
			double a = 2.0;
			double b = 3.0;
			kigDoubleAddition = (double(__cdecl *)(double, double)) pcci;
			uReturnVal = kigDoubleAddition(2.0, 3.0);
			if (uReturnVal == a + b)
			{
				return ERROR_SUCCESS;
			}
			else { return ERROR_UNIDENTIFIED_ERROR; }
		}
	}
      	return 0;
}