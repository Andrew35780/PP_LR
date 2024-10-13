#include <stdio.h>

inline void CalculateSumCountAndProductOfNumbers()
{
    int n;

    printf("\n������� ���-�� ����� (n): ");
    scanf_s("%d", &n);
    printf("\n");

    int positiveSum = 0, positiveCount = 0, totalProduct = 1;
    
    for (int i = 1; i <= n; i++)
    {
        int number;

        printf("������� ����� �����: ");
        scanf_s("%d", &number);

        totalProduct *= number;

        if (number > 0)
        {
            positiveSum += number;
            positiveCount++;
        }
    }

    printf("\n����� ������������� ����� = %d\n", positiveSum);
    printf("���������� ������������� ����� = %d\n", positiveCount);
    printf("������������ ���� ����� = %d\n", totalProduct);
}
