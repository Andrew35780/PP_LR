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

    p = &a[0][0]; // ������������� ��������� ������� ������ ������ 

    cout << "\n ������� ������ � ������ a["<< N <<"][" << M << "]:\n\n";
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < M; j++)
        {
            cout << " a[" << i << "][" << j << "] = ";
            cin >> *(p + i * M + j); // ���� ������� 
        }
    }

    // ������ ������� b[2] 
    for (j = 0; j < M; j++) // ���� �� �������� 
    {
        min = *(p + j);   // ������������ min �������� ������� �������� ������� 

        for (i = 1; i < N; i++) // ���� �� �������, ������� �� ������� �������� 
            if ((*(p + i * M + j)) < min)   
                min = *(p + i * M + j);

        *(b + j) = min;
    }

    cout << "\n\n ����� ��������� ������� a[" << N << "][" << M << "]:";
    for (i = 0; i < N; i++)
    {
        cout << "\n";
        for (j = 0; j < M; j++)
            cout << "\t" << *(p + i * M + j);
    }

    cout << "\n\n ����� ����������� ������� b["<< M << "]:\n";
    for (j = 0; j < M; j++)
        cout << "\t" << *(b + j);
    cout << "\n\n";

    system("PAUSE");
}*/
