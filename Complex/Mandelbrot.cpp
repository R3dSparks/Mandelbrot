#include "Mandelbrot.h"



Mandelbrot::Mandelbrot(int width, int height, double scale, int iteration, int threshold)
{
	this->width_ = width;
	this->height_ = height;
	this->bitmap_ = Bitmap(width, height);
	this->mandelbrotlogic_ = MandelbrotLogic(width, height, scale, iteration, threshold);
}


Mandelbrot::~Mandelbrot()
{
}

void Mandelbrot::Calculate()
{
	for (int y = 0; y < this->height_; y++)
	{
		for (int x = 0; x < this->width_; x++)
		{
			if (this->mandelbrotlogic_.RunMandelbrotAlgorithm(x, y))
			{
				this->bitmap_.setPixelRGB(x, y, 0xffffff);
			}
			else
			{
				this->bitmap_.setPixelRGB(x, y, 0x000000);
			}
		}
	}
}

Bitmap Mandelbrot::GetBitmap()
{
	return this->bitmap_;
}
