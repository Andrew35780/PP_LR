#include <iostream>
#include <stdio.h>
#include <locale.h>

void PrintHead();
void PrintBody(float* rubles, float const dollarCourse);
void PrintTail();

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    float dollarCourse, rubles;

    printf("Введите текущий курс доллара к рублю: ");
    scanf_s("%f", &dollarCourse);
    system("cls");

    PrintHead();
    PrintBody(&rubles, dollarCourse);
    PrintTail();  
}

void PrintHead() {
    printf("\n    Таблица перевода долларов в рубли  \n");

    for (short i = 0; i <= 40; i++) printf("*");
    printf("\n|     Доллары       |       Рубли       |\n");

    PrintTail();
}

void PrintBody(float* rubles, float const dollarCourse) {
    for (short dollars = 15; dollars <= 105; dollars += 10)
    {
        *rubles = dollars * dollarCourse;

        printf("| %17d | %17.2f |\n", dollars, *rubles);
    }
}

void PrintTail() {
    for (short i = 0; i <= 40; i++) printf("-");
    printf("\n");
}