/*
  ------------------------------------------------------------
  DYNAMIC ANSI C IMAGE MANAGEMENT LIBRARY
  by D.K. Iakovidis
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

unsigned char **allocateImage(int rows, int columns)
{
      unsigned char **image = (unsigned char **)malloc(rows * sizeof(unsigned char *));
      int i;
      for (i = 0; i < rows; i++)
      {
          image[i] = (unsigned char *)malloc(columns * sizeof(unsigned char));
      }
      return image;
}

void deallocateImage(unsigned char **image, int rows)
{
     int i;
     for (i = 0; i < rows; i++)
     {
         free(image[i]);
     }
     free(image);     
}

unsigned char **loadImage(char *filename, int rows, int columns)
{
    FILE *inputFile;
    unsigned char **image = allocateImage(rows, columns);

    int i,j;    
	if ( ((inputFile = fopen(filename,"rb")) != NULL))
	{
		for  (i = 0; i < rows; i++)
		{
			for  (j = 0; j < columns; j++)
			{
				fscanf(inputFile, "%c", &image[i][j]);
			}
		}
	} 
	else
	{
		printf("Error loading image.");
	}
	fclose(inputFile);
	return image;
}


void saveImage(char *filename, unsigned char **image, int rows, int columns)
{
    FILE *outputFile;
     
    int i,j;
   	if ( ((outputFile = fopen(filename,"wb")) != NULL))
	{
		for  (i = 0; i < rows; i++)
		{
			for  (j = 0; j < columns; j++)
			{
				fprintf(outputFile, "%c", image[i][j]);
			}
		}
	} 
	else
	{
		printf("Error saving image.");
	}
	fclose(outputFile);
}

