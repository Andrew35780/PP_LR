#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	system("color f0");

	float A = 23.4;
	float B = 8.7;
	int C = 82;
	int D = 23;

	printf("A/B = %f\n", A / B);
	printf("C/D = %f\n", C / (float)D);
	printf("C%D = %d\n", C % D);
	printf("C++ = %d\n", C++);
	printf("D-- = %d\n", D--);

	int y = --C + 20;
	printf("y=--C+20; y = %d\n", y);

	int z = (C--) + 20;
	printf("z=(C--)+20; z = %d\n", z);

	return 0;
}
