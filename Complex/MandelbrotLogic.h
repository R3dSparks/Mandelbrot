#pragma once
#include "Complex.h"

class MandelbrotLogic
{
public:
	// Constructor

	MandelbrotLogic();
	~MandelbrotLogic();

	// Properties

	// Methods

	int IsPixelInsideMandelbrotSet(Complex);

	void RunMandelbrotAlgorithm(int x, int y);

private:

	double scaling_;
	double origin_x_;
	double origin_y_;

};

