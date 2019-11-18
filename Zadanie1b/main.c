#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// doc
/**
 * return value are form [1;5]
 * 1 - valid password
 * 2 - lack of number
 * 3 - lack of big letter
 * 4 - lack of small letter
 * 5 - lack of special symbols
**/
int is_password_valid(char * buffer)
{
    int it = 0;
	int small_letter = 0, big_letter = 0, number = 0, special = 0; // bools

	while (buffer[it] != '\0')
    {
		if(buffer[it] >= 'a' && buffer[it] <= 'z')
        {
            small_letter = 1;
        }
        else if(buffer[it] >= 'A' && buffer[it] <= 'Z')
        {
			big_letter = 1;
		}
		else if (buffer[it] >= 48 && buffer[it] <= 57)
		{
			number = 1;
		}
		else if(buffer[it] >= 33 && buffer[it] < 127)
		{
			special = 1;
		}

		if(small_letter && big_letter && special && number) return 1;

		it++;
	}

    if (!number)
		return 2;

    if (!big_letter)
		return 3;

    if (!small_letter)
		return 4;

    if (!special)
		return 5;
}

char * generate_password(int size)
{
    srand(time(0));
    char * password = (char*)malloc(size+1 * sizeof(char));

    if(size == 0) return NULL;

    do{
        for(int i = 0; i < size; i++)
            password[i] = 33 + rand() / (RAND_MAX / (126 - 33 + 1) + 1);
    }while(is_password_valid(password) != 1);

    password[size] = '\0';
    return password;
}

int main()
{
    int pas_size = 0;

    printf("Jak dlugie haslo <4;20> znakow : ");
    scanf("%d", &pas_size);

    if(pas_size < 4 || pas_size > 20){
        printf("Zla wielkosc !");
        return;
    }

    char * password = generate_password(pas_size);
    printf("%s", password);
    return 0;
}
