/*D.K. Iakovidis
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dip.h"			

unsigned char **processImage(unsigned char **inputImage,unsigned char **inputImage2, int rows, int columns);

int main(void)
{
     unsigned char *inputFilename = "image268x324.raw",
     				*inputFilename2= "Mask.raw"
                    *outputFilename = "image268x324out.raw";
     int rows = 268, 
         columns = 324;
         
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


unsigned char **processImage(unsigned char **inputImage,unsigned char **inputImage2, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
         /*erwthma g 
		 	outputImage[i][j]=inputImage[i][j] & (255-inputImage2[i][j]); */
    	 
		 /*erwthma d
		 	outputImage[i][j]=inputImage[i][j] & (inputImage2[i][j]); */
		 
		 /*erwthma e 

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

		 */
		 
		 /*erwthma st 
		 	outputImage[i][j]=inputImage[i][j] & (kernel[i][j]);
		 */
		 
		 
		 }
 	}
     return outputImage;
}
