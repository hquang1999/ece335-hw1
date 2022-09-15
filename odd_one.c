#include <stdio.h>
#include <stdlib.h>

// max bit size
int bit = 32;

// print function
void printBinary (int max, unsigned num) {
	printf(" Binary: ");

	unsigned int mask = 1 << (max - 1);
	
	for (int i = 0; i < max; i++) {
		if (mask & num) {
			printf("1");
		}
		else {
			printf("0");
		}
		mask = mask >> 1;
	}
	printf("\n");
}

int getFirstOne(unsigned int x, int bit) {
	int posOne = bit;
	// creates a mask of 1 with 0's that max is
	// this one will be 1 with 31 zeroes
	unsigned int mask = 1 << (posOne - 1);
	
	// loop for finding when the first 1 is in 
	// our number x
	for (; posOne > 0; posOne--) {
		// AND statement with mask and x
		if (posOne & x) {
			break;
		}
		// reduces mask 
		mask = mask >> 1;
	}
	
	return posOne;
}

int any_odd_one (unsigned int x, int bit) {
	printf("Decimal: %d\n",x);
	// max # of shifts
	int max = getFirstOne(x,bit);

	printf("max = %d\n",max);
	// Print function to visualize what the decimal is in binary
	printBinary(max, x);

	// creates a new adjusted mask.
	unsigned int mask = (max - 1) >> 1;
	
	for (int i = 1; i <= max; i++) {
		// AND statement & if the index is odd
		if ((mask & x) && (i % 2 != 0)) {
			// found a 1 in our odd binary string
			return 1;
		}
		// reduces mask
		mask = mask << 1;
	} 
	// if for loop finishes, no 1 was found in the odd index
	return 0; 
}

int main(int argv, char* argc[]) {
	unsigned int a = atoi(argc[1]);
	int res = any_odd_one(a,bit);

	printf("Results: %i\n", res);
	
	return 0;
}
