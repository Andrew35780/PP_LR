#include "Task.h"
/*
int main()
{
    setlocale(LC_CTYPE, "");

    while (1) {
        system("cls");

        printf("\n 1: ������ ������\n");
        printf(" 2: ���������� ������\n");
        printf(" 3: ������ ������\n");
        //printf(" 4: ����� �� ����\n");
        //printf(" 5: ����� �� ��������� ����� �� ��������\n");
        printf(" 4: ��������� ������\n");
        printf("\n �������� ��������: ");

        int choise;
        scanf_s("%d", &choise);
        getchar(); // ����������� �� ����������� /n

        switch ((operation)choise)
        {
        case WriteData: {
            char answ = 'y';
            while (answ != 'n') {
                system("cls");

                game_t game = { 0 };
                fill_game_data(&game);
                write_data_to_file("file.txt", game, "a");

                printf("\n ������ �������� ���-�� ��� (y/n)? ");
                answ = getchar();
                getchar();
            }
            break;
        }
        case AddData:
            break;
        case ReadData:
            break;
        case FinishWork:
            return 0;
        default:
            printf("\n �� ����� �������������� ��������!\n");
        }
    }

    return 0;
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

    printf(" ���� ������ = ");
    scanf_s("%hu", &game->release_year);
    getchar();

    printf(" ������� = ");
    fgets(game->article, sizeof(game->article), stdin);
    game->article[strcspn(game->article, "\n")] = '\0';

    printf(" ���� = ");
    scanf_s("%f", &game->price);
    getchar(); // ������� \n �� ������

    printf(" ������ = ");
    scanf_s("%f", &game->discount);
    getchar();

    printf(" ���������� = ");
    scanf_s("%u", &game->count);
    getchar();

    printf(" ��������� (0 - �����, 1 - �/�) = ");
    int is_used_int;
    scanf_s("%d", &is_used_int);
    getchar();
    game->is_used = is_used_int;
}

int print_data_from_file(const char* file_name) {
    FILE* file;

    if (fopen_s(&file, file_name, "r") != 0)
        return ERROR_FILE_OPPENING;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
        printf("%s", buffer);

    fclose(file);

    return SUCCESS;
}

int write_data_to_file(const char* file_name, const game_t game, const char* mode) {
    FILE* file;

    if (fopen_s(&file, file_name, mode) != 0)
        return ERROR_FILE_OPPENING;

    char price_str[50], discount_str[50];

    // ��������� ������ ��� ���� � ������ � ��������� ���������
    float final_price = game.discount == 0 ? game.price :
        game.price * (1 - (game.discount / 100));
    sprintf_s(price_str, "%.2f ���.", final_price);
    sprintf_s(discount_str, "%.1f%%", game.discount);

    fprintf_s(file, "\n");
    fprintf_s(file, "+----------------------+--------------------------------+\n");
    fprintf_s(file, "| %-20s | %-30s |\n", "��������", game.name);
    fprintf_s(file, "| %-20s | %-30s |\n", "���������", game.platform);
    fprintf_s(file, "| %-20s | %-30hu |\n", "��� �������", game.release_year);
    fprintf_s(file, "| %-20s | %-30s |\n", "����", price_str);
    fprintf_s(file, "| %-20s | %-30s |\n", "���������", game.is_used ? "�/�" : "�����");
    fprintf_s(file, "| %-20s | %-30u |\n", "����������", game.count);
    fprintf_s(file, "| %-20s | %-30s |\n", "����", game.genre);
    fprintf_s(file, "| %-20s | %-30s |\n", "���������� �������", game.age_rating);
    fprintf_s(file, "| %-20s | %-30s |\n", "������", discount_str);
    fprintf_s(file, "| %-20s | %-30s |\n", "������", game.format);
    fprintf_s(file, "| %-20s | %-30s |\n", "�������", game.article);
    fprintf_s(file, "+----------------------+--------------------------------+\n");

    fclose(file);

    return SUCCESS;
}*/