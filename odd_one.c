#include <stdio.h>
#include <stdlib.h>

int any_odd_one (unsigned int x, int max) {
	printf("%d\n",x);

	return 0; 
}


void printIntToBin(unsigned int x) {
	unsigned int mask = 1 << 31;
	for (int i = 32; i > 0; i--) {
		if (mask & x) {
			printf("1");
		}
		else {
			printf("0");
		}
		if ((i % 4) == 1) {
			printf(" ");
		}
		mask = mask >> 1;
	}
	printf("\n");
}

int main() {
	int a = 100;
	int bit = 32;
	any_odd_one(a,bit);
	printIntToBin(a);
	return 0;
}
