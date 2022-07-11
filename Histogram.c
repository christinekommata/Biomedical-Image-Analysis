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

long *histogram(unsigned char **inputImage, int rows, int columns);

int main(void)
{
     unsigned char *inputFilename = "image268x324.raw";
     
     int rows = 324, 
         columns = 268;
     int i;    
     unsigned char **inputImage;
     long *h;
  
     inputImage = loadImage(inputFilename, rows, columns);

     h = histogram(inputImage, rows, columns);
     
     for (i = 0; i < 256; i++)
     {
         printf("%ld\n", h[i]);
     }
     
     deallocateImage(inputImage, rows);
     return 0;
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
