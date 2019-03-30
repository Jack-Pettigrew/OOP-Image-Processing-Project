#include "imageMerge.h"

//merging images through finding the mean of pixel values
void imageMerge::meanMerge(Image* img)
{
	Image tempImage; //an empty image object named 'tempImage'

	//loop through each image...
	for (int i = 0; i < 13; i++)
	{
		//...get current image - assign it to empty 'tempImage' object
		if (i == 0)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_1.ppm");
		else if (i == 1)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_2.ppm");
		else if (i == 2)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_3.ppm");
		else if (i == 3)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_4.ppm");
		else if (i == 4)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_5.ppm");
		else if (i == 5)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_6.ppm");
		else if (i == 6)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_7.ppm");
		else if (i == 7)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_8.ppm");
		else if (i == 8)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_9.ppm");
		else if (i == 9)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_10.ppm");
		else if (i == 10)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_11.ppm");
		else if (i == 11)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_12.ppm");
		else if (i == 12)
			tempImage = wrObj.readPPM("Images/ImageStacker_set1/IMG_13.ppm");

		//FOR loop going through the pixels (img->w * img->h)
		for (int i = 0; i < img->w * img->h; i++)
		{
			img->pixels[i].r += tempImage.pixels[i].r;
			img->pixels[i].g += tempImage.pixels[i].g;
			img->pixels[i].b += tempImage.pixels[i].b;
			//each pixel (and it's R, G, B values) in 'tempImage' is added and assigned to 'img's pixel array (and corresponding R, G, B values
		}
		//Repeats FOR loop for all of the 13 images

	}

	//FOR loop going through 'img's new R, G, B values...
	for (int i = 0; i < img->w * img->h; i++)
	{
		//and finds the mean of each (img->pixels[i].r/g/b /= 13)
		img->pixels[i].r /= 13;
		img->pixels[i].g /= 13;
		img->pixels[i].b /= 13;
	}
}

//merging images through finding the median of pixel values
void imageMerge::medianMerge(Image* img)
{
	//load in each image into Objects
	Image img1 = wrObj.readPPM("Images/ImageStacker_set1/IMG_1.ppm");
	Image img2 = wrObj.readPPM("Images/ImageStacker_set1/IMG_2.ppm");
	Image img3 = wrObj.readPPM("Images/ImageStacker_set1/IMG_3.ppm");
	Image img4 = wrObj.readPPM("Images/ImageStacker_set1/IMG_4.ppm");
	Image img5 = wrObj.readPPM("Images/ImageStacker_set1/IMG_5.ppm");
	Image img6 = wrObj.readPPM("Images/ImageStacker_set1/IMG_6.ppm");
	Image img7 = wrObj.readPPM("Images/ImageStacker_set1/IMG_7.ppm");
	Image img8 = wrObj.readPPM("Images/ImageStacker_set1/IMG_8.ppm");
	Image img9 = wrObj.readPPM("Images/ImageStacker_set1/IMG_9.ppm");
	Image img10 = wrObj.readPPM("Images/ImageStacker_set1/IMG_10.ppm");
	Image img11 = wrObj.readPPM("Images/ImageStacker_set1/IMG_11.ppm");
	Image img12 = wrObj.readPPM("Images/ImageStacker_set1/IMG_12.ppm");
	Image img13 = wrObj.readPPM("Images/ImageStacker_set1/IMG_13.ppm");

	cout << "\nProcessing. Please Wait..." << endl;

	//FOR LOOP adding pixel colour values to colour vectors for sorting
	for (int i = 0; i < img->w * img->h; i++)
	{
		//create a vector specific to each pixel (img->w * img->h)
		vector<float> rValue;
		vector<float> bValue;
		vector<float> gValue;

		//R vector 'push_back'
		rValue.push_back(img1.pixels[i].r);
		rValue.push_back(img2.pixels[i].r);
		rValue.push_back(img3.pixels[i].r);
		rValue.push_back(img4.pixels[i].r);
		rValue.push_back(img5.pixels[i].r);
		rValue.push_back(img6.pixels[i].r);
		rValue.push_back(img7.pixels[i].r);
		rValue.push_back(img8.pixels[i].r);
		rValue.push_back(img9.pixels[i].r);
		rValue.push_back(img10.pixels[i].r);
		rValue.push_back(img11.pixels[i].r);
		rValue.push_back(img12.pixels[i].r);
		rValue.push_back(img13.pixels[i].r);
		
		sort(rValue.begin(), rValue.end()); //sorting each pixel's own colour value vector 
		img->pixels[i].r = rValue[6]; //assigning original image to the newly sorted colour value vector median

		//B vector 'push_back'
		bValue.push_back(img1.pixels[i].b);
		bValue.push_back(img2.pixels[i].b);
		bValue.push_back(img3.pixels[i].b);
		bValue.push_back(img4.pixels[i].b);
		bValue.push_back(img5.pixels[i].b);
		bValue.push_back(img6.pixels[i].b);
		bValue.push_back(img7.pixels[i].b);
		bValue.push_back(img8.pixels[i].b);
		bValue.push_back(img9.pixels[i].b);
		bValue.push_back(img10.pixels[i].b);
		bValue.push_back(img11.pixels[i].b);
		bValue.push_back(img12.pixels[i].b);
		bValue.push_back(img13.pixels[i].b);

		sort(bValue.begin(), bValue.end());
		img->pixels[i].b = bValue[6];

		//G vector 'push_back'
		gValue.push_back(img1.pixels[i].g);
		gValue.push_back(img2.pixels[i].g);
		gValue.push_back(img3.pixels[i].g);
		gValue.push_back(img4.pixels[i].g);
		gValue.push_back(img5.pixels[i].g);
		gValue.push_back(img6.pixels[i].g);
		gValue.push_back(img7.pixels[i].g);
		gValue.push_back(img8.pixels[i].g);
		gValue.push_back(img9.pixels[i].g);
		gValue.push_back(img10.pixels[i].g);
		gValue.push_back(img11.pixels[i].g);
		gValue.push_back(img12.pixels[i].g);
		gValue.push_back(img13.pixels[i].g);

		sort(gValue.begin(), gValue.end());
		img->pixels[i].g = gValue[6];
	}
}

