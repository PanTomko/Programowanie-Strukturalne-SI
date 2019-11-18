#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main() {
	char buffer[255];
	gets(buffer);

	while (!GetKeyState(0x51)) {
		printf("%s\n", buffer);
	}

	return 0;
}
