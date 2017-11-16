#include <iostream>
#include "BMP.h"
#include "MandelbrotLogic.h"
#include "Bitmap.h"

int main()
{
	int height = 100*4;
	int width = 150*4;
	int size = height * width * 3;

	MandelbrotLogic mbl = MandelbrotLogic(width, height);

	Bitmap bmp = Bitmap(width, height);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
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


	SaveBMP(bmp.get_image_data(), width, height, size, "testBmp.bmp");

}
