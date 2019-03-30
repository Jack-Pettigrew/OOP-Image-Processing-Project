#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Image-MODIFIED.h"

class WriteRead : public Image //WriteRead class - inheriting the Image class
{
public:
	Image readPPM(const char *filename);
	void writePPM(Image &img, const char *filename);

private:
	std::string header;
	int w, h, b;
};

