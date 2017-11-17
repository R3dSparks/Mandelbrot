#include <iostream>
#include "BMP.h"
#include "MandelbrotLogic.h"
#include "Bitmap.h"

int main()
{
	int height = 7;
	int width = 7;
	int percentage = 0;
	int last_percentage = -1;

	MandelbrotLogic mbl = MandelbrotLogic(width, height, 0.001, 100, 1000);

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
		
		percentage = (int)((x / (double)width) * 100);

		if (percentage > last_percentage)
		{
			std::cout << percentage << "%" << std::endl;
			last_percentage = percentage;
		}
	}

	SaveBMP(bmp.get_image_data(), width, height, bmp.get_size(), "testBmp.bmp");

}
