#include <stdio.h>

int is_num( char c )
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;

    return 0;
}

int main()
{
	int code = 0;

	printf("Podaj LITERE : ");
	code = getchar();

	if (is_num(code))
		printf("Fainie tego chcialem.");
	else
		printf("Kawalarz sie znalaz !");

	getchar(); getchar();
	return 0;
}
