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
        0,
        10,
        {2015, 8, 15},
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
        {2013, 5, 10},
    };

    //game_t game = { 0 };
    //fill_game_data(&game);

    print_game_disk_header();
    print_game_disk(game1);
    print_game_disk(game2);
}
void fill_game_data(game_t* game) {
    printf("\n ������� ������ �� ����:\n\n");

    printf(" �������� = ");
    fgets(game->name, sizeof(game->name), stdin);
    game->name[strcspn(game->name, "\n")] = '\0';

    printf(" ��������� = ");
    fgets(game->platform, sizeof(game->platform), stdin);
    game->platform[strcspn(game->platform, "\n")] = '\0';

    printf(" ���� = ");
    fgets(game->genre, sizeof(game->genre), stdin);
    game->genre[strcspn(game->genre, "\n")] = '\0';

    printf(" ���������� ������� = ");
    fgets(game->age_rating, sizeof(game->age_rating), stdin);
    game->age_rating[strcspn(game->age_rating, "\n")] = '\0';

    printf(" ������ ����� = ");
    fgets(game->format, sizeof(game->format), stdin);
    game->format[strcspn(game->format, "\n")] = '\0';

    printf(" ���� ������ \n");
    printf(" ��� = ");
    scanf_s("%hu", &game->release_date.year);
    getchar();
    printf(" ����� = ");
    scanf_s("%hu", &game->release_date.month);
    getchar();
    printf(" ���� = ");
    scanf_s("%hu", &game->release_date.day);
    getchar();

    printf(" ������� = ");
    fgets(game->article, sizeof(game->article), stdin);
    game->article[strcspn(game->article, "\n")] = '\0';

    printf(" ���� = ");
    scanf_s("%f", &game->price);
    getchar();

    printf(" ������ = ");
    scanf_s("%hu", &game->discount);
    getchar();

    printf(" ���������� = ");
    scanf_s("%u", &game->count);
    getchar();
}

void print_game_disk_header() {
    printf("+----------------------+-----------+-------------+-----------+------------+-----------+---------+-----------+----------+----------------+\n");
    printf("| ��������             | ��������� | ���� ������ | ����, ��� | ���-��, �� | ����      | ������� | ������, %% | ������   | �������        |\n");
    printf("+----------------------+-----------+-------------+-----------+------------+-----------+---------+-----------+----------+----------------+\n");
}

void print_game_disk(const game_t disc) {
    char price_str[20], date_str[12];

    // ����������� ������ � �����
    sprintf(date_str, "%02hu-%02hu-%04hu", disc.release_date.day, disc.release_date.month, disc.release_date.year);
    // ����������� ����
    float final_price = disc.price * (1 - (disc.discount / 100.0));
    sprintf(price_str, "%.2f", final_price);

    // ����� ������
    printf("| %-20s | %-9s | %-11s | %-9s | %-10u | %-9s | %-7s | %-9hu | %-8s | %-14s |\n",
        disc.name, disc.platform, date_str, price_str, disc.count,
        disc.genre, disc.age_rating, disc.discount, disc.format, disc.article);

    printf("+----------------------+-----------+-------------+-----------+------------+-----------+---------+-----------+----------+----------------+\n");
}

/*
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
}*/
