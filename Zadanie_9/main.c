#include <stdio.h>

int is_number( char * buffer)
{
	int it = 0;

	if (buffer[0] == '-') it++;

	while (buffer[it] != '\0')
    {
		if (!(buffer[it] >= 48 && buffer[it] <= 57)) return 0;
		it++;
	}

	return 1;
}

int main()
{
	char num[] = "3023";
	char no_num[] = "12x12";

	printf("num    : %i\n", is_number(num));
	printf("no_num : %i\n ", is_number(no_num));

	getchar();
	return 0;
}
