#include <iostream>
#include <stdio.h>
#include <locale.h>

#include "LR7_Task1.cpp"
#include "LR8_Task1.cpp"
#include "LR8_Task2.cpp"

int main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    short choise;
    while (true) 
    {
        printf("\n1. ЛР8 Задание 1\n");
        printf("2. ЛР8 Задание 2\n");
        printf("3. ЛР7 Задание 1\n");
        printf("4. Завершить работу программы\n");
        printf("\nВыберите 1, 2, 3 или 4: ");
        scanf_s("%hd", &choise);
        printf("\n");

        switch (choise)
        {
        case 1:
            CalculateSumCountAndProductOfNumbers();
            break;
        case 2:
            CalculatePosNegZeroNumbers();
            break;
        case 3:
            CalculateDaysUntilTargetDistance();
            break;
        case 4:
            exit(0);
        default:
            printf("\nТакого варианта не существует\n");
        }

        printf("\n");
    }
    
    return 0;
}
