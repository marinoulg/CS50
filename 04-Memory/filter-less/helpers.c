#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // So long as the red, green, and blue values are all equal, the result will
    // be varying shades of gray along the black-white spectrum, with higher
    // values meaning lighter shades (closer to white) and lower values meaning
    // darker shades (closer to black).

    // you can take the average of the red, green, and blue values to determine
    // what shade of grey to make the new pixel.

    for (int i = 0; i < height; i++)
    {
      // Iterating over rows
      for (int j = 0; j < width ; j++)
      {
        // Iterating over each pixel
        float average_pixel_temp = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3;
        // float average_pixel = (float) 0.f average_pixel;
        int average_pixel = round(average_pixel_temp);

        // Set the average to the colour of those 3 bytes for 1 pixel
        image[i][j].rgbtRed = average_pixel;
        image[i][j].rgbtGreen = average_pixel;
        image[i][j].rgbtBlue = average_pixel;
      }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
  {
    // Iterating over rows
    for (int j = 0; j < width ; j++)
    {
      int originalRed = image[i][j].rgbtRed;
      int originalGreen = image[i][j].rgbtGreen;
      int originalBlue = image[i][j].rgbtBlue;

      // Set the sepia colour
      int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
      int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
      int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

      // Set the set colour of those 3 bytes for 1 pixel
      image[i][j].rgbtRed = sepiaRed;
      image[i][j].rgbtGreen = sepiaGreen;
      image[i][j].rgbtBlue = sepiaBlue;
    }
  }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  int last_pixel_per_row = width - 1;

  for (int i = 0; i < height; i++)
  {
    // Iterating over rows
    for (int j = 0; j < width ; j++)
    {
      float middle = width/2;
      int middle_int = (int) middle;
      if (middle_int != round(middle)) // width is odd
      {
        middle += 1; // from median
      }
      if (j < middle)
      {
        int j_new = last_pixel_per_row - j;
        RGBTRIPLE temp_pixel = image[i][j_new];
        image[i][j_new] = image[i][j];
        image[i][j] = temp_pixel;
      }
    }
  }
  return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  // int temp_red = image[height][width].rgbtRed;
  // int temp_green = image[height][width].rgbtGreen;
  // int temp_blue = image[height][width].rgbtBlue;

  // RGBTRIPLE image_temp = image[height][width];


  // temp_red[0][0] = 255;

  for (int i = 0; i < height; i ++)
  {
    for (int j = 0; i < width; i++)
    {
      if (i == 0 || i == (height-1))
      {
        if (j == 0 || j == (width-1)) // corners of image
        {
          if (i == 0 && j == 0) // upper left corner
          {
            RGBTRIPLE temp_array[3];
            temp_array[0] = image[i][j+1];
            temp_array[1] = image[i+1][j];
            temp_array[2] = image[i+1][j+1];
          }
          else if (i == 0 && j == (width-1)) // upper right worner
          {
            RGBTRIPLE temp_array[3];
            temp_array[0] = image[i][j-1];
            temp_array[1] = image[i+1][j-1];
            temp_array[2] = image[i+1][j];
          }
          else if (i == (height-1) && j == 0) // lower left worner
          {
            RGBTRIPLE temp_array[3];
            temp_array[0] = image[i-1][j];
            temp_array[1] = image[i-1][j+1];
            temp_array[2] = image[i][j+1];
          }
          else if (i == (height-1) && j == (width-1)) // lower right worner
          {
            RGBTRIPLE temp_array[3];
            temp_array[0] = image[i-1][j-1];
            temp_array[1] = image[i-1][j];
            temp_array[2] = image[i][j-1];
          }


        }
        else // first or last row
        {
          if (i == 0) // first row
          {
            RGBTRIPLE temp_array[5];
            temp_array[0] = image[i][j-1];
            temp_array[1] = image[i][j+1];
            temp_array[2] = image[i+1][j-1];
            temp_array[3] = image[i+1][j];
            temp_array[4] = image[i+1][j+1];
          }
          else // last row
          {
            RGBTRIPLE temp_array[5];
            temp_array[0] = image[i-1][j-1];
            temp_array[1] = image[i-1][j];
            temp_array[2] = image[i-1][j+1];
            temp_array[3] = image[i][j-1];
            temp_array[4] = image[i][j+1];
          }
        }
      }
      else if (j == 0 || j == (width-1)) // first or last column
      {
        if (j == 0) // first column
        {
          RGBTRIPLE temp_array[5];
          temp_array[0] = image[i-1][j];
          temp_array[1] = image[i-1][j+1];
          temp_array[2] = image[i][j+1];
          temp_array[3] = image[i+1][j];
          temp_array[4] = image[i+1][j+1];

        }
        else // last column
        {
          RGBTRIPLE temp_array[5];
          temp_array[0] = image[i-1][j-1];
          temp_array[1] = image[i-1][j];
          temp_array[2] = image[i][j-1];
          temp_array[3] = image[i+1][j-1];
          temp_array[4] = image[i+1][j];
        }

      }
      else
      {
        RGBTRIPLE temp_array[8];
        temp_array[0] = image[i-1][j-1];
        temp_array[1] = image[i-1][j];
        temp_array[2] = image[i-1][j+1];
        temp_array[3] = image[i][j-1];
        temp_array[4] = image[i][j+1];
        temp_array[5] = image[i+1][j-1];
        temp_array[6] = image[i+1][j];
        temp_array[7] = image[i+1][j+1];

        int average_pixel_red;
        int average_pixel_blue;
        int average_pixel_green;
        for (int sum = 0; sum < 8; sum++)
        {
          average_pixel_red += temp_array[sum].rgbtRed;
          average_pixel_green += temp_array[sum].rgbtGreen;
          average_pixel_blue += temp_array[sum].rgbtBlue;
        }

        // image_temp[i][j].rgbtRed = average_pixel_blue;
        RGBTRIPLE temp = image[i][j]; // number of bytes
        temp.rgbtRed = average_pixel_red;
        temp.rgbtGreen = average_pixel_green;
        temp.rgbtBlue = average_pixel_blue;



      }
    }
  }
  return;
}
