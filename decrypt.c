#include "decrypt.h"
#include "header_utils.h"

#include <stdlib.h>
#include <stdio.h>

int decrypt(char *imgPath) {
    FILE *img = fopen(imgPath, "r");
    if (!img) {
        perror("Error opening file");
        return -1;
    }
    if (!IsBitMap(img)) {
        fprintf(stderr, "Input image is not BMP\n");
        fclose(img);
        return 0;
    }

    fseek(img, getOffSet(img), SEEK_SET);
    char *buf = (char *)malloc(3);
    char decoded = 0;
    int k = 0;

    while (fread(buf, 1, 3, img))
    {
        decoded = (decoded & ~3) | (buf[2] & 3);
        if (k == 3)
        {
            if (decoded == 0) {
                break;
            }
            printf("%c", decoded);
            k = 0;
            decoded = 0;
        }
        else
        {
            decoded <<= 2;
            k++;
        }
    }

    printf("\n");

    free(buf);
    fclose(img);

    return 1;
}