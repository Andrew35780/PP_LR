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
	printf("\n ������������ ������ ��������� ������������� ����� ����������� = %d\n", productEven);

	FreeMatrixMemory(matrix, n, m);
}

void InputMatrixSize(int* rows, int* columns)
{
	printf("\n ������� ����������� ������� (n): ");
	scanf_s("%d", rows);
	printf(" ������� ����������� ������� (m): ");
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
			printf(" ������� [%d][%d] ������� �������:  ", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void PrintMatrix(int** matrix, int rows, int columns)
{
	printf("\n ����� ��������� �������� �������: \n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%4d", matrix[i][j]);

		printf("\n");
	}
}

void PrintArray(int* array, int size) {
	printf("\n ����� ����������� �������: \n");
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
	// �������� ������ ��� ��������������� �������
	int* result = (int*)malloc(sizeof(int) * rows);
	if (!result) {
		printf("������ ��������� ������ ��� �������\n");
		exit(-1);
	}

	// ������������ ������ ������ �������
	for (int i = 0; i < rows; i++) {
		int allPositive = 1;
		int allNegative = 1;

		// ���������, �������� �� ��� �������� ������ �������������� ��� ��������������
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] <= 0)
				allPositive = 0; // �������� ������������� �������
			if (matrix[i][j] >= 0)
				allNegative = 0; // �������� ������������� �������
		}

		// ���� ��� �������� ������������� � ������� �����
		if (allNegative) {
			int sum = 0;
			for (int j = 0; j < columns; j++)
				sum += matrix[i][j];
			result[i] = sum;
		}
		// ���� ��� �������� ������������� � ������� ������������
		else if (allPositive) {
			int product = 1;
			for (int j = 0; j < columns; j++)
				product *= matrix[i][j];
			result[i] = product;
		}
		// ���� ������ �� ������������� �� ������ ������� � ���������� 0
		else
			result[i] = 0;
	}

	return result;
}

int ProductEvenAfterMax(int* array, int n) {
	if (n <= 0) return -1;

	// ������� ���������� ������� � ��� ������
	int max = array[0];
	int maxIndex = 0;

	for (int i = 1; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
			maxIndex = i;
		}
	}

	// ��������� ������������ ������ ���������, ������������� ����� maxIndex
	int product = 1;
	int foundEven = 0;

	for (int i = maxIndex + 1; i < n; i++) {
		if (array[i] % 2 == 0) {
			product *= array[i];
			foundEven = 1;
		}
	}
	// ���� ������ ��������� �� �������, ���������� 0
	return foundEven ? product : 0;
}