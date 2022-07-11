/*
  ------------------------------------------------------------
  ANSI C IMAGE PROCESSING TEMPLATE USING DIP LIBRARY
  by D.K. Iakovidis
  ------------------------------------------------------------
*/

//kanw askhsh5 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dip.h"			


unsigned char **processImage(unsigned char **inputImage, int rows, int columns);
unsigned char **rectanImage (unsigned char **inputImage, int rows, int columns,int x1,int x2,int y1,int y2);



int main(void)
{
     unsigned char *inputFilename = "chest339x339.raw",
                   *outputFilename = "chest339x339out.raw";
     int rows = 339, 
         columns = 339;
     int x1=30;
     int x2=80;
     int y1=50;
     int y2=100;
     
     
    unsigned char **inputImage, **outputImage;

     inputImage = allocateImage(rows, columns);     
     
     inputImage = loadImage(inputFilename, rows, columns);
     outputImage = processImage(inputImage, rows, columns);
     saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(outputImage, rows);      
     

     return 0;
}




unsigned char **normImage(unsigned char **inputImage, int rows, int columns, int x1, int y1, int x2, int y2)
{
    int i,j;
    int max_i,max_j,min_i,min_j;
	double max=0.0;
	double min=0.0;
	double kernel[rows][columns];	// kernel is defined in 2D as shown by the Gaussian function

    unsigned char **outputImage5 = allocateImage(rows, columns);
         
    for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
            if (max<inputImage[i][j])
            {
            	max=inputImage[i][j];
				max_i=i;
				max_j=j;
			}
		}
	}
	
	for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
			if (min>inputImage[i][j])
			{
				min=inputImage[i][j];
				min_i=i;
				min_j=j;
			}
    	}
	}
	
    for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
            if ((i>x1) && (i<x2) && (j>y1) && (j<y2))
            {
				kernel[i][j] = (255*inputImage[i][j]-min)/(max-min);
				if (max<kernel[i][j]) max=kernel[i][j];
				if (min>kernel[i][j]) min=kernel[i][j];			
    		}
    		else
    		{
				kernel[i][j]=inputImage[i][j];
			}
			
			outputImage5[i][j]=(unsigned char) kernel[i][j];
		}
    }
    
    return outputImage5;
}
