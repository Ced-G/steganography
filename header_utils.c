#include "header_utils.h"

int IsBitMap(FILE *fp)
{
    int s;
    fread(&s, 1, 2, fp);
    // 19778 is the flag of bitmap (ASCII: BM)
    return s == 19778 ? 1 : 0;
}

int getWidth(FILE *fp)
{
    int width;
    fseek(fp, 18, SEEK_SET);
    fread(&width, 1, 4, fp);
    return width;
}

int getHeight(FILE *fp)
{
    int height;
    fseek(fp, 22, SEEK_SET);
    fread(&height, 1, 4, fp);
    return height;
}

short getBit(FILE *fp)
{
    short bit;
    fseek(fp, 28, SEEK_SET);
    fread(&bit, 1, 2, fp);
    return bit;
}

int getOffSet(FILE *fp)
{
    int OffSet;
    fseek(fp, 10L, SEEK_SET);
    fread(&OffSet, 1, 4, fp);
    return OffSet;
}