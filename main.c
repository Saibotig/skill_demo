#include <stdio.h>

//function to print random numbers
void printRandom(int lower, int upper, int n) {
	for (int i = 0; i < n; i++) {
		int rnd = (rand() % (upper + lower)) - lower;
		printf("%d", rnd);
	}
}

int main() {
	printRandom(20, 333, 12);
	return 0;
}