#include "Task.h"

int main()
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

    //write_data_to_file("file.txt", game1, "w");
    write_data_to_file("file.txt", game2, "a");
    print_data_from_file("file.txt");

	return 0;
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
}