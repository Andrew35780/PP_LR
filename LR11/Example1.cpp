#include <stdio.h>
#include <locale.h>
#include <iostream>
/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int n, i;

	printf("\n ������� ����������� ������� (n): ");
	scanf_s("%d", &n);
	if (n <= 0) exit(-1);

	int *array = (int *)malloc(sizeof(int) * n);

	if (!array) exit(-1);

	printf("\n");
	for (i = 0; i < n; i++) {
		printf(" ������� %d ������� �������:\n ", i + 1);
		scanf_s("%d", &array[i]);
	}

	printf("\n ����� ��������� ��������� �������: \n");
	for (i = 0; i < n; i++) printf("%4d", array[i]);

	printf("\n ����� ������������� ��������� �������: \n");
	int negativeElementsSum = 0;

	for (i = 0; i < n; i++) {
		if (array[i] < 0) {
			printf("%4d ", array[i]);
			negativeElementsSum += array[i];
		}
	}
	printf("\n");

	printf("\n ����� ������������� ����� � ������� = %d \n", negativeElementsSum);

	free(array);
}
*/