#include <iostream>
#include <locale.h>
#include <stdio.h>

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int m;
    printf("\n������� ���������� ����� (m): ");
    scanf_s("%d", &m);

    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    for (int i = 1; i <= m; i++) {
        float number;
        printf("������� ����� %d: ", i);
        scanf_s("%f", &number);

        if (number > 0) positiveCount++;
        else if (number < 0) negativeCount++;
        else zeroCount++;

    }

    printf("\n������������� �����: %d\n", positiveCount);
    printf("������������� �����: %d\n", negativeCount);
    printf("�����: %d\n", zeroCount);

    if (positiveCount > negativeCount && positiveCount > zeroCount) 
    {
        printf("\n������ ����� ������������� �����\n");
    }
    else if (negativeCount > positiveCount && negativeCount > zeroCount) 
    {
        printf("\n������ ����� ������������� �����\n");
    }
    else if (zeroCount > positiveCount && zeroCount > negativeCount) 
    {
        printf("\n������ ����� �����\n");
    }
    else 
    {
        printf("\n���������� ����� ����� ����� �����������\n");
    }
}
