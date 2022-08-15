#include "header_utils.h"
#include "encrypt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(char *imgPath, char *msg)
{
    FILE *imageIn = fopen(imgPath, "r");
    if (!imageIn)
    {
        perror("Error opening file");
        return -1;
    }

    if (!IsBitMap(imageIn))
    {
        fprintf(stderr, "Input image is not BMP\n");
        fclose(imageIn);
        return 0;
    }

    char *foutName = calloc(strlen(imgPath) + 5, sizeof(char));
    strcat(foutName, "enc_");
    strcpy(foutName + 4, imgPath);
    FILE *imageOut = fopen(foutName, "w");
    free(foutName);

    int offset = getOffSet(imageIn);
    char *buf = (char *)malloc(offset);

    // copy the header to the output file
    fseek(imageIn, 0, SEEK_SET);
    fseek(imageOut, 0, SEEK_SET);
    fread(buf, 1, offset, imageIn);
    fwrite(buf, 1, offset, imageOut);
    free(buf);

    // copy the data to the output file
    fseek(imageIn, offset, SEEK_SET);
    fseek(imageOut, offset, SEEK_SET);

    buf = (char *)malloc(3);
    char encoded = 0;
    int i = 0;
    //192 = 11000000
    int mask = 192;
    int shift = 3;

    while (fread(buf, 1, 3, imageIn))
    {
        fwrite(buf, 1, 2, imageOut);
        if (msg[i] != '\0')
        {
            // Set 2 bits of the character
            encoded = msg[i] & mask;
            for (int k = 0; k < shift; k++)
            {
                // Shift the bits to the right
                encoded = encoded >> 2;
            }
            printf("%d\n ", encoded);

            // Set the rest of the bits to the original value
            encoded |= buf[2] & ~3;
            fwrite(&encoded, 1, 1, imageOut);
            mask >>= 2;
            shift--;
            if (mask < 3)
            {
                i++;
                shift = 3;
                mask = 192;
            }
        }
        else
            fwrite(buf + 2, 1, 1, imageOut);
    }

    free(buf);
    fclose(imageIn);
    fclose(imageOut);

    return 1;
}