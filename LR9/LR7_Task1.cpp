#include <stdio.h>

inline void CalculateDaysUntilTargetDistance()
{
    float S, P, R;

    printf("\n������� ��������� ���������� (S) � ��: ");
    scanf_s("%f", &S);
    printf("������� ������� ���������� (P): ");
    scanf_s("%f", &P);
    printf("������� ������� ���������� (R) � ��: ");
    scanf_s("%f", &R);

    int days = 0;
    while (S < R)
    {
        S += S * (P / 100);
        days++;
    }

    printf("\n��������� ����� ��������� %.2f �� ����� %d ����\n", R, days);
}
