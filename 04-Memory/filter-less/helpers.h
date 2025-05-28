#include "bmp.h"

// image = an array of height many rows, and each row is itself another array
//         of width many RGBTRIPLEs
// --> image[0] represents the first row,
// --> image[0][0] represents the pixel in the upper-left corner of the image.

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);
