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

unsigned char **processImage(unsigned char **inputImage, int rows, int columns);

int main(void)
{
     unsigned char *inputFilename = "image268x324.raw",
                   *outputFilename = "image268x324out.raw";
     int rows = 324, 
         columns = 268;
         
     unsigned char **inputImage, **outputImage;

     inputImage = allocateImage(rows, columns);     
     
     inputImage = loadImage(inputFilename, rows, columns);
     outputImage = processImage(inputImage, rows, columns);
     saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(outputImage, rows);      

     return 0;
}


unsigned char **processImage(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = inputImage[i][j];
         }
     }
     return outputImage;
}
