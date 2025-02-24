#include "Task.h"

//int select_game_by_year(const char* orig_file_name, const char* new_file_name);
void write_data_to_file_simple(const char* mode);
int select_game_by_year_simple(const char* orig_file_name, const char* new_file_name);
void print_game_disc(const game_t disc);

int main()
{
	setlocale(LC_CTYPE, "");
	//system("color f0");

	game_t game1 = {
		"The Witcher 3",
		"PC",
		"RPG",
		"18+",
		"DVD",
		1000.0,
		0,
		{2015, 8, 15},
		10,
		"W3-PC-2015",
	};

	game_t game2 = {
		"Bioshock Infinite",
		"PS4",
		"Shooter",
		"18+",
		"Blue-Ray",
		500.0,
		30,
		{2013, 5, 10},
		5,
		"BI-PS4-2013",
	};

	//game_t game3; //game_temp for writing in cycle
	//fill_game_data(&game3);

	while (1) {
		system("cls");

		printf("\n 1: Запись данных\n");
		printf(" 2: Дополнение данных\n");
		printf(" 3: Чтение данных\n");
		printf(" 4: Отбор по году\n");
		//printf(" 5: Отбор по введённому слову из названия\n");
		printf(" 5: Закончить работу\n");
		printf("\n Выберите операцию: ");

		int choise;
		scanf_s("%d", &choise);
		getchar(); // Избавляемся от оставшегося /n

		switch ((operation)choise)
		{
		case WriteData:
			//write_data_to_file("file.txt", "w");

			write_data_to_file_simple("w");
			break;
		case AddData:
			//write_data_to_file("simple_file.txt", "a");

			write_data_to_file_simple("a");
			break;
		case ReadData:
			system("cls");
			print_data_from_file("simple_file.txt");
			printf("\n");
			system("pause");
			break;
		case SelectByYear:
			//select_game_by_year("file.txt", "sorted_file.txt");

			select_game_by_year_simple("simple_file.txt", "sorted_file.txt");
			system("pause");
			break;
		case FinishWork:
			return 0;
		default:
			printf("\n Вы ввели несуществующую операцию!\n");
		}
	}

	return 0;
}

/*
int select_game_by_year(const char* orig_file_name, const char* new_file_name) {
	FILE* origFile;
	FILE* newFile;

	if (fopen_s(&origFile, orig_file_name, "r") != 0) {
		printf("\n Ошибка открытия файла %s !\n", orig_file_name);
		return ERROR_FILE_OPPENING;
	}
	if (fopen_s(&newFile, new_file_name, "w") != 0) {
		fclose(origFile);
		printf("\n Ошибка открытия файла %s !\n", new_file_name);
		return ERROR_FILE_OPPENING;
	}

	unsigned short sort_year;
	printf("\n Старше какого года должна быть игра? = ");
	scanf_s("%hu", &sort_year);

	game_t game;
	int game_found = 0;

	// Читаем игры из исходного файла
	while (fscanf_s(origFile,
		"+----------------------+--------------------------------+\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30hu |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30u |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30s |\n"
		"| %-20s | %-30s |\n"
		"+----------------------+--------------------------------+\n",
		game.name, game.platform, game.genre, game.age_rating,
		&game.release_year, game.article, &game.price, &game.discount,
		&game.count, &game.is_used) == 10) {

		printf("Что-то прочитали...");
		// Проверяем, если год релиза игры больше указанного
		if (game.release_year > sort_year) {
			game_found = 1;

			// Записываем отфильтрованные игры в новый файл
			fprintf(newFile, "+----------------------+--------------------------------+\n");
			fprintf(newFile, "| %-20s | %-30s |\n", "Название", game.name);
			fprintf(newFile, "| %-20s | %-30s |\n", "Платформа", game.platform);
			fprintf(newFile, "| %-20s | %-30hu |\n", "Год выпуска", game.release_year);
			fprintf(newFile, "| %-20s | %-30.2f руб. |\n", "Цена", game.price);
			fprintf(newFile, "| %-20s | %-30s |\n", "Состояние", game.is_used ? "Б/У" : "Новый");
			fprintf(newFile, "| %-20s | %-30u |\n", "Количество", game.count);
			fprintf(newFile, "| %-20s | %-30s |\n", "Жанр", game.genre);
			fprintf(newFile, "| %-20s | %-30s |\n", "Возрастной рейтинг", game.age_rating);
			fprintf(newFile, "| %-20s | %-30.1f%% |\n", "Скидка", game.discount);
			fprintf(newFile, "| %-20s | %-30s |\n", "Артикул", game.article);
			fprintf(newFile, "+----------------------+--------------------------------+\n");

			// Также выводим на экран
			printf("+----------------------+--------------------------------+\n");
			printf("| %-20s | %-30s |\n", "Название", game.name);
			printf("| %-20s | %-30s |\n", "Платформа", game.platform);
			printf("| %-20s | %-30hu |\n", "Год выпуска", game.release_year);
			printf("| %-20s | %-30.2f руб. |\n", "Цена", game.price);
			printf("| %-20s | %-30s |\n", "Состояние", game.is_used ? "Б/У" : "Новый");
			printf("| %-20s | %-30u |\n", "Количество", game.count);
			printf("| %-20s | %-30s |\n", "Жанр", game.genre);
			printf("| %-20s | %-30s |\n", "Возрастной рейтинг", game.age_rating);
			printf("| %-20s | %-30.1f%% |\n", "Скидка", game.discount);
			printf("| %-20s | %-30s |\n", "Артикул", game.article);
			printf("+----------------------+--------------------------------+\n");
		}
	}

	fclose(origFile);
	fclose(newFile);

	// Если были отобраны игры
	return game_found;
}*/

