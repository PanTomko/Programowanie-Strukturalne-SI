#include <stdio.h>

int main() {
	char op = 'n';
	int a, b, result;

	while (op != 'Q') {
		printf("Podaj operacje [-,+,*,/,Q]: ");
		scanf("%c", &op);

		if (op == 'Q') return 0;

		printf("Podaj dwie lczby np \"20 30\": ");
		scanf("%i %i", &a, &b);

		switch (op) {
			case '*': result = a * b; break;
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '/': result = a / b; break;
		}

		printf("Wynik %i %c %i : %i\n\n", a, op, b, result);
		getchar();
	}
	return 0;
}
