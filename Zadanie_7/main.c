#include <stdio.h>

void reverse_cap( char *buffer )
{
    int it = 0, lower_count = 0;

    while (buffer[it] != '\0')
    {
		if (buffer[it] >= 65 && buffer[it] <= 90)
		{
			buffer[it] += 32;
		}
		else if (buffer[it] >= 97 && buffer[it] <= 122)
		{
			buffer[it] -= 32;
			lower_count++;
		}
		else
		{
            printf("This is not valid string !\n");
            return;
		}

		it++;
	}
}

int main() {
	char buffer[255];

	gets(buffer);
    reverse_cap(buffer);
	printf("Nowy strig to \"%s\"", buffer);

	getchar();
	return 0;
}
