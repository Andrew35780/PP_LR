#include <stdio.h>
#include <locale.h>
#include <iostream>

#define n 15
/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int i, array[n];

	printf("\n");
	for (i = 0; i < n; i++) {
		printf(" Введите %d элемент массива:\n ", i + 1);
		scanf_s("%d", &array[i]);
	}

	printf("\n Вывод элементов исходного массива: \n");
	for (i = 0; i < n; i++) printf("%4d", array[i]);
	printf("\n\n");

	int elementsSum = 0;
	for (i = 0; i < n; i++) {
		elementsSum += array[i];
	}
	
	float average = (float)elementsSum / n;

	printf(" Среднее арифметическое элементов массива = %.2f\n\n", average);

	float difference = 0;
	for (i = 0; i < n; i++) {
		difference = array[i] - average;
		printf(" Разность %d = %.2f\n", i + 1, difference);
	}
	printf("\n");
}
*/