//merging images through finding the funk of pixel values
void imageMerge::sigmaMerge(Image* img)
{
	//storing original values into own objs
	Image temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12, temp13;

	temp1 = wrObj.readPPM("Images/ImageStacker_set1/IMG_1.ppm");
	temp2 = wrObj.readPPM("Images/ImageStacker_set1/IMG_2.ppm");
	temp3 = wrObj.readPPM("Images/ImageStacker_set1/IMG_3.ppm");
	temp4 = wrObj.readPPM("Images/ImageStacker_set1/IMG_4.ppm");
	temp5 = wrObj.readPPM("Images/ImageStacker_set1/IMG_5.ppm");
	temp6 = wrObj.readPPM("Images/ImageStacker_set1/IMG_6.ppm");
	temp7 = wrObj.readPPM("Images/ImageStacker_set1/IMG_7.ppm");
	temp8 = wrObj.readPPM("Images/ImageStacker_set1/IMG_8.ppm");
	temp9 = wrObj.readPPM("Images/ImageStacker_set1/IMG_9.ppm");
	temp10 = wrObj.readPPM("Images/ImageStacker_set1/IMG_10.ppm");
	temp11 = wrObj.readPPM("Images/ImageStacker_set1/IMG_11.ppm");
	temp12 = wrObj.readPPM("Images/ImageStacker_set1/IMG_12.ppm");
	temp13 = wrObj.readPPM("Images/ImageStacker_set1/IMG_13.ppm");
	
	cout << "Processing, Please wait..." << endl;

	//for each iteration of this loop...
	for (int i = 0; i < (img->w * img->h); i++)
	{
		//these vectors hold the object's pixel[i].r/g/b value
		vector<float> vectorR;
		vector<float> vectorG;
		vector<float> vectorB;
		//^ elements overwritten each iteration (instead of continuous adding via push_back for each pixel)

		//add R value to corresponding vector
		vectorR.push_back(temp1.pixels[i].r);
		vectorR.push_back(temp2.pixels[i].r);
		vectorR.push_back(temp3.pixels[i].r);
		vectorR.push_back(temp4.pixels[i].r);
		vectorR.push_back(temp5.pixels[i].r);
		vectorR.push_back(temp6.pixels[i].r);
		vectorR.push_back(temp7.pixels[i].r);
		vectorR.push_back(temp8.pixels[i].r);
		vectorR.push_back(temp9.pixels[i].r);
		vectorR.push_back(temp10.pixels[i].r);
		vectorR.push_back(temp11.pixels[i].r);
		vectorR.push_back(temp12.pixels[i].r);
		vectorR.push_back(temp13.pixels[i].r);

		//add G value to corresponding vector
		vectorG.push_back(temp1.pixels[i].g);
		vectorG.push_back(temp2.pixels[i].g);
		vectorG.push_back(temp3.pixels[i].g);
		vectorG.push_back(temp4.pixels[i].g);
		vectorG.push_back(temp5.pixels[i].g);
		vectorG.push_back(temp6.pixels[i].g);
		vectorG.push_back(temp7.pixels[i].g);
		vectorG.push_back(temp8.pixels[i].g);
		vectorG.push_back(temp9.pixels[i].g);
		vectorG.push_back(temp10.pixels[i].g);
		vectorG.push_back(temp11.pixels[i].g);
		vectorG.push_back(temp12.pixels[i].g);
		vectorG.push_back(temp13.pixels[i].g);

		//add B value to corresponding vector
		vectorB.push_back(temp1.pixels[i].b);
		vectorB.push_back(temp2.pixels[i].b);
		vectorB.push_back(temp3.pixels[i].b);
		vectorB.push_back(temp4.pixels[i].b);
		vectorB.push_back(temp5.pixels[i].b);
		vectorB.push_back(temp6.pixels[i].b);
		vectorB.push_back(temp7.pixels[i].b);
		vectorB.push_back(temp8.pixels[i].b);
		vectorB.push_back(temp9.pixels[i].b);
		vectorB.push_back(temp10.pixels[i].b);
		vectorB.push_back(temp11.pixels[i].b);
		vectorB.push_back(temp12.pixels[i].b);
		vectorB.push_back(temp13.pixels[i].b);

		//floats to hold the total of the R, G, B in the vectors (overwritten each iteration for each pixel)
		float totsR = 0;
		float totsG = 0;
		float totsB = 0;

		//assigning the tots values from each vector element
		for (int i = 0; i < 13; i++)
		{
			totsR += vectorR[i];
			totsG += vectorG[i];
			totsB += vectorB[i];
		}

		//floats to hold the mean values of R, G, B (overwritten each iteration for each pixel)
		float meanR = 0;
		float meanG = 0;
		float meanB = 0;

		//find and assign mean of tots values to meanR/G/B
		meanR = totsR / 13;
		meanG = totsG / 13;
		meanB = totsB / 13;

		//floats to store total Squared deviation of R, G, B (overwritten each iteration)
		float SQdeviationTotsR = 0;
		float SQdeviationTotsG = 0;
		float SQdeviationTotsB = 0;

		//for each of the 13 images -> calculate the total deviation for R, G, B
		for (int i = 0; i < 13; i++)
		{
			SQdeviationTotsR += ((vectorR[i] - meanR) * (vectorR[i] - meanR));
			SQdeviationTotsG += ((vectorG[i] - meanG) * (vectorG[i] - meanG));
			SQdeviationTotsB += ((vectorB[i] - meanB) * (vectorB[i] - meanB));
		}

		//finding the mean of deviations -> then Square Rooting
		SQdeviationTotsR = SQdeviationTotsR / 13;
		SQdeviationTotsR = sqrt(SQdeviationTotsR);

		SQdeviationTotsG = SQdeviationTotsG / 13;
		SQdeviationTotsG = sqrt(SQdeviationTotsG);

		SQdeviationTotsB = SQdeviationTotsB / 13;
		SQdeviationTotsB = sqrt(SQdeviationTotsB);

		//defining min and max values for R, G, and B
		float minSdR = 0, maxSdR = 0, minSdG = 0, maxSdG = 0,
			minSdB = 0, maxSdB = 0;

		float sigma = 1;

		//getting the min and max values of each R, G, B value
		minSdR = meanR - (sigma * SQdeviationTotsR);
		maxSdR = meanR + (sigma * SQdeviationTotsR);
		minSdG = meanG - (sigma * SQdeviationTotsG);
		maxSdG = meanG + (sigma * SQdeviationTotsG);
		minSdB = meanB - (sigma * SQdeviationTotsB);
		maxSdB = meanB + (sigma * SQdeviationTotsB);

		//vectors to store sigma values within range
		vector<float> sigmaR;
		vector<float> sigmaG;
		vector<float> sigmaB;

		for (int i = 0; i < 13; i++)
		{
			if (vectorR[i] > minSdR && vectorR[i] < maxSdR)
			{
				sigmaR.push_back(vectorR[i]);
			}
			if (vectorG[i] > minSdG && vectorG[i] < maxSdG)
			{
				sigmaG.push_back(vectorG[i]);
			}
			if (vectorB[i] > minSdB && vectorB[i] < maxSdG)
			{
				sigmaB.push_back(vectorB[i]);
			}
		}

		//floats to store the sum of each vector for the AVERAGE
		float sigmaSumR = 0, sigmaSumG = 0, sigmaSumB = 0;

		//FOR loop storing the sum of vector to corresponding float above
		for (int i = 0; i < sigmaR.size(); i++)
		{
			sigmaSumR += sigmaR[i];
		}
		for (int i = 0; i < sigmaG.size(); i++)
		{
			sigmaSumG += sigmaG[i];
		}
		for (int i = 0; i < sigmaB.size(); i++)
		{
			sigmaSumB += sigmaB[i];
		}

		//get sigma final sum
		sigmaSumR /= sigmaR.size();
		sigmaSumG /= sigmaG.size();
		sigmaSumB /= sigmaB.size();

		//finishing sigma pixel assigning
		img->pixels[i].r = sigmaSumR;
		img->pixels[i].g = sigmaSumG;
		img->pixels[i].b = sigmaSumB;
	}
}