#pragma once
//*********************************************
//Image class to hold and allow manipulation of images once read into the code
//from https://www.scratchapixel.com/
//*********************************************
#include <iostream>
#include <cstdlib> 
#include <cstdio>
#include <fstream>

class Image
{
public:
	// Rgb structure, i.e. a pixel 
	struct Rgb
	{
		//constructors
		Rgb() : r(0), g(0), b(0) {}//black
		Rgb(float c) : r(c), g(c), b(c) {} //grey
		Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {} //coloured

		//member functions
		bool operator != (const Rgb &c) const
		{
			return c.r != r || c.g != g || c.b != b;
		}

		Rgb& operator *= (const Rgb &rgb)
		{
			r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
		}

		Rgb& operator += (const Rgb &rgb)
		{
			r += rgb.r, g += rgb.g, b += rgb.b; return *this;
		}

		friend float& operator += (float &f, const Rgb rgb)
		{
			f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
		}

		//member variables
		float r, g, b;
	};

	//Image Class Constructors
	Image() : w(0), h(0), pixels(nullptr) { /* empty image */ }
	Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack) :
		w(_w), h(_h), pixels(NULL)
	{
		pixels = new Rgb[w * h];
		for (int i = 0; i < w * h; ++i)
			pixels[i] = c;
	}

	//Image Class copy constructor
	Image(const Image &im)
	{
		w = im.w;
		h = im.h;
		pixels = new Rgb[im.w * im.h];
		for (int i = 0; i < im.w * im.h; ++i)
			pixels[i] = im.pixels[i];
	}

	//Image Class copy assignment operator
	Image& operator=(const Image& other)
	{
		w = other.w;
		h = other.h;
		pixels = new Rgb[other.w * other.h];
		for (int i = 0; i < other.w * other.h; ++i)
			pixels[i] = other.pixels[i];

		return *this;

	}

	const Rgb& operator [] (const unsigned int &i) const
	{
		return pixels[i];
	}

	Rgb& operator [] (const unsigned int &i)
	{
		return pixels[i];
	}

	//Image Class deconstructor
	~Image()
	{
		if (pixels != NULL) delete[] pixels;
		//delete[] pixels;
	}

	virtual void outputInfo(const char *filename);
	virtual void twoTimesZoom(Image *img) {}
	virtual void fourTimesZoom(Image *img) {}

	std::ofstream FsObj; //file output object

	int w, h; //unsigned int w, h - Image resolution 
	Rgb *pixels; // 1D array of pixels in image
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors values
};