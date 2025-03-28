#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

//plaintext[i] = (cipher[i]-'a' - shift+26) %26

char* vigenere_encrypt(char* cipher, char* key)
{
    int text_length = strlen(cipher);
    int key_length = strlen(key);

    char* plaintext = (char*) malloc(sizeof(char) * (text_length + 1));
    memset(plaintext, '\0', sizeof(char) * (text_length + 1));
    for(int i = 0; i < text_length; i++)
    {
        if(isalpha(cipher[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            
            if(islower(cipher[i]))
            {
                plaintext[i] = 'a' + (cipher[i] - 'a' - shift + 26) % 26;
            }
            else
            {
                plaintext[i] = 'A' + (cipher[i] - 'A' - shift + 26) % 26;
            }
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[text_length] = '\0';
    return plaintext;
}

int main()
{
    char text[MAXN];
    scanf("%s", text);

    char key[MAXN];
    scanf("%s", key);

    char* plaintext = vigenere_encrypt(text, key);
    printf("%s", plaintext);
    free(plaintext);
    return EXIT_SUCCESS;
}

