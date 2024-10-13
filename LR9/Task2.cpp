#include <iostream>
#include <stdio.h>
#include <locale.h>

double FuncG(double a, double b);

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    double s, t;

    printf("\n¬ведите s и t: ");
    scanf_s("%lf %lf", &s, &t);

    double result = FuncG(1.2, s) + FuncG(t, s) - FuncG(2 * s - 1, s * t);

    printf("\ng(1.2,s) + g(s,t) - g(2s-1,st) = %lf\n", result);
}

double FuncG(double a, double b) 
{
    return ((a * a) + (b * b)) / ((a * a) + (2 * a * b) + (3 * b * b) + 4);
}
