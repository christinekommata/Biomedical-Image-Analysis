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

unsigned char **normalizeImage(unsigned char **inputImage, int rows, int columns);
unsigned char **LUTTransform(unsigned char **inputImage, int rows, int columns, unsigned char *lut);
long *histogram(unsigned char **inputImage, int rows, int columns);
unsigned char **equalizeImage(unsigned char **inputImage, int rows, int columns);
unsigned char **sqrtImage(unsigned char **inputImage, int rows, int columns);

int main(void)
{
     unsigned char *inputFilename = "chest300x300.raw",
                   *outputFilename = "chest300x300out.raw";
     int rows = 300, 
         columns = 300;
         
     unsigned char **inputImage, **outputImage;

     inputImage = loadImage(inputFilename, rows, columns);
     
	 //outputImage = normalizeImage(inputImage, rows, columns);
     //outputImage = equalizeImage(inputImage, rows, columns);
     outputImage = sqrtImage(inputImage, rows, columns);
     
	 saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(outputImage, rows);      

     return 0;
}


unsigned char **normalizeImage(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     unsigned char min, max;
     // Find min-max
     min = 255; max = 0; 
     float factor = 0;
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
         	if (inputImage[i][j] < min) min = inputImage[i][j];
         	if (inputImage[i][j] > max) max = inputImage[i][j];
		 }
	 }
     
     // Normalize
     factor = max-min;
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = 255*(inputImage[i][j]-min)/factor;
         }
     }
     return outputImage;
}


unsigned char **LUTTransform(unsigned char **inputImage, int rows, int columns, unsigned char *lut)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);

     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = lut[ inputImage[i][j] ];
         }
     }
     return outputImage;
}

long *histogram(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     long *h = (long *)malloc(256 * sizeof(long));

     for (i = 0; i < 256; i++)
     {
         h[i] = 0;
     }
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             h[ inputImage[i][j] ]++;
         }
     }
     return h;
}

unsigned char **equalizeImage(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage; 
     unsigned char *lut = (unsigned char *)malloc(256*sizeof(unsigned char));
	 long *h = histogram(inputImage, rows, columns);
	 double sum = 0, temp = 0, factor = 0;
	 
	 // Create Look Up Table (LUT)
	 factor = rows*columns;
	 for (i = 0; i < 256; i++)
	 {
	 	sum += h[i];
	 	temp = sum * 255 / factor;
	 	if (temp > 255) temp = 255;
	 	if (temp < 0) temp = 0;
	 	lut[i] = (unsigned char)temp;
	 }
	 
	 outputImage = LUTTransform(inputImage, rows, columns, lut);

     return outputImage;
}

unsigned char **sqrtImage(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage; 
     unsigned char *lut = (unsigned char *)malloc(256*sizeof(unsigned char));
	 double temp = 0;
	 
	 // Create Look Up Table (LUT)
	 for (i = 0; i < 256; i++)
	 {
	 	temp = pow(i,0.9);//sqrt(255*i); // you change only this part
	 	if (temp > 255) temp = 255;
	 	if (temp < 0) temp = 0;
	 	lut[i] = (unsigned char)temp;
	 }
	 
	 outputImage = LUTTransform(inputImage, rows, columns, lut);

     return outputImage;
}
