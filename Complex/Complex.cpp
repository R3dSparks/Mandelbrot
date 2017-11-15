#include "Complex.h"

Complex::Complex()
{
	
}

Complex::Complex(double real, double imaginary)
{
	this->real_ = real;
	this->imaginary_ = imaginary;
}

Complex::~Complex()
{
}

// Getter Setter

double Complex::get_real() const
{
	return this->real_;
}

double Complex::get_imaginary() const
{
	return this->imaginary_;
}

void Complex::set_real(double real)
{
	this->real_ = real;
}

void Complex::set_imaginary(double imaginary)
{
	this->imaginary_ = imaginary;
}

// Operator

Complex operator+(const Complex &a, const Complex &b)
{
	return Complex(a.get_real() + b.get_real(), a.get_imaginary() + b.get_imaginary());
}

Complex operator+(double a, const Complex &b)
{
	return Complex(a + b.get_real(), b.get_imaginary());
}

Complex operator+(const Complex &a, double b)
{
	return Complex(a.get_real() + b, a.get_imaginary());
}

Complex operator-(const Complex &a, const Complex &b)
{
	return Complex(a.get_real() - b.get_real(), a.get_imaginary() - b.get_imaginary());
}

Complex operator*(const Complex &a, const Complex &b)
{
	double real = a.get_real() * b.get_real() - a.get_imaginary() * b.get_imaginary();
	double imaginary = a.get_imaginary() * b.get_real() + a.get_real() * b.get_imaginary();

	return Complex(real, imaginary);
}

Complex operator/(const Complex &a, const Complex &b)
{
	double real = (a.get_real() * b.get_real() + a.get_imaginary() * b.get_imaginary())
		/ (a.get_imaginary() * a.get_imaginary() + b.get_imaginary() * b.get_imaginary());
	double imaginary = (a.get_imaginary * b.get_real() - a.get_real() * b.get_imaginary())
		/ (a.get_imaginary() * a.get_imaginary() + b.get_imaginary() * b.get_imaginary());

	return Complex(real, imaginary);
}
