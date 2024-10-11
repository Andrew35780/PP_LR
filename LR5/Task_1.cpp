#include <stdio.h> 
#include <iostream>
#include <locale.h>

using namespace std;
/*
void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    char type;
    int time, price;

    printf("Введите вид перевода (E K R): ");
    type = getchar();
    
    printf("Введите время перевода: ");
    scanf_s("%d", &time);

    if (type == 'E' && time <= 270)
        price = 1700;
    else if (type == 'K' && time <= 390)
        price = 3500;
    else if (type == 'R' && time <= 540)
        price = 5000;
    else
    {
        printf("\nНеправильный вид или время перевода\n");
        exit(-1);
    }
    
    printf("\nЦена = %d\n", price);
}
*/