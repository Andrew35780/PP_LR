#include <locale.h>
#include <iostream>
#include <iomanip>

using namespace std;

/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	const int N = 3, M = 4;
	int A[N][M], max[N];
	int i, j;

	for (i = 0; i < N; i++) // ввод матрицы
	{
		for (j = 0; j < M; j++)
		{
			cout << " Введите элемент матрицы A = " << endl;
			cin >> A[i][j];
		}
	}

	cout << "\n Вывод  матрицы А : " << endl;

	for (i = 0; i < N; i++) // вывод исходной матрицы по строкам
	{
		for (j = 0; j < M; j++)   
			cout << setw(4) << A[i][j] << "  ";

		cout << endl; // переход на новую строку в матрице
	}

	for (i = 0; i < N; i++)
	{
		max[i] = A[i][0]; // первый элемент в каждой строке полагаем наибольшим
		for (j = 0; j < M; j++)
		{
			if (A[i][j] > max[i])
				max[i] = A[i][j];
		}
	}
	cout << endl;

	cout << " Вывод массива максимальных элементов в каждой строке : " << endl;
	for (i = 0; i < N; i++)  
		cout << max[i] << endl;
}
*/