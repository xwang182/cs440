/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 */
#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

/**
 * Images_rotation function rotates image
 * @ return the newimage 
 */
PNG Images_rotation(PNG image)
{		
	
	PNG new_image(image.width(),image.height());
	for (size_t y = 0; y < image.height();y++ )
     	{
         	for (size_t x = 0; x < image.width(); x++)
        	{
			*new_image(x,y)=*image(image.width() - x - 1,image.height() - y - 1);
		}
    }
	return new_image;
}

/**
 * The main function in this program 
 *
 * @return 0 if it is executed successful.
 */
int main()
{
	// load a new PNG image from the file sample.png.
    	PNG image(100,100);
    	image.draw(50,50);

	// rotate the image.
	//image = Images_rotation(image);

	// store new file to the destination
	image.writeToFile("out.png");

	return 0;
}




