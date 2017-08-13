// Created by Oscar Riveros 
// http://twitter.com/maxtuno
// Unlicensed (Public Domain)

#include <stdlib.h>
#include <stdio.h>

void print_list(int *list, unsigned size) {
	printf("[");
	for (unsigned i = 0; i < size; i++) {
		printf("%i, ", list[i]);
	}
	printf("]\n");
}

//invert a list on time "O(n/2)" and space O(1)
int *invert_list(int *list, unsigned size) {
	int aux = 0;
	for (unsigned i = 0; i < size / 2; i++) {
		aux = list[size - 1 - i];
		list[size - 1 - i] = list[i];
		list[i] = aux;
	}
	return list;
}

int main(int argc, char **argv) {

	unsigned size = atoll(argv[1]);

	int *list = (int *) calloc(sizeof(int), size);
	for (unsigned i = 0; i < size; i++) {
		list[i] = i;
	}

	print_list(list, size);
	print_list(invert_list(list, size), size);

	return EXIT_SUCCESS;
}
