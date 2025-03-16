#include <iostream> 

#define N 3 
#define M 4 

using namespace std;
/*
int main()
{
    setlocale(LC_CTYPE, "");

    int a[N][M], b[M], min, * p;
    int i, j;

    p = &a[0][0]; // Инициализация указателя адресом первой ячейки 

    cout << "\n Введите данные в массив a["<< N <<"][" << M << "]:\n\n";
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < M; j++)
        {
            cout << " a[" << i << "][" << j << "] = ";
            cin >> *(p + i * M + j); // Ввод массива 
        }
    }

    // Расчет массива b[2] 
    for (j = 0; j < M; j++) // Цикл по столбцам 
    {
        min = *(p + j);   // Присваивание min значения первого элемента столбца 

        for (i = 1; i < N; i++) // Цикл по строкам, начиная со второго элемента 
            if ((*(p + i * M + j)) < min)   
                min = *(p + i * M + j);

        *(b + j) = min;
    }

    cout << "\n\n Вывод исходного массива a[" << N << "][" << M << "]:";
    for (i = 0; i < N; i++)
    {
        cout << "\n";
        for (j = 0; j < M; j++)
            cout << "\t" << *(p + i * M + j);
    }

    cout << "\n\n Вывод полученного массива b["<< M << "]:\n";
    for (j = 0; j < M; j++)
        cout << "\t" << *(b + j);
    cout << "\n\n";

    system("PAUSE");
}*/
