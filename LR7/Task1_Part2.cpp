#include <iostream>
#include <locale.h>
#include <stdio.h>


void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    float S, P, R;

    printf("\n������� ��������� ���������� (S) � ��: ");
    scanf_s("%f", &S);
    printf("������� ������� ���������� (P): ");
    scanf_s("%f", &P);
    printf("������� ������� ���������� (R) � ��: ");
    scanf_s("%f", &R);

    int days = 0;
    do
    {
        S += S * (P / 100);
        days++;
    } while (S < R);

    printf("\n��������� ����� ��������� %.2f �� ����� %d ����\n", R, days);
}
