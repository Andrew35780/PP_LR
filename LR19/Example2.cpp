// Программа, в которой функция mas принимает двумерный массив как параметр.
#include <iostream> 

#define n 2 // Число строк 
#define m 3 // Число столбцов 

using namespace std;

int mas(int[][m], int, int); // Прототип функции  
/*
int main()
{
	setlocale(LC_CTYPE, "");

	int y[n][m], i, j, min;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << "\n Введите y[" << i << "][" << j << "] = ";
			cin >> y[i][j]; // Ввод массива 
		}
	}

	min = mas(y, n, m); // Обращение к функции и получение результата 
	cout << "\n\n Минимальная компонента = " << min << endl;

	return 0;
}*/

int mas(int x[][m], int k, int d) // Заголовок функции 
{
	int min1 = x[0][0]; 
	int i, j;

	for (i = 0; i < k; i++) 
	{
		for (j = 0; j < d; j++)
		{
			if (x[i][j] < min1) 
				min1 = x[i][j];
		}
	}

	return min1;
}
