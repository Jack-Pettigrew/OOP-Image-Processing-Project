#pragma once
#include <math.h>
#include "WriteRead.h"
#include "Image-MODIFIED.h"

class Zoom : public Image //class for scaling the Image with Inheritence
{
public:
	Zoom() {}
	Zoom(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);

	void twoTimesZoom(Image *img);
	void fourTimesZoom(Image *img);
	void outputInfo(const char *filename);

private:
	WriteRead wrObj;
};

