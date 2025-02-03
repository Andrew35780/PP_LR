#include <stdio.h>
#include <locale.h>
#include <iostream>

void InputMatrixSize(int* rows, int* columns);
void AllocMemoryForMatrix(int*** matrix, int* rows, int* columns);
void InputMatrix(int** matrix, int* rows, int* columns);
void PrintMatrix(int** matrix, int* rows, int* columns, const char* matrixTitle = "исходной");
void FreeMatrixMemory(int** matrix, int* rows, int* columns);
void CalculateAndPrintMatrixSums(int** matrix, int* rows, int* columns, bool const isRowSum);
/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int rows, columns;
	int** matrix = NULL;

	InputMatrixSize(&rows, &columns);

	AllocMemoryForMatrix(&matrix, &rows, &columns);

	printf("\n");

	InputMatrix(matrix, &rows, &columns);

	PrintMatrix(matrix, &rows, &columns);
	
	CalculateAndPrintMatrixSums(matrix, &rows, &columns, true);

	printf("\n");

	CalculateAndPrintMatrixSums(matrix, &rows, &columns, false);

	FreeMatrixMemory(matrix, &rows, &columns);
}

void InputMatrixSize(int* rows, int* columns) 
{
	printf("\n Введите размерность матрицы (n m): ");
	scanf_s("%d %d", rows, columns);

	if (*rows <= 0 || *columns <= 0) exit(-1);
}

void AllocMemoryForMatrix(int*** matrix, int* rows, int* columns) 
{
	*matrix = (int**)malloc(sizeof(int*) * (*rows));
	if (!(*matrix)) exit(-1);

	for (int i = 0; i < *rows; i++)
	{
		(*matrix)[i] = (int*)malloc(sizeof(int) * (*columns));

		if (!(*matrix)[i])
		{
			while (i--)
				free((*matrix)[i]);

			free(*matrix);

			exit(-1);
		}
	}
}

void InputMatrix(int** matrix, int* rows, int* columns)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *columns; j++)
		{
			printf(" Введите [%d][%d] элемент матрицы:\n ", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void PrintMatrix(int** matrix, int* rows, int* columns, const char* matrixTitle)
{
	printf("\n Вывод элементов %s матрицы: \n", matrixTitle);
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *columns; j++)
			printf("%4d", matrix[i][j]);

		printf("\n");
	}
}

void FreeMatrixMemory(int** matrix, int* rows, int* columns)
{
	for (int i = 0; i < *rows; i++)
		free(matrix[i]);
	free(matrix);

	matrix = NULL;
}

void CalculateAndPrintMatrixSums(int** matrix, int* rows, int* columns, bool const isRowSum) 
{
	for (int idx = 0; idx < (isRowSum ? *rows : *columns); idx++) {
		
		int negativeSum = 0;
		int positiveSum = 0;

		for (int subIdx = 0; subIdx < (isRowSum ? *columns : *rows); subIdx++) {
			int value = isRowSum ? matrix[idx][subIdx] : matrix[subIdx][idx];

			if (value < 0)
				negativeSum += value;
			else
				positiveSum += value;
		}

		if (isRowSum) 
		{
			printf("\n Сумма отрицательных элементов в %d строке = %d \n", idx + 1, negativeSum);
			printf(" Сумма положительных элементов в %d строке = %d \n", idx + 1, positiveSum);
		}
		else 
		{
			printf("\n Сумма отрицательных элементов в %d столбце = %d \n", idx + 1, negativeSum);
			printf(" Сумма положительных элементов в %d столбце = %d \n", idx + 1, positiveSum);
		}
	}
}
*/