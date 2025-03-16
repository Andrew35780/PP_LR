// Пример 1
/*
#include <iostream> 
#define n 5 

using namespace std;

int vec(int[], int); // Прототип функции вычисления min компоненты вектора 

int main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int y[n], i, min;

    for (i = 0; i < n; i++)
    {
        cout << "\n Введите y[" << i << "] = ";
        cin >> y[i]; // Ввод элементов вектора 
    }

    min = vec(y, n); // Вызывающая функция 
    cout << "\n\n Минимальная компонента = " << min << endl;

    return 0;
}

int vec(int x[], int k) // Заголовок функции 
{
    int min1 = x[0]; 
    int i;

    for (i = 1; i < k; i++)
    {
        if (x[i] < min1) 
            min1 = x[i];
    }

    return min1;
}
*/


// Пример 3
/*
#include <iostream> 

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int a[5], sum = 0, *p;
    int kol = 0, i;

    p = &a[0]; // инициализация указателя адресом первого элемента 

    cout << "\n Ввод данных в массив a[ ]\n";
    for (i = 0; i < 5; i++)
    {
        cout << " a[" << i << "] = ";
        cin >> *(p + i);  // разыменовывание смещенного указателя 
    }

    // расчет суммы и количества положительных элементов 
    for (i = 0; i < 5; i++) 
    {
        if (*(p + i) > 0)
        {
            sum += *(p + i);
            kol++;
        }
    }

    // вывод исходных данных и результатов 
    cout << "\n\n\n Элемент массива  Адрес элемента массива \n";
    for (i = 0; i < 5; i++)
    {
        cout << " " << * (p + i) << "\t\t  " << (p + i) << "\n"; // вывод результатов с пробелами
    }

    cout << "\n Сумма = " << sum << "\n Количество = " << kol;
    cout << "\n\n";
}
*/


// Пример 5
/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h> // Содержит прототипы функций для работы с ГСЧ
#include <conio.h>
#include <time.h> // Содержит прототипы функций для работы со временем
#include <locale.h>

#define n 5

using namespace std;

// Функция ввода элементов матрицы с клавиатуры
void input_matrix(int a[n][n]) 
{
    int i, j;

    printf("Введите элементы матрицы A: \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    }
}

// Функция заполнения матрицы случайными числами
void fill_matrix_random(int a[][n]) 
{
    int i, j;

    srand((unsigned)time(NULL)); // Инициализация ГСЧ
                                 // time() возвращает текущее время в секундах

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            a[i][j] = rand() % 50; // Генерируются значения элементов от 0 до 49
    }
}

// Функция вычисления элементов массива X
int* mas_x(int(*a)[n], int* x, void (*pfunc)(int[n][n])) 
{
    int i, j;

    // Вызов через указатель одной из двух функций ввода элементов a
    pfunc(a);

    for (i = 0, j = n - 1; i < n; i++, j--)
        x[i] = a[i][j];

    return x;
}

// Функция вывода на экран элементов матрицы a и массива x
void output(const int x[], const int a[][n]) 
{
    int i, j;

    printf("\n Матрица A:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    printf("\n Массив X:\n");
    for (i = 0; i < n; i++)
    {
        printf("%5d", x[i]);
        printf("\n");
    }
}

int main() 
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int a[n][n], x[n], c;

    void (*pfunc)(int[n][n]) = NULL;

    do
    {
        printf(" Ввод матрицы: \n1 - С клавиатуры\n2 - ГСЧ\n");
        scanf_s(" %d", &c);
    } 
    while (c != 1 && c != 2);

    // Присваивание указателю адреса одной из функции
    switch (c)
    {
    case 1:
        pfunc = &input_matrix;
        break;
    case 2:
        pfunc = &fill_matrix_random;
    }

    output(mas_x(a, x, pfunc), a);

    _getch();
}*/