#include <iostream>
#include <Windows.h>

#include "BMP.h"
#include "MandelbrotLogic.h"
#include "Bitmap.h"

DWORD WINAPI mblThread(LPVOID param)
{
	int height = *((int*)param);
	int width = *((int*)param + 1);

	Bitmap bmp = *((Bitmap*)param + 2);
	MandelbrotLogic mbl = *((MandelbrotLogic*)param + 3);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (mbl.RunMandelbrotAlgorithm(x, y) == false)
			{
				bmp.setPixelRGB(x, y, 0x000000);
			}
			else
			{
				bmp.setPixelRGB(x, y, 0xffffff);
			}
		}
	}

	return 0;
}

int main()
{
	int height = 600;
	int width = 800;
	int percentage = 0;
	int last_percentage = -1;

	MandelbrotLogic mbl = MandelbrotLogic(width, height, 1, 500, 1000);

	Bitmap bmp = Bitmap(width, height);

	LPVOID params = malloc(2 * sizeof(int) + sizeof(&bmp) + sizeof(&mbl));

	*((int*)params) = height;
	*((int*)params + 1) = width;
	*((Bitmap*)params + 2) = bmp;
	*((MandelbrotLogic*)params + 3) = mbl;


	DWORD threadId;

	HANDLE thread = CreateThread(0, 0, &mblThread, params, 0, &threadId);

	std::cout << "Started thread" << std::endl;

	WaitForSingleObject(thread, INFINITE);

	std::cout << "Finished thread" << std::endl;

	CloseHandle(thread);

	SaveBMP(bmp.get_image_data(), width, height, bmp.get_size(), "testBmp.bmp");

}
