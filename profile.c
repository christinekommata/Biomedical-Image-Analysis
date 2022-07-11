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

unsigned char *profile(unsigned char **inputImage, int rows, int columns, int profileRow);

int main(void)
{
     unsigned char *inputFilename = "image268x324.raw";
     
     int rows = 324, 
         columns = 268;
     int i;    
     unsigned char **inputImage;
     unsigned char *p;
  
     inputImage = loadImage(inputFilename, rows, columns);

     p = profile(inputImage, rows, columns, 20);
     
     for (i = 0; i < columns; i++)
     {
         printf("%d\n", p[i]);
     }
     
     deallocateImage(inputImage, rows);
     return 0;
}


unsigned char *profile(unsigned char **inputImage, int rows, int columns, int profileRow)
{
     int j;
     unsigned char *profile = (unsigned char *)malloc(columns * sizeof(unsigned char));
     
     for (j = 0; j < columns; j++)
     {
         profile[j] = inputImage[profileRow][j];
     }
     return profile;
}
