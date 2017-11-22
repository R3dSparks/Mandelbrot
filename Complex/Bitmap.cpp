#include "Bitmap.h"



Bitmap::Bitmap(int width, int height)
{
	this->width_ = width;
	this->height_ = height;

	this->padded_width_ = width * 3 + (4 - ((width * 3) % 4)) % 4;
	this->size_ = this->height_ * this->padded_width_;
	this->image_data_ = (BYTE*)malloc(this->size_);
}


Bitmap::~Bitmap()
{
	free(this->image_data_);
}

BYTE * Bitmap::get_image_data()
{
	return this->image_data_;
}

int Bitmap::get_size()
{
	return this->size_;
}

int Bitmap::getPixelRGB(int x, int y)
{
	if (x >= this->width_ || y >= this->height_)
		return 0;

	BYTE* pixel_data = get_pixel(x, y);

	int red = *pixel_data;
	int green = *(pixel_data + 1);
	int blue = *(pixel_data + 2);

	return blue | green << 8 | red << 16;
}

void Bitmap::setPixelRGB(int x , int y, int rgb)
{
	if (x >= this->width_ || y >= this->height_)
		return;

	BYTE* pixel_data = get_pixel(x, y);

	*pixel_data = rgb & 0x0000ff;
	*(pixel_data + 1) = (rgb & 0x00ff00) >> 8;
	*(pixel_data + 2) = (rgb & 0xff0000) >> 16;
}

BYTE* Bitmap::get_pixel(int x, int y)
{
	BYTE* pixel_ptr = this->image_data_;

	// Add complete padded row bytes to the prt
	pixel_ptr += y * this->padded_width_;

	// Add bytes from the current row to the prt
	pixel_ptr += x * 3;

	return pixel_ptr;
}
