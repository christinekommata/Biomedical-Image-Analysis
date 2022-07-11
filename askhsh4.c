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
     unsigned char *inputFilename = "chest339x339.raw",
                   *outputFilename = "chest339x339out.raw";
     int rows = 339, 
         columns = 339;
         
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
     int max_i=0;
     int max_j=0;
     double max=0.0;
     
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
         	if (max<inputImage[i][j]) 
         	{
			
			 max=inputImage[i][j];
			 max_i=i;
			 max_j=j;
			}
			 
         }
     }
     
      for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         { 
     		if((j==max_j) && (i>max_i-10) && (i<max_i+10) || (i==max_i) && (j>max_j-10) && (j<max_j+10))
     		{
			
			 outputImage[i][j] = 0;
			}
			else
			{
				outputImage[i][j]=inputImage[i][j];
			}
 		}
	}
     return outputImage;
}
