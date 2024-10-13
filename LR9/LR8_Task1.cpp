#include <stdio.h>

inline void CalculateSumCountAndProductOfNumbers()
{
    int n;

    printf("\nВведите кол-во чисел (n): ");
    scanf_s("%d", &n);
    printf("\n");

    int positiveSum = 0, positiveCount = 0, totalProduct = 1;
    
    for (int i = 1; i <= n; i++)
    {
        int number;

        printf("Введите целое число: ");
        scanf_s("%d", &number);

        totalProduct *= number;

        if (number > 0)
        {
            positiveSum += number;
            positiveCount++;
        }
    }

    printf("\nСумма положительных чисел = %d\n", positiveSum);
    printf("Количество положительных чисел = %d\n", positiveCount);
    printf("Произведение всех чисел = %d\n", totalProduct);
}
