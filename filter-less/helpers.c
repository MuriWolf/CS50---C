#include "helpers.h"
#include "stdio.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumColors = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            int meanColors = round((float) sumColors / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = meanColors;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // int rowCopyLength = sizeof(image[height]) / sizeof(rowCopy[0]);
        RGBTRIPLE rowCopy[width];

        for (int k = 0; k < width; k++)
        {
            rowCopy[k] = image[i][k];
        }

        for (int j = 0; j < width; j++)
        {
            image[i][j] = rowCopy[width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0, sumRed = 0, sumGreen = 0;

            int rowPositions[3] = {-1, 0, 1};
            int colPositions[3] = {-1, 0, 1};

            // 9 in this case works like an 'NULL', if is 9, then ignore it. I am using this because using NULL didn't work,
            // so i decided to use a number that will never be used in this case (since zero is being used)
            if (i == 0)
            {
                // no way to access the row above the first one, so remove -1
                rowPositions[0] = 9;
            }
            if (i == height - 1)
            {
                // no way to access the row below the last one, so remove 1
                rowPositions[2] = 9;
            }

            if (j == 0)
            {
                colPositions[0] = 9;
            }
            if (j == width - 1)
            {
                colPositions[2] = 9;
            }

            int counter = 0;

            for (int k = 0; k < 3; k++)
            {
                // here if is 9, then ignore it, like explained before
                if (rowPositions[k] != 9)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (colPositions[l] != 9)
                        {
                            counter++;
                            sumRed = sumRed + copy[i + rowPositions[k]][j + colPositions[l]].rgbtRed;
                            sumGreen = sumGreen + copy[i + rowPositions[k]][j + colPositions[l]].rgbtGreen;
                            sumBlue = sumBlue + copy[i + rowPositions[k]][j + colPositions[l]].rgbtBlue;
                        }
                    }
                }
            }
            image[i][j].rgbtRed = round((float) sumRed / counter);
            image[i][j].rgbtGreen = round((float) sumGreen / counter);
            image[i][j].rgbtBlue = round((float) sumBlue / counter);
        }
    }
    return;
}
