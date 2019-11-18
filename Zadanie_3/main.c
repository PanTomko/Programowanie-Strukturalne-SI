#include <stdio.h>

int main() {
	int a,b;

	printf("Poddaj dwie liczby np. \"21 30\" : ");
	scanf("%d%d", &a, &b);

	printf("%i + %i = %i\n", a, b, a+b);
	printf("%i - %i = %i\n", a, b, a-b);
	printf("%i * %i = %i\n", a, b, a*b);
	printf("%i / %i = %i\n", a, b, a/b);

	getchar(); getchar();
	return 0;
}
