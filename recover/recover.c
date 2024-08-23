#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = sizeof(BYTE)*512;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }


    FILE *memoryCard = fopen(argv[1], "r");

    if (memoryCard == NULL)
    {
        printf("Not possible to open!\n");
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];
    char fileNameBuffer[8];
    int counter = 0;
    FILE *output = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, memoryCard) == 512)
    {
        // new file
        if (buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xF0)==0xE0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(fileNameBuffer, "%03d.jpg", counter++);

            output = fopen(fileNameBuffer, "w");
        }

        if (output != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(memoryCard);


    return 0;
}
