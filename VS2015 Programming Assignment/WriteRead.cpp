#include "WriteRead.h"

Image WriteRead::readPPM(const char *filename)
{
	//Remove this cout to prevent multiple outputs
	std::cout << "\nReading image ..." << std::endl;

	std::ifstream ifs; //declare ifstream
	ifs.open(filename, std::ios::binary); //open file in 'binary'
	Image src; //declaring empty Image object 'src'

	try {
		if (ifs.fail()) {
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
			//if fail to open -> throw
		}

		//class var declarations
		//std::string header -> 'P6' binary header
		//int w, h, b -> width, heigh, colour depth (now private variables

		ifs >> header; //output to header string
		if (strcmp(header.c_str(), "P6") != 0)
		{
			throw("Can't read the input file - is it in binary format (Has P6 in the header)?");
			//if fail -> throw
		}

		ifs >> w >> h >> b; //takes vars from file
							//empty image class 'src' w and h = local w and h

		src.w = w;
		src.h = h;
		//std::cout << w << " " << h << std::endl;

		src.pixels = new Image::Rgb[w * h]; //creates 'Image class' 1D array of local var w and h - image resolution(this is throw an exception if bad_alloc)
		ifs.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data 
		unsigned char pix[3]; // read each pixel one by one and convert bytes to floats 

		for (int i = 0; i < w * h; ++i) {
			//^ for i is less than the sum of local w * h
			ifs.read(reinterpret_cast<char *>(pix), 3);
			src.pixels[i].r = pix[0] / 255.f;
			src.pixels[i].g = pix[1] / 255.f;
			src.pixels[i].b = pix[2] / 255.f;
			//read each element of pixel array and convert it's R,G,B binary values -> float values
		}

		ifs.close();
	}
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ifs.close();
	}

	//Confirm image read
	//Delete this to prevent multiple lines output
	std::cout << "Image Read: " << filename << std::endl;
	return src;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^
//Reads ppm files into program
//They need to be in 'binary' format (P6) with no comments in the header
//The first line is the 'P'number - P6 indicates it is a binary file, then the image dimensions and finally the colour range
//This header is then followed by the pixel colour data
//eg:	P6
//		3264 2448
//		255
//Open a .ppm file in notepad++ to see this header (caution: they are large files!)

void WriteRead::writePPM(Image &img, const char *filename)
{
	//std::cout << filename << std::endl;
	std::cout << "\nWriting image ..." << std::endl;

	if (img.w == 0 || img.h == 0)
	{
		fprintf(stderr, "Can't save an empty image\n");
		return;
	}

	std::ofstream ofs; //declare ofstream

	try {
		ofs.open(filename, std::ios::binary); // need to spec. binary mode for Windows users 

		if (ofs.fail())
			throw("Can't open output file");

		ofs << "P6\n" << img.w << " " << img.h << "\n255\n";
		//std::cout << "P6\n" << img.w << " " << img.h << "\n255\n";

		//local r, g, b vars
		unsigned char r, g, b;

		// loop over each pixel in the image, clamp and convert to byte format
		for (int i = 0; i < img.w * img.h; ++i) {
			r = static_cast<unsigned char>(std::min(1.f, img.pixels[i].r) * 255);
			g = static_cast<unsigned char>(std::min(1.f, img.pixels[i].g) * 255);
			b = static_cast<unsigned char>(std::min(1.f, img.pixels[i].b) * 255);
			ofs << r << g << b;
		}

		ofs.close();
		std::cout << "Image Written!" << std::endl;
		//^ Confirm image write
	}

	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ofs.close();
	}

	outputInfo(filename);
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^
//Write data out to a ppm file
//Constructs the header as in readPPM