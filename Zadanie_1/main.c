#include <stdio.h>

int main() {
	char buffer[255];

	gets(buffer);
	printf("Hello World \n%s", buffer);

	getchar(); getchar();
	return 0;
}
