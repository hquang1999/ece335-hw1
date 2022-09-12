#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer a, int len) {
	int i;
	
	printf("Hex \n");
	for(i = 0; i < len; i++) {
		printf("%.2x ", a[i]);
	}
/*
	printf("\nint? \n");
	for(i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
*/	
	printf("\n\n");
}

void show_int(int a) {
	show_bytes((byte_pointer)&a, sizeof(a));
}

void show_float(float a) {
	show_bytes((byte_pointer)&a, sizeof(a));
}

int main(int argv, char* argc[]) {
	int a = atoi("14281");
	int b = atoi("-14281");
	float c = atof("14281");

	printf("show int %d\n", a);
	show_int(a);

	printf("show int %d\n", b);
	show_int(b);
	
	printf("show float %g\n", c);
	show_float(c);
	
	return 0;
}
