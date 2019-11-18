#include <stdio.h>

int to_num(char *buffer)
{
	int result = 0, it = 0, sing = 1;

	if (buffer[0] == '-')
    {
		it = 1;
		sing = -1;
	}

	for (; buffer[it] != '\0'; ++it)
    {
		if (!(buffer[it] >= 48 && buffer[it] <= 57))
		{
			printf("to nie liczba -> ");
			return 0;
		}
		else
			result = result * 10 + (buffer[it] - 48);
	}

	return result * sing;
}

int main()
{
	printf("num    : %i\n", to_num("3023"));
	printf("num2   : %i\n", to_num("-23"));
	printf("no_num : %i\n", to_num("12x12"));

	getchar();
	return 0;
}
