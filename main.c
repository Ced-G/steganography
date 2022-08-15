#include "decrypt.h"
#include "encrypt.h"

#include <stdio.h>

#define PATH "img.bmp" // Open file path

int main(int argc, char** argv)
{
    if (argc != 3 && argc != 2)
    {
        printf("Ecrypt: %s <image path> <message>\nDecrypt: %s <image path>\n", argv[0], argv[0]);
        return 1;
    }

    if (argc == 3) {
        char *msg = argv[2];
        encrypt(argv[1], msg);
    }
    else {
        decrypt(argv[1]);
    }
    
    return 0;
    

    // encrypt(PATH, "test");

    // printf("now reading created output\n");

    // decrypt("enc_img.bmp");

}