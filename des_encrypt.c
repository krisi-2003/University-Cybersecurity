#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define MAXN 1000

//gcc des_encrypt.c -o des_encrypt -lcrypto


int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    unsigned char input[MAXN];

    scanf("%s", input);

    unsigned int length = strlen(input);

    int padded_length = ((length + 7) / 8) * 8;  //padding to be multiple of 8 (пълнежът да бъде кратен на 8)
    unsigned char padded_input[padded_length];
    unsigned char output[padded_length];

    int difference_length = padded_length - length;
    memcpy(padded_input, input, length);
    memset(padded_input + length, difference_length, difference_length);

    DES_key_schedule key_schedule;
    DES_set_key( (DES_cblock*) key, &key_schedule); //make the key in cblock from string(направете ключа в cblock от низ)

    for(int i = 0; i < padded_length; i += 8)
    {
        DES_ecb_encrypt( (DES_cblock*) (padded_input + i),
            (DES_cblock*) (output + i), &key_schedule, DES_ENCRYPT);
    }

    for(int i = 0; i < padded_length; i++)
    {
        printf("%02x", output[i]);
    }
    return EXIT_SUCCESS;
}
