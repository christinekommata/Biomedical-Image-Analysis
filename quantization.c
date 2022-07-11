/*
  ------------------------------------------------------------
  ANSI C IMAGE PROCESSING TEMPLATE USING DIP LIBRARY
  by D.K. Iakovidis
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dip.h"			


unsigned char **thresholdImage(unsigned char **inputImage, int rows, int columns, unsigned char threshold);

unsigned char **quantizeImage(unsigned char **inputImage, int rows, int columns, unsigned char levels);

int main(void)
{
     unsigned char *inputFilename = "image268x324.raw",
                   *outputFilename = "image268x324out.raw";
     int rows = 324, 
         columns = 268;
         
     unsigned char **inputImage, **outputImage;
    
     inputImage = loadImage(inputFilename, rows, columns);

     outputImage = quantizeImage(inputImage, rows, columns, 8);
     //outputImage = thresholdImage(inputImage, rows, columns, 190);


     saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(outputImage, rows);      

     return 0;
}


unsigned char **thresholdImage(unsigned char **inputImage, int rows, int columns, unsigned char threshold)
{
	int i,j;
    unsigned char **outputImage = allocateImage(rows, columns);

	for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
         	if (inputImage[i][j] >= threshold)
         	{
             	outputImage[i][j] = 255;
			} 
			else
			{
				outputImage[i][j] = 0;
			}
         }
     }
     return outputImage;
}


unsigned char **quantizeImage(unsigned char **inputImage, int rows, int columns, unsigned char levels)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);

     float q = 255.0f/levels;
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = (unsigned char)(floor(inputImage[i][j]/q)*q+q/2);
         }
     }
     return outputImage;
}
