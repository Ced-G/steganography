#include "decrypt.h"
#include "encrypt.h"

#include <stdio.h>

#define PATH "fruits.bmp" // Open file path

int main()
{
    char msg[] = "Hello";
    encrypt(PATH, msg);

    printf("now reading created output\n");

    decrypt("enc_fruits.bmp");

    return 0;
}