int select_game_by_year_simple(const char* orig_file_name, const char* new_file_name) {
	FILE* origFile;
	FILE* newFile;

	if (fopen_s(&origFile, orig_file_name, "r") != 0) {
		printf("\n Ошибка открытия файла %s !\n", orig_file_name);
		return ERROR_FILE_OPPENING;
	}
	if (fopen_s(&newFile, new_file_name, "w") != 0) {
		fclose(origFile);
		printf("\n Ошибка открытия файла %s !\n", new_file_name);
		return ERROR_FILE_OPPENING;
	}

	unsigned short sort_year;
	printf("\n Старше какого года должна быть игра? = ");
	scanf_s("%hu", &sort_year);

	game_t game = { 0 };
	int game_found = 0;

	// Читаем игры из исходного файла
	while (!feof(origFile))
	{
		char price_str[20], date_str[12];

		fscanf(origFile, "%s %s %s %s %s %s %s %f %hu %u", 
			game.name, game.platform, game.genre, game.age_rating, 
			game.format, date_str, game.article, &game.price, 
			&game.discount, &game.count); // Почему такой порядок??

		printf("\n+----------------------+-----------+-------------+-----------+------------+-----------+---------+-----------+----------+----------------+\n");

		// Преобразуем строку с датой в структуру
		sscanf_s(date_str, "%hu-%hu-%hu", &game.release_date.day, &game.release_date.month, &game.release_date.year);

		print_game_disc(game);
		// Проверяем, если год релиза игры больше указанного
		

			// Записываем отфильтрованные игры в новый файл
			

			// Также выводим на экран
			
		
	}

	fclose(origFile);
	fclose(newFile);

	// Если были отобраны игры
	return game_found;
}

