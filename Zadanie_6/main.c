#include <stdio.h>

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

    return 1;
}

int main() {
	char password[8];
	printf("Podaj silne haslo [max 8]: ");
	scanf("%s", password);

    int result = is_password_valid(password);

    if (result == 3 || result == 4)
        printf("Przynajmniej jedna litera, mala i duza !");
	else if (result == 2)
        printf("Przynajmniej jedna cyfra !");
	else if ( result == 5)
        printf("Przynajmniej jeden special !");
    else if ( result == 1)
        printf("Znakomite haslo !");

	getchar(); getchar();
	return 0;
}
