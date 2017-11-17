#include "Bitmap.h"



Bitmap::Bitmap(int width, int height)
{
	this->width_ = width;
	this->height_ = height;
	this->size_ = width * height * 3; // Number of pixels times 3 byte per pixel
	this->size_ = this->size_ + 4 - this->size_ % 4;
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

	BYTE* pixel_data = (this->image_data_) + (x + y * this->width_) * 3;

	int red = *pixel_data;
	int green = *(pixel_data + 1);
	int blue = *(pixel_data + 2);

	return blue | green << 8 | red << 16;
}

void Bitmap::setPixelRGB(int x , int y, int rgb)
{
	if (x >= this->width_ || y >= this->height_)
		return;

	BYTE* pixel_data = (this->image_data_) + (x + y * this->width_) * 3;

	*pixel_data = rgb & 0x0000ff;
	*(pixel_data + 1) = (rgb & 0x00ff00) >> 8;
	*(pixel_data + 2) = (rgb & 0xff0000) >> 16;
}
