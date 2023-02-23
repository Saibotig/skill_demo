#include <stdio.h>
#include <stdlib.h>

//function to print random numbers
void printRandom(int lower, int upper, int n) {
	for (int i = 0; i < n; i++) {
		int rnd = (rand() % (upper + lower)) - lower;
		printf("Number %d: %d\n", i + 1, rnd);
	}
}

int main() {
	printRandom(20, 333, 12);
	return 0;
}