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

unsigned char **processImage(unsigned char **inputImage,unsigned char inputImage2, int rows, int columns)

int main(void)
{
     unsigned char *inputFilename = "mri221x279.raw",
     			   *inputFilename2 = "petGrey221x279.raw"
                   *outputFilename = "fusedImage.raw";
     int rows = 221, 
         columns = 279;
         
     unsigned char **inputImage,**inputImage2, **outputImage;

     inputImage = allocateImage(rows, columns);     
     inputImage2 = allocateImage(rows, columns); 
     inputImage = loadImage(inputFilename, rows, columns);
     inputImage2 = loadImage(inputFilename2, rows, columns);
     outputImage = processImage(inputImage,inputImage2, rows, columns);
     saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(inputImage2, rows);
     deallocateImage(outputImage, rows);      

     return 0;
}


unsigned char **processImage(unsigned char **inputImage,unsigned char inputImage2, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     double min=255.0;
     double max=0.0;
     double kernel[rows][columns];
     
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             kernel[i][j] = (inputImage[i][j]+inputImage2[i][j])/2;
             if (min>kernel[i][j]) min=kernel[i][j];
             if (max<kernel[i][j]) max=kernel[i][j];

         }
     }
     
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             kernel[i][j] = 255* (kernel[i][j] - min)/(max-min);
             outputImage[i][j]=(unsigned char) kernel[i][j];
         }
     } 
     return outputImage;
}
