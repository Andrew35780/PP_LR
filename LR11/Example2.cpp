#include <stdio.h>
#include <locale.h>
#include <iostream>
/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int n, i;

	printf("\n Введите размерность массива (n): ");
	scanf_s("%d", &n);
	if (n <= 0) exit(-1);

	int* array = (int*)malloc(sizeof(int) * n);
	int* positiveArray = (int*)malloc(sizeof(int) * n);

	if (!array || !positiveArray) exit(-1);

	printf("\n");
	for (i = 0; i < n; i++) {
		printf(" Введите %d элемент массива:\n ", i + 1);
		scanf_s("%d", &array[i]);
	}

	printf("\n Вывод элементов исходного массива: \n");
	for (i = 0; i < n; i++) printf("%4d", array[i]);

	int positiveCount = 0;

	for (i = 0; i < n; i++) {
		if (array[i] > 0) {
			positiveArray[positiveCount] = array[i];
			positiveCount++;
		}
	}
	printf("\n");

	printf("\n Вывод массива из положительных чисел: \n");
	for (i = 0; i < positiveCount; i++) printf("%4d", positiveArray[i]);

	free(array);
	free(positiveArray);
}
*/