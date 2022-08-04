#ifndef HEADER_UTILS_H
#define HEADER_UTILS_H

#include <stdio.h>

int IsBitMap(FILE *fp);

int getWidth(FILE *fp);

int getHeight(FILE *fp);

short getBit(FILE *fp);

int getOffSet(FILE *fp);

#endif