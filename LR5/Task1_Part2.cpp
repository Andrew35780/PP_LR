#include <stdio.h> 
#include <iostream>
#include <locale.h>

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    int translations1, translations2, translations3;

    printf("\n������� ���������� ��������� ���� �����������: ");
    scanf_s("%d %d %d", &translations1, &translations2, &translations3);

    float avgTranslations = (translations1 + translations2 + translations3) / 3.0;

    int minTranslations = translations1;
    int maxTranslations = translations1;

    if (translations2 < minTranslations) minTranslations = translations2;
    if (translations2 > maxTranslations) maxTranslations = translations2;

    if (translations3 < minTranslations) minTranslations = translations3;
    if (translations3 > maxTranslations) maxTranslations = translations3;

    printf("\n������� ���������� ���������: %.2f\n", avgTranslations);
    printf("����������� ���������� ���������: %d\n", minTranslations);
    printf("������������ ���������� ���������: %d\n", maxTranslations);
}
