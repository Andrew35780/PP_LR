#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <iostream>

void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int n, i;

	printf("\n Введите размерность массива (n): ");
	scanf_s("%d", &n);
	if (n <= 0) exit(-1);

	int* array = (int*)malloc(sizeof(int) * n);
	if (!array) exit(-1);

	printf("\n");
	for (i = 0; i < n; i++) {
		printf(" Введите %d элемент массива:\n ", i + 1);
		scanf_s("%d", &array[i]);
	}

	printf("\n Вывод элементов исходного массива: \n");
	for (i = 0; i < n; i++) printf("%4d", array[i]);
	printf("\n");

	float minElement = FLT_MAX;
	float processedElement = 0.0;

	for (i = 0; i < n; i++) {
		if (array[i] > 0)
			processedElement = sqrt(array[i]);
		else
			processedElement = pow(array[i], 2);

		if (processedElement < minElement)
			minElement = processedElement;
	}

	printf("\n Минимальный элемент среди обработанных = %.2f\n", minElement);

	free(array);
}
