#include <stdio.h>

int count_x(char * buffer, char znak)
{
    int it = 0, result = 0;
    while (buffer[it] != '\0')
    {
		if (buffer[it] == znak) result++;
		it++;
	}

    return result;
}

int main()
{
	char buffer[255];
	char znak = '\0';


	printf("Podaj tekst : ");
	gets(buffer);
	printf("Jaki znak szukac : ");
	znak = getchar();

	printf("Znak '%c' pojawil sie : %i", znak, count_x(buffer,znak));

	getchar(); getchar();
	return 0;
}
