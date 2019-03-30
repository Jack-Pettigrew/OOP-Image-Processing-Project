//Jack Pettigrew - 15593452
//UoL - 2017 - 2018
//Object Oriented Programming: Assignment

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Image-MODIFIED.h"
#include "imageMerge.h"
#include "WriteRead.h"
#include "Zoom.h"

using namespace std;

int main(int argc, char *argv)
{
	//global objects
	WriteRead *rwObj = new WriteRead();
	imageMerge *merger = new imageMerge();

	cout << "************************************" << endl;
	cout << "Image Stacker / Image Scaler" << endl;
	cout << "************************************" << endl;

	//exit case bool
	bool running = true;

	// Global Polymorphism Objects (Images that point to their desired product)
	Image *img = new Image(3264, 2448); // creates 'img' object with resolution arguments
	Image *zoomImgTwo = new Zoom(1500, 1500); // new image object to hold x2 image
	Image *zoomImgFour = new Zoom(3000, 3000); // new image object to hold x4 image	

	//goto keyword for default case
	restart:
	cout << "\nWhich form of blending would you like to perform?" << endl;
	cout << "1. Mean Blending\n2. Median Blending\n3. Sigma Blending\n4. Zoom x2\n5. Zoom x4\n6. Exit" << endl;

	//menu variable switch
	char menuInput;
	cin >> menuInput;

	switch (menuInput)
	{
		case '1':
			cout << "Starting Mean Blending..." << endl;
			
			merger->meanMerge(img); //performs merger->meanMerge on 'img'

			rwObj->writePPM(*img, "Images/ImageStacker_set1/meanBlendedImage.ppm"); //Output the image data to a file for viewing

			img->outputInfo("Images/ImageStacker_set1/meanBlendedImage.ppm");

			break;
		case '2':
			cout << "Starting Median Blending..." << endl;
			merger->medianMerge(img); //performs merger->meanMerge on 'img'

			rwObj->writePPM(*img, "Images/ImageStacker_set1/medianBlendedImage.ppm"); //Output the image data to a file for viewing

			img->outputInfo("Images/ImageStacker_set1/medianBlendedImage.ppm");
			
			break;
		case '3':
			cout << "Starting Sigma Clip..." << endl;

			merger->sigmaMerge(img);

			rwObj->writePPM(*img, "Images/ImageStacker_set1/sigmaClipImage.ppm");

			img->outputInfo("Images/ImageStacker_set1/sigmaClipImage.ppm");

			break;
		case '4':
			cout << "Scaling Image by x2..." << endl;

			zoomImgTwo->twoTimesZoom(zoomImgTwo); // Polymorphism Image - Zoom Object

			rwObj->writePPM(*zoomImgTwo, "Images/Zoom/scaledImagex2.ppm");

			zoomImgTwo->outputInfo("Images/Zoom/scaledImagex2.ppm"); // Polymorphism Image - Output Function

			break;
		case '5':
			cout << "Scaling Image by x4..." << endl;

			zoomImgFour->fourTimesZoom(zoomImgFour);

			rwObj->writePPM(*zoomImgFour, "Images/Zoom/scaledImagex4.ppm");

			zoomImgFour->outputInfo("Images/Zoom/scaledImagex4.ppm");

			break;
		case '6':
			running = false;
			break;
		default:
			cout << "Please enter a valid input." << endl;

			goto  restart;
	}

	cout << "Closing Application..." << endl;

	delete img, rwObj, merger, zoomImgTwo, zoomImgFour;
	img = NULL; rwObj = NULL; merger = NULL; ; zoomImgTwo = NULL; zoomImgFour = NULL;

	return 0;
}
