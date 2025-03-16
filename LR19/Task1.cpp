#include <iostream>

void InputSquareMatrixSize(int* rows);
void AllocMemoryForMatrix(int*** matrix, int rows);
void InputMatrix(int** matrix, int rows);
void PrintMatrix(int** matrix, int rows, const char* matrixTitle = "квадратной");
void FreeMatrixMemory(int** matrix, int rows);
void CalcSumAndCountPositiveNumbers(int** matrix, int rows, int* positiveCount, int* positiveSum);
void PrintSumAndCountPositiveNumbers(int const positiveCount, int const positiveSum);
/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int rows, positiveCount = 0, positiveSum = 0;
	int** matrix = NULL;

	InputSquareMatrixSize(&rows);

	AllocMemoryForMatrix(&matrix, rows);

	printf("\n");

	InputMatrix(matrix, rows);

	PrintMatrix(matrix, rows);

	printf("\n");
	CalcSumAndCountPositiveNumbers(matrix, rows, &positiveCount, &positiveSum);

	PrintSumAndCountPositiveNumbers(positiveCount, positiveSum);

	FreeMatrixMemory(matrix, rows);
}*/

void InputSquareMatrixSize(int* rows)
{
	printf("\n Введите размерность матрицы (n): ");
	scanf_s("%d", rows);

	if (*rows <= 0) exit(-1);
}

void AllocMemoryForMatrix(int*** matrix, int rows)
{
	*matrix = (int**)malloc(sizeof(int*) * rows);
	if (!(*matrix)) exit(-1);

	for (int i = 0; i < rows; i++)
	{
		(*matrix)[i] = (int*)malloc(sizeof(int) * rows);

		if (!(*matrix)[i])
		{
			while (i--)
				free((*matrix)[i]);

			free(*matrix);

			exit(-1);
		}
	}
}

void InputMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			printf(" Введите [%d][%d] элемент матрицы:\n ", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void PrintMatrix(int** matrix, int rows, const char* matrixTitle)
{
	printf("\n Вывод элементов %s матрицы: \n", matrixTitle);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%4d", matrix[i][j]);

		printf("\n");
	}
}

void FreeMatrixMemory(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		free(matrix[i]);
	free(matrix);

	matrix = NULL;
}

void CalcSumAndCountPositiveNumbers(int** matrix, int rows, int* positiveCount, int* positiveSum)
{
	for (int i = 0; i < rows; i++) {
		for (int j = i + 1; j < rows; j++) {
			if (matrix[i][j] > 0)
			{
				*positiveSum += matrix[i][j];
				(*positiveCount)++;
			}
		}
	}
}

void PrintSumAndCountPositiveNumbers(int const positiveCount, int const positiveSum)
{
	printf(" Сумма положительных элементов выше главной диагонали = %d \n", positiveSum);
	printf(" Количество положительных элементов выше главной диагонали = %d \n", positiveCount);
}
