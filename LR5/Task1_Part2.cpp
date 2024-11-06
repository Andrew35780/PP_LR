#include <stdio.h> 
#include <iostream>
#include <locale.h>

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int translations1, translations2, translations3;

    printf("\nВведите количество переводов трех сотрудников: ");
    scanf_s("%d %d %d", &translations1, &translations2, &translations3);

    float avgTranslations = (translations1 + translations2 + translations3) / 3.0;

    int minTranslations = translations1;
    int maxTranslations = translations1;

    if (translations2 < minTranslations) minTranslations = translations2;
    if (translations2 > maxTranslations) maxTranslations = translations2;

    if (translations3 < minTranslations) minTranslations = translations3;
    if (translations3 > maxTranslations) maxTranslations = translations3;

    printf("\nСреднее количество переводов: %.2f\n", avgTranslations);
    printf("Минимальное количество переводов: %d\n", minTranslations);
    printf("Максимальное количество переводов: %d\n", maxTranslations);
}
