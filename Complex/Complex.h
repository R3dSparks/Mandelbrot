#pragma once
#include <math.h>

class Complex
{
public:
	// Constructor

	Complex();
	Complex(double, double);
	~Complex();

	// Getter Setter

	double get_real() const;
	double get_imaginary() const;

	void set_real(double);
	void set_imaginary(double);

	// Methods

	double getLength() const;

private:
	// Properties

	double real_;
	double imaginary_;

	// Methods

};

// Operator

Complex operator+(const Complex&, const Complex&);
Complex operator+(double, const Complex&);
Complex operator+(const Complex&, double);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