void print_game_disc(const game_t game) {
	char price_str[20], date_str[12];

	// Форматируем строку с датой
	sprintf(date_str, "%02hu-%02hu-%04hu", game.release_date.day, game.release_date.month, game.release_date.year);
	// Форматируем цену
	float final_price = game.price * (1 - (game.discount / 100.0));
	sprintf(price_str, "%.2f", final_price);

	// Вывод данных
	printf("| %-20s | %-9s | %-11s | %-9s | %-10u | %-9s | %-7s | %-9hu | %-8s | %-14s |\n",
		game.name, game.platform, date_str, price_str, game.count,
		game.genre, game.age_rating, game.discount, game.format, game.article);

	printf("+----------------------+-----------+-------------+-----------+------------+-----------+---------+-----------+----------+----------------+\n");
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

	printf(" Дата релиза \n");
	printf(" Год = ");
	scanf_s("%hu", &game->release_date.year);
	getchar();
	printf(" Месяц = ");
	scanf_s("%hu", &game->release_date.month);
	getchar();
	printf(" День = ");
	scanf_s("%hu", &game->release_date.day);
	getchar();

	printf(" Артикул = ");
	fgets(game->article, sizeof(game->article), stdin);
	game->article[strcspn(game->article, "\n")] = '\0';

	printf(" Цена = ");
	scanf_s("%f", &game->price);
	getchar();

	printf(" Скидка = ");
	scanf_s("%hu", &game->discount);
	getchar();

	printf(" Количество = ");
	scanf_s("%u", &game->count);
	getchar();
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

/*
// New Func
int write_data_to_file(const char* file_name, const char* mode) {
	FILE* file;

	if (fopen_s(&file, file_name, mode) != 0)
		return ERROR_FILE_OPPENING;

	char answ = 'y';
	while (answ != 'n') {
		system("cls");

		game_t disc = { 0 };
		fill_game_data(&disc);

		char price_str[50], discount_str[50];

		// Формируем строки для цены и скидки с единицами измерения
		float final_price = disc.discount == 0 ? disc.price :
			disc.price * (1 - (disc.discount / 100));
		sprintf_s(price_str, "%.2f руб.", final_price);
		sprintf_s(discount_str, "%.1f%%", disc.discount);

		fprintf_s(file, "\n");
		fprintf_s(file, "+----------------------+--------------------------------+\n");
		fprintf_s(file, "| %-20s | %-30s |\n", "Название", disc.name);
		fprintf_s(file, "| %-20s | %-30s |\n", "Платформа", disc.platform);
		fprintf_s(file, "| %-20s | %-30hu |\n", "Год выпуска", disc.release_year);
		fprintf_s(file, "| %-20s | %-30s |\n", "Цена", price_str);
		fprintf_s(file, "| %-20s | %-30s |\n", "Состояние", disc.is_used ? "Б/У" : "Новый");
		fprintf_s(file, "| %-20s | %-30u |\n", "Количество", disc.count);
		fprintf_s(file, "| %-20s | %-30s |\n", "Жанр", disc.genre);
		fprintf_s(file, "| %-20s | %-30s |\n", "Возрастной рейтинг", disc.age_rating);
		fprintf_s(file, "| %-20s | %-30s |\n", "Скидка", discount_str);
		fprintf_s(file, "| %-20s | %-30s |\n", "Формат", disc.format);
		fprintf_s(file, "| %-20s | %-30s |\n", "Артикул", disc.article);
		fprintf_s(file, "+----------------------+--------------------------------+\n");

		printf("\n Хотите записать что-то ещё (y/n)? ");
		answ = getchar();
		getchar();
	}

	fclose(file);

	return SUCCESS;
}*/

void write_data_to_file_simple(const char* mode) {
	FILE* file;

	fopen_s(&file, "simple_file.txt", mode);

	char answ = 'y';
	while (answ != 'n') {
		system("cls");

		game_t game;
		fill_game_data(&game);

		//char price_str[50];
		char price_str[20], date_str[12];

		// Форматируем строку с датой
		sprintf(date_str, "%02hu-%02hu-%04hu", game.release_date.day, game.release_date.month, game.release_date.year);

		// Формируем строки для цены
		float final_price = game.discount == 0 ? game.price :
			game.price * (1 - (game.discount / 100));
		sprintf(price_str, "%.2f", final_price);

		//fprintf_s(file, "\n");
		fprintf_s(file, "%-20s ", game.name);
		fprintf_s(file, "%-9s ", game.platform);
		fprintf_s(file, "%-9s ", game.genre);
		fprintf_s(file, "%-7s ", game.age_rating);
		fprintf_s(file, "%-8s ", game.format);
		fprintf_s(file, "%-11s ", date_str);
		fprintf_s(file, "%-14s ", game.article);
		fprintf_s(file, "%-9s ", price_str);
		fprintf_s(file, "%-9hu ", game.discount);
		fprintf_s(file, "%-10u\n", game.count);

		printf("\n Хотите записать что-то ещё (y/n)? ");
		answ = getchar();
		getchar();
	}
}

//TODO: поменять порядок заполнения полей структуры
// Добавить сообщение об ошибке открытия файла в функциях!
// Возможно, что ошибка чтения из файла в: неправильных спецификаторах, неправильных размерах или их наличии, нахождение данных на разных строках, неправильное количество форматных строк и аргументов для записи, попытка записи строк в числовые поля
// Скорее всего, придётся записывать в файл данные в "сыром" виде, а потом добавлять их к таблице на выводе!
