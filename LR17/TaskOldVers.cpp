#include "Task.h"
/*
int main()
{
    setlocale(LC_CTYPE, "");

    while (1) {
        system("cls");

        printf("\n 1: Запись данных\n");
        printf(" 2: Дополнение данных\n");
        printf(" 3: Чтение данных\n");
        //printf(" 4: Отбор по году\n");
        //printf(" 5: Отбор по введённому слову из названия\n");
        printf(" 4: Закончить работу\n");
        printf("\n Выберите операцию: ");

        int choise;
        scanf_s("%d", &choise);
        getchar(); // Избавляемся от оставшегося /n

        switch ((operation)choise)
        {
        case WriteData: {
            char answ = 'y';
            while (answ != 'n') {
                system("cls");

                game_t game = { 0 };
                fill_game_data(&game);
                write_data_to_file("file.txt", game, "a");

                printf("\n Хотите записать что-то ещё (y/n)? ");
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
            printf("\n Вы ввели несуществующую операцию!\n");
        }
    }

    return 0;
}

void fill_game_data(game_t* game) {
    printf("\n Введите данные об игре:\n\n");

    printf(" Название = ");
    fgets(game->name, sizeof(game->name), stdin);
    game->name[strcspn(game->name, "\n")] = '\0';

    printf(" Платформа = ");
    fgets(game->platform, sizeof(game->platform), stdin);
    game->platform[strcspn(game->platform, "\n")] = '\0';

    printf(" Жанр = ");
    fgets(game->genre, sizeof(game->genre), stdin);
    game->genre[strcspn(game->genre, "\n")] = '\0';

    printf(" Возрастной рейтинг = ");
    fgets(game->age_rating, sizeof(game->age_rating), stdin);
    game->age_rating[strcspn(game->age_rating, "\n")] = '\0';

    printf(" Формат диска = ");
    fgets(game->format, sizeof(game->format), stdin);
    game->format[strcspn(game->format, "\n")] = '\0';

    printf(" Дата релиза = ");
    scanf_s("%hu", &game->release_year);
    getchar();

    printf(" Артикул = ");
    fgets(game->article, sizeof(game->article), stdin);
    game->article[strcspn(game->article, "\n")] = '\0';

    printf(" Цена = ");
    scanf_s("%f", &game->price);
    getchar(); // Очищаем \n из буфера

    printf(" Скидка = ");
    scanf_s("%f", &game->discount);
    getchar();

    printf(" Количество = ");
    scanf_s("%u", &game->count);
    getchar();

    printf(" Состояние (0 - Новая, 1 - Б/У) = ");
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

    // Формируем строки для цены и скидки с единицами измерения
    float final_price = game.discount == 0 ? game.price :
        game.price * (1 - (game.discount / 100));
    sprintf_s(price_str, "%.2f руб.", final_price);
    sprintf_s(discount_str, "%.1f%%", game.discount);

    fprintf_s(file, "\n");
    fprintf_s(file, "+----------------------+--------------------------------+\n");
    fprintf_s(file, "| %-20s | %-30s |\n", "Название", game.name);
    fprintf_s(file, "| %-20s | %-30s |\n", "Платформа", game.platform);
    fprintf_s(file, "| %-20s | %-30hu |\n", "Год выпуска", game.release_year);
    fprintf_s(file, "| %-20s | %-30s |\n", "Цена", price_str);
    fprintf_s(file, "| %-20s | %-30s |\n", "Состояние", game.is_used ? "Б/У" : "Новый");
    fprintf_s(file, "| %-20s | %-30u |\n", "Количество", game.count);
    fprintf_s(file, "| %-20s | %-30s |\n", "Жанр", game.genre);
    fprintf_s(file, "| %-20s | %-30s |\n", "Возрастной рейтинг", game.age_rating);
    fprintf_s(file, "| %-20s | %-30s |\n", "Скидка", discount_str);
    fprintf_s(file, "| %-20s | %-30s |\n", "Формат", game.format);
    fprintf_s(file, "| %-20s | %-30s |\n", "Артикул", game.article);
    fprintf_s(file, "+----------------------+--------------------------------+\n");

    fclose(file);

    return SUCCESS;
}*/