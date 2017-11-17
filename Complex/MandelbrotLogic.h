#pragma once
#include "Complex.h"

class MandelbrotLogic
{
public:
	// Constructor

	MandelbrotLogic(int, int, double, int, int);
	~MandelbrotLogic();

	// Properties

	// Methods

	int GetRGB(int value, int max_value);

	int IsNumInsideMandelbrotSet(const Complex);

	int RunMandelbrotAlgorithm(int, int);

private:

	double scaling_ = 0.005;
	double origin_x_ = 0.5;
	double origin_y_ = 0;
	int total_pixel_width_;
	int total_pixel_height_;

	int divergence_threshhold_ = 500;
	int max_iterations_ = 200;

};

