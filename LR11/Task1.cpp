#include <stdio.h>
#include <locale.h>
#include <iostream>

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

	int evenProduct = 1;
	int evenSum = 0, evenCount = 0;
	float evenAverage;
	int multiplesOfThreeCount = 0;

	int* arrayMultiplesOfThree = (int*)malloc(sizeof(int) * n);
	if (!arrayMultiplesOfThree) exit(-1);

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			evenProduct *= array[i];
			evenSum += array[i];
			evenCount++;
		}
		if (array[i] % 3 == 0) {
			arrayMultiplesOfThree[multiplesOfThreeCount] = array[i];
			multiplesOfThreeCount++;
		}
	}
	printf("\n");

	evenAverage = (float)evenSum / evenCount;

	printf("\n ������������ ��������� � ������� ��������� = %d \n", evenProduct);
	printf("\n ������� �������������� ��������� � ������� ��������� = %.2f \n", evenAverage);

	printf("\n ����� ��������� ������� ����� ������� 3: \n");
	for (i = 0; i < multiplesOfThreeCount; i++) printf("%4d", arrayMultiplesOfThree[i]);
	printf("\n");

	free(array);
	free(arrayMultiplesOfThree);
}
