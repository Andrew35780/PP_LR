#include <iostream>
#include <locale.h>
#include <stdio.h>

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int m;
    printf("\nВведите количество чисел (m): ");
    scanf_s("%d", &m);

    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    for (int i = 1; i <= m; i++) {
        float number;
        printf("Введите число %d: ", i);
        scanf_s("%f", &number);

        if (number > 0) positiveCount++;
        else if (number < 0) negativeCount++;
        else zeroCount++;

    }

    printf("\nПоложительных чисел: %d\n", positiveCount);
    printf("Отрицательных чисел: %d\n", negativeCount);
    printf("Нулей: %d\n", zeroCount);

    if (positiveCount > negativeCount && positiveCount > zeroCount) 
    {
        printf("\nБольше всего положительных чисел\n");
    }
    else if (negativeCount > positiveCount && negativeCount > zeroCount) 
    {
        printf("\nБольше всего отрицательных чисел\n");
    }
    else if (zeroCount > positiveCount && zeroCount > negativeCount) 
    {
        printf("\nБольше всего нулей\n");
    }
    else 
    {
        printf("\nКоличество чисел равно между категориями\n");
    }
}
