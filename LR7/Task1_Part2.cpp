#include <iostream>
#include <locale.h>
#include <stdio.h>


void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    float S, P, R;

    printf("\n¬ведите начальное рассто€ние (S) в км: ");
    scanf_s("%f", &S);
    printf("¬ведите процент увеличени€ (P): ");
    scanf_s("%f", &P);
    printf("¬ведите целевое рассто€ние (R) в км: ");
    scanf_s("%f", &R);

    int days = 0;
    do
    {
        S += S * (P / 100);
        days++;
    } while (S < R);

    printf("\n—портсмен будет пробегать %.2f км через %d дней\n", R, days);
}
