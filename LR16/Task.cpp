#include <stdbool.h>
#include <iomanip>
#include <iostream>
#include "Task.h"

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    game_t game1 = {
        "The Witcher 3",
        "PC",
        "RPG",
        "18+",
        "DVD",
        "W3-PC-2015",
        1000.0,
        0.0,
        10,
        2015,
        false
    };

    game_t game2 = {
        "Bioshock Infinite",
        "PS4",
        "Shooter",
        "18+",
        "Blu-Ray",
        "BI-PS4-2013",
        500.0,
        30.0,
        5,
        2013,
        true
    };

    print_game_disk(game1);
    print_game_disk(game2);
}

void print_game_disk(const game_t disc) {
    char price_str[50], discount_str[50];

    // ��������� ������ ��� ���� � ������ � ��������� ���������
    float final_price = disc.discount == 0 ? disc.price : 
        disc.price * (1 - (disc.discount / 100));
    sprintf_s(price_str, "%.2f ���.", final_price);
    sprintf_s(discount_str, "%.1f%%", disc.discount);

    printf("\n");
    printf("+----------------------+--------------------------------+\n");
    printf("| %-20s | %-30s |\n", "��������", disc.name);
    printf("| %-20s | %-30s |\n", "���������", disc.platform);
    printf("| %-20s | %-30hu |\n", "��� �������", disc.release_year);
    printf("| %-20s | %-30s |\n", "����", price_str);
    printf("| %-20s | %-30s |\n", "���������", disc.is_used ? "�/�" : "�����");
    printf("| %-20s | %-30u |\n", "����������", disc.count);
    printf("| %-20s | %-30s |\n", "����", disc.genre);
    printf("| %-20s | %-30s |\n", "���������� �������", disc.age_rating);
    printf("| %-20s | %-30s |\n", "������", discount_str);
    printf("| %-20s | %-30s |\n", "������", disc.format);
    printf("| %-20s | %-30s |\n", "�������", disc.article);
    printf("+----------------------+--------------------------------+\n");
}