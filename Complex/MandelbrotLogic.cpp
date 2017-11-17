#include "MandelbrotLogic.h"



MandelbrotLogic::MandelbrotLogic(int width, int height, double scale, int iterations, int threshold)
{
	this->total_pixel_width_ = width;
	this->total_pixel_height_ = height;
	this->scaling_ = scale;
	this->max_iterations_ = iterations;
	this->divergence_threshhold_ = threshold;
}


MandelbrotLogic::~MandelbrotLogic()
{
}

int MandelbrotLogic::GetRGB(int value, int max_value)
{
	return 0;
}

int MandelbrotLogic::IsNumInsideMandelbrotSet(const Complex c)
{
	Complex z = Complex(0, 0);

	for (int i = 0; i < this->max_iterations_; i++)
	{
		if (z.getLength() > this->divergence_threshhold_)
			return i;

		z = z * z + c;
	}

	return 0;
}

int MandelbrotLogic::RunMandelbrotAlgorithm(int pixel_x, int pixel_y)
{
	double real = (pixel_x - this->total_pixel_width_ / 2) * this->scaling_ - this->origin_x_;
	double imaginary = (pixel_y - this->total_pixel_height_ / 2) * this->scaling_ - this->origin_y_;

	Complex c = Complex(real, imaginary);

	return IsNumInsideMandelbrotSet(c);
}
