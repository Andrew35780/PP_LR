// ���������, � ������� ������� mas ��������� ��������� ������ ��� ��������.
#include <iostream> 

#define n 2 // ����� ����� 
#define m 3 // ����� �������� 

using namespace std;

int mas(int[][m], int, int); // �������� �������  
/*
int main()
{
	setlocale(LC_CTYPE, "");

	int y[n][m], i, j, min;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << "\n ������� y[" << i << "][" << j << "] = ";
			cin >> y[i][j]; // ���� ������� 
		}
	}

	min = mas(y, n, m); // ��������� � ������� � ��������� ���������� 
	cout << "\n\n ����������� ���������� = " << min << endl;

	return 0;
}*/

int mas(int x[][m], int k, int d) // ��������� ������� 
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
