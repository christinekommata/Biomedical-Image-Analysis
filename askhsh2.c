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
                   *outputFilename = "chest339x339.raw";
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
     unsigned char blackWhite[rows][columns];
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
         	//erwthma b
         	
         	if (j<columns/2)
         	{
         		blackWhite[i][j]=255;
         		
			 }
			 else
			 {
			 	blackWhite[i][j]=0;
			 }
         	
        
         	
         	if (inputImage[i][j]<170)
         	{
			 
             outputImage[i][j] = 255;
         	}	
         	else
         	{
         		outputImage[i][j]=0;
			 }
			 
			 outputImage[i][j]= blackWhite[i][j];
			 
			 /*erwthma g
			 outputImage[i][j] = (255- blackWhite[i][j])|outputImage[i][j]; */
			 
			 /* erwthma d
			outputImage[i][j]= (255- blackWhite[i][j]) & outputImage[i][j];
			 */
			 
			 /* erwthma e 
			 outputImage[i][j]=~outputImage[i][j]
				*/
			 
			 /*erwthma st
			 outputImage[i][j]= (255- blackWhite[i][j]) ^ outputImage[i][j];
			 */
         }
         
     }
     return outputImage;
}
