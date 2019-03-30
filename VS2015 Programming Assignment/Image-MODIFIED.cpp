#include "Image-MODIFIED.h"

const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

void Image::outputInfo(const char *filename)
{
	FsObj.open("Images/LogFile.txt");

	FsObj << filename << "\nImage Resolution: " << w << " x " << h << "\nColour Depth: 256 for R/G/B = 24 bit Colour\n" << "This is a blended Image.\n";

	FsObj.close();
}
