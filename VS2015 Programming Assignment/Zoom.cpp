#include "Zoom.h"


Zoom::Zoom(const unsigned int & _w, const unsigned int & _h, const Rgb & c) :
	Image(_w, _h)
{
}

void Zoom::twoTimesZoom(Image *img)
{
	Image tempImage; //empty temp image

	//w1 and h1
	tempImage = wrObj.readPPM("Images/Zoom/zIMG_1.ppm"); //read in Zoom image

	float x = tempImage.w / (float)img->w; //original x / zoomed x
	float y = tempImage.h / (float)img->h; //original y / zoomed y
	float x2, y2;
	for (int i = 0; i < img->h; i++)
	{
		for (int j = 0; j < img->w; j++)
		{
			x2 = floor(j * x);
			y2 = floor(i * y);
			img->pixels[(i * img->w) + j] = tempImage[((y2*tempImage.w) + x2)];
		}
	}
}

void Zoom::fourTimesZoom(Image *img)
{
	Image tempImage; //empty temp image

	//w1 and h1
	tempImage = wrObj.readPPM("Images/Zoom/zIMG_1.ppm"); //read in Zoom image

	float x = tempImage.w / (float)img->w; //original x / zoomed x
	float y = tempImage.h / (float)img->h; //original y / zoomed y
	float x2, y2;
	for (int i = 0; i < img->h; i++)
	{
		for (int j = 0; j < img->w; j++)
		{
			x2 = floor(j * x);
			y2 = floor(i * y);
			img->pixels[(i * img->w) + j] = tempImage[((y2*tempImage.w) + x2)];
		}
	}
}

void Zoom::outputInfo(const char * filename)
{
	FsObj.open("Images/LogFile.txt");

	FsObj << filename << "\nImage Resolution: " << w << " x " << h << "\nColour Depth: 256 for R/G/B = 24 bit Colour\n" << "This is a Zoomed Image\n";

	FsObj.close();
}
