#include <stdio.h>
#include <stdlib.h>
#include "gfx5.c"
#include "gfxe.h"

/*************************************
* An advanced example demonstrating  *
* how we are  able to manipulate     *
* pixel data in memory before it is  *
*drawn to screen                     *
*************************************/

int main( int argc, char * argv[] ) {
	gfx_open( 800, 600, "the matrix" );
	
	// Read the image data into memory
	unsigned char * bufferPtr = readRAWImage( "matrix.bmp", 54 );
	
	// The number of pixels in the image
	int size = 800 * 600;
	
	// Loop through the data and modify the pixel values
	int i,r,g,b,l;
	for ( i = 0; i < size; ++i ) {
		
		// Get the r,g,b values of pixel i
		r = *( bufferPtr + 3 * i );
		g = *( bufferPtr + 3 * i + 1 );
		b = *( bufferPtr + 3 * i + 2 );
		
		// Find the gamma-corrected luminance of the aforementioned pixel
		// (Assuming a monitor with a typical color profile)
		l = 0.3086 * r + 0.6094 * g + 0.0820 * b;

		// Set the pixel's r,g,b values to the
		// luminance value for monotone color value
		*( bufferPtr + 3 * i ) = l;
		*( bufferPtr + 3 * i + 1 ) = l;
		*( bufferPtr + 3 * i + 2 ) = l;
		
		// For fun, you could invert the colors
		//*(bufferPtr + 3 * i) = 255 - *(bufferPtr + 3 * i);
		//*(bufferPtr + 3 * i + 1) = 255 - *(bufferPtr + 3 * i + 1);
		//*(bufferPtr + 3 * i + 2) = 255 - *(bufferPtr + 3 * i + 2);
	}
	
	// Draw the image on screen
	printRAWImage ( 0, 0, 800, 600, bufferPtr );
	
	// Always remember to release your memory!
	free( bufferPtr );
	
	gfx_wait();
	return 0;
}
