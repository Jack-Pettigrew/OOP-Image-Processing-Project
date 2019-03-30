#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "WriteRead.h"
#include "Image-MODIFIED.h"

using namespace std;

class imageMerge : public Image
{
public:
	void meanMerge(Image *img);
	void medianMerge(Image *img);
	void sigmaMerge(Image *img);
	
private:
	// WriteRead class object
	WriteRead wrObj;
};