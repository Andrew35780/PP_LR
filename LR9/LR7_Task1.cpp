#include <stdio.h>

inline void CalculateDaysUntilTargetDistance()
{
    float S, P, R;

    printf("\n¬ведите начальное рассто€ние (S) в км: ");
    scanf_s("%f", &S);
    printf("¬ведите процент увеличени€ (P): ");
    scanf_s("%f", &P);
    printf("¬ведите целевое рассто€ние (R) в км: ");
    scanf_s("%f", &R);

    int days = 0;
    while (S < R)
    {
        S += S * (P / 100);
        days++;
    }

    printf("\n—портсмен будет пробегать %.2f км через %d дней\n", R, days);
}
