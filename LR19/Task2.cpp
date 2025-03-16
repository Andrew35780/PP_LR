#include <iostream>

void InputMatrixSize(int* rows, int* columns);
void AllocMemoryForMatrix(int*** matrix, int rows, int columns);
void InputMatrix(int** matrix, int rows, int columns);
void PrintMatrix(int** matrix, int rows, int columns);
void PrintArray(int* array, int size);
void FreeMatrixMemory(int** matrix, int rows, int columns);
int* MakeArrayOfRowsFromMatrix(int** matrix, int rows, int columns);
int ProductEvenAfterMax(int* array, int n);

void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int n, m;
	int** matrix = NULL;

	InputMatrixSize(&n, &m);

	AllocMemoryForMatrix(&matrix, n, m);

	printf("\n");

	InputMatrix(matrix, n, m);

	PrintMatrix(matrix, n, m);

	int* result = MakeArrayOfRowsFromMatrix(matrix, n, m);
	PrintArray(result, n);
	printf("\n");

	int productEven = ProductEvenAfterMax(result, n);
	printf("\n Произведение четных элементов расположенных после наибольшего = %d\n", productEven);

	FreeMatrixMemory(matrix, n, m);
}

void InputMatrixSize(int* rows, int* columns)
{
	printf("\n Введите размерность матрицы (n): ");
	scanf_s("%d", rows);
	printf(" Введите размерность матрицы (m): ");
	scanf_s("%d", columns);

	if (*rows <= 0 || *columns <= 0) exit(-1);
}

void AllocMemoryForMatrix(int*** matrix, int rows, int columns)
{
	*matrix = (int**)malloc(sizeof(int*) * rows);
	if (!(*matrix)) exit(-1);

	for (int i = 0; i < rows; i++)
	{
		(*matrix)[i] = (int*)malloc(sizeof(int) * columns);

		if (!(*matrix)[i])
		{
			while (i--)
				free((*matrix)[i]);

			free(*matrix);

			exit(-1);
		}
	}
}

void InputMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			printf(" Введите [%d][%d] элемент матрицы:  ", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void PrintMatrix(int** matrix, int rows, int columns)
{
	printf("\n Вывод элементов исходной матрицы: \n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%4d", matrix[i][j]);

		printf("\n");
	}
}

void PrintArray(int* array, int size) {
	printf("\n Вывод полученного массива: \n");
	for (int i = 0; i < size; i++)
		printf("%4d ", array[i]);
}

void FreeMatrixMemory(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		free(matrix[i]);
	free(matrix);

	matrix = NULL;
}

int* MakeArrayOfRowsFromMatrix(int** matrix, int rows, int columns) {
	// Выделяем память для результирующего массива
	int* result = (int*)malloc(sizeof(int) * rows);
	if (!result) {
		printf("Ошибка выделения памяти для массива\n");
		exit(-1);
	}

	// Обрабатываем каждую строку матрицы
	for (int i = 0; i < rows; i++) {
		int allPositive = 1;
		int allNegative = 1;

		// Проверяем, являются ли все элементы строки положительными или отрицательными
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] <= 0)
				allPositive = 0; // Встречен отрицательный элемент
			if (matrix[i][j] >= 0)
				allNegative = 0; // Встречен положительный элемент
		}

		// Если все элементы отрицательные – считаем сумму
		if (allNegative) {
			int sum = 0;
			for (int j = 0; j < columns; j++)
				sum += matrix[i][j];
			result[i] = sum;
		}
		// Если все элементы положительные – считаем произведение
		else if (allPositive) {
			int product = 1;
			for (int j = 0; j < columns; j++)
				product *= matrix[i][j];
			result[i] = product;
		}
		// Если строка не удовлетворяет ни одному условию – записываем 0
		else
			result[i] = 0;
	}

	return result;
}

int ProductEvenAfterMax(int* array, int n) {
	if (n <= 0) return -1;

	// Находим наибольший элемент и его индекс
	int max = array[0];
	int maxIndex = 0;

	for (int i = 1; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
			maxIndex = i;
		}
	}

	// Вычисляем произведение четных элементов, расположенных после maxIndex
	int product = 1;
	int foundEven = 0;

	for (int i = maxIndex + 1; i < n; i++) {
		if (array[i] % 2 == 0) {
			product *= array[i];
			foundEven = 1;
		}
	}
	// Если четных элементов не найдено, возвращаем 0
	return foundEven ? product : 0;
}