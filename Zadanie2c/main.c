#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * encrypt_copy( const char *text, int key )
{
    char small_s, big_s;
    char * result = (char*)malloc( (strlen(text)+1) * sizeof(char) );

    if(key == 0)
        return strcpy(result, text);

    if(key > 0)
    {
        small_s = 97;
        big_s = 65;
    }
    else
    {
        small_s = 122;
        big_s = 90;
    }

    int i = 0;
    while( text[i] )
    {
        if( text[i] >= 'A'  && text[i] <= 'Z')
            result[i] = (text[i] + key - big_s) % 26 + big_s;
        else if(text[i] >= 'a'  && text[i] <= 'z')
            result[i] = (text[i] + key - small_s) % 26 + small_s;
        else
            result[i] = text[i];

        i++;
    }

    result[i] = '\0';
    return result;
}


int main()
{
    const char text_1[] = "Marcin";
    const char text_2[] = "Hello World!";

    const char * encrypted_text_1 = encrypt_copy(text_1, -2);
    const char * encrypted_text_2 = encrypt_copy(text_2, 22);

    printf("%s\n", encrypted_text_1);
    printf("%s\n", encrypted_text_2);
    printf("%s\n", encrypt_copy("aAa bBb", 25) );

    printf("%d", -2 % 26);

    return 0;
}
