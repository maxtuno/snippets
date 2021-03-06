// Created by Oscar Riveros
// http://twitter.com/maxtuno
// Unlicensed (Public Domain)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ui128tos(unsigned __int128 n) {
	char *s = (char *)calloc(sizeof(char), 40);
	do {
		*--s = "0123456789"[n % 10];
		n /= 10;
	} while (n);
	return s;
}

unsigned __int128 stoui128(char *s) {
	unsigned __int128 n = 0;
	for (unsigned i = 0; i < strlen(s); i++) {
		n *= 10;
		n += (s[i] - '0');
	}
	return n;
}

int main() {
	char s[] = "340282366920938463463374607431768211455"; // (1 << 128) - 1
	printf("%s\n", ui128tos(stoui128(s)));
	return EXIT_SUCCESS;
}
