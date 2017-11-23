#pragma once
#include "Bitmap.h"
#include "MandelbrotLogic.h"

class Mandelbrot
{
public:
	Mandelbrot(int, int, double, int, int);
	~Mandelbrot();

	void Calculate();
	Bitmap GetBitmap();

private:
	int height_;
	int width_;

	Bitmap bitmap_;
	MandelbrotLogic mandelbrotlogic_;

};

