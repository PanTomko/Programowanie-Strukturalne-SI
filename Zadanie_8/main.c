#include <stdio.h>

void add_10_p(int * num) {
	*num += 10;
}

int add_10_v(int num) {
	return num + 10;
}

int main()
{
	int a = 10;
	add_10_p(&a);
	printf("Liczba : %i\n", a);
	printf("Liczba : %i", add_10_v(a));
	getchar();
	return 0;
}
