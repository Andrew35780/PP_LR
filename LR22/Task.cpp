#include <stdio.h>
#include <iostream>

void print_digits(unsigned int n);

int main() {
	setlocale(LC_CTYPE, "");
	system("color f0");

	unsigned int n;

	printf("\n������� ����������� ����� n: ");
	scanf_s("%u", &n);

	print_digits(n);
	printf("\n");

	return 0;
}

void print_digits(unsigned int n)
{
	if (n < 10) {
		printf("%u ", n);
		return;
	}

	// ���������� �������� �� ������ �����
	print_digits(n / 10);

	// ������� ��������� ����� ����� ������������ ������
	printf("%u ", n % 10);
}
