#include <locale.h>
#include <iostream>
#define n 15

using namespace std;
/*
void main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	int i, array[n];

	cout << "\n";
	for (i = 0; i < n; i++) {
		cout << " Введите " << i + 1 << " элемент массива : " << "\n ";
		cin >> array[i];
	}

	cout << "\n" << " Вывод элементов исходного массива: " << endl;
	for (i = 0; i < n; i++) printf("%4d", array[i]);
	cout << "\n" << endl;;

	int positiveProduct = 1, negativeProduct = 1;
	for (i = 0; i < n; i++) {
		if (array[i] > 0)
			positiveProduct *= array[i];
		else if (array[i] < 0)
			negativeProduct *= array[i];
	}

	if (positiveProduct > negativeProduct)
		cout << " Положительное произведение больше отрицательного" << "\n" << endl;
	else
		cout << " Отрицательное произведение больше положительного" << "\n" << endl;

	cout << " Положительное произведение = " << positiveProduct << endl;
	cout << " Отрицательное произведение = " << negativeProduct << endl;
}
*/