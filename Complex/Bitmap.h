#pragma once
#include <Windows.h>

class Bitmap
{
public:
	Bitmap(int, int);
	~Bitmap();

	BYTE* get_image_data();
	int get_size();

	int getPixelRGB(int, int);
	void setPixelRGB(int, int, int);

private:
	int width_;
	int height_;
	int size_;
	BYTE* image_data_;

};

