#include "Task.h"

int main()
{
	setlocale(LC_CTYPE, "");
	system("color f0");

	while (1) {
		system("cls");

		printf("\n 1: ������ ������\n");
		printf(" 2: ���������� ������\n");
		printf(" 3: ������ ������\n");
		printf(" 4: ����� �� ����\n");
		printf(" 5: ����� �� ��������\n");
		printf(" 6: ��������� ������\n");
		printf("\n �������� ��������: ");

		int choise;
		scanf_s("%d", &choise);
		getchar(); // ����������� �� ����������� /n

		switch ((operation)choise)
		{
		case WriteData:
			write_data_to_file("simple_file.txt", "w");
			break;
		case AddData:
			write_data_to_file("simple_file.txt", "a");
			break;
		case ReadData:
			system("cls");
			print_data_from_file("simple_file.txt");
			printf("\n");
			system("pause");
			break;
		case SelectByYear:
			system("cls");
			select_game_by_year("simple_file.txt", "sorted_file.txt");
			system("pause");
			break;
		case FindByName:
			system("cls");
			find_record_in_file_by_name("simple_file.txt");
			system("pause");
			break;
		case FinishWork:
			return 0;
		default:
			printf("\n �� ����� �������������� ��������!\n");
		}
	}

	return 0;
}


int select_game_by_year(const char* orig_file_name, const char* new_file_name) {
	FILE* origFile;
	FILE* newFile;

	if (fopen_s(&origFile, orig_file_name, "r") != 0) {
		printf("\n ������ �������� ����� %s !\n", orig_file_name);
		return ERROR_FILE_OPPENING;
	}
	if (fopen_s(&newFile, new_file_name, "w") != 0) {
		fclose(origFile);
		printf("\n ������ �������� ����� %s !\n", new_file_name);
		return ERROR_FILE_OPPENING;
	}

	unsigned short sort_year;
	printf("\n ������ ������ ���� ������ ���� ����? = ");
	scanf_s("%hu", &sort_year);

	game_t game = { 0 };
	char date_str[12];
	int game_found = 0;

	// ������ ���� �� ��������� �����
	while (fscanf(origFile, "%s %s %s %s %s %f %hu %s %u %s",
		game.name, game.platform, game.genre, game.age_rating,
		game.format, &game.price, &game.discount, date_str,
		&game.count, game.article) == 10)
	{

		// ����������� ������ � ����� � ���������
		sscanf_s(date_str, "%hu-%hu-%hu", &game.release_date.day, &game.release_date.month, &game.release_date.year);

		// ���������, ���� ��� ������ ���� ������ ����������
		if (game.release_date.year > sort_year) {
			// ���������� ��������������� ���� � ����� ����
			fprintf(newFile, "%s %s %s %s %s %02u-%02u-%04u %s %.2f %hu %u\n",
				game.name, game.platform, game.genre, game.age_rating, game.format,
				game.release_date.day, game.release_date.month, game.release_date.year,
				game.article, game.price, game.discount, game.count);

			// ����� ������� �� �����
			printf("\n");
			print_game_table_header();
			print_game_data(game);

			game_found = 1;
		}
	}

	fclose(origFile);
	fclose(newFile);

	// ���� ���� �������� ����
	return game_found;
}

void print_game_data(const game_t game) {
	char date_str[12];

	// ����������� ������ � �����
	sprintf_s(date_str, "%02hu-%02hu-%04hu", game.release_date.day, game.release_date.month, game.release_date.year);

	// ����������� ����
	float final_price = game.price * (1 - (game.discount / 100.0));

	// ����� ������
	printf("| %-20s | %-9s | %-9s | %-7s | %-8s | %-11.2f | %-9hu | %-11s | %-10u | %-14s |\n",
		game.name, game.platform, game.genre, game.age_rating, game.format,
		game.price, game.discount, date_str, game.count, game.article);

	printf("+----------------------+-----------+-----------+---------+----------+-------------+-----------+-------------+------------+----------------+\n");
}

void print_game_table_header() {
	printf("+----------------------+-----------+-----------+---------+----------+-------------+-----------+-------------+------------+----------------+\n");
	printf("| ��������             | ��������� | ����      | ������� | ������   | ����, ���   | ������, %% | ���� ������ | ���-��, �� | �������        |\n");
	printf("+----------------------+-----------+-----------+---------+----------+-------------+-----------+-------------+------------+----------------+\n");
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

	printf(" ���� = ");
	scanf_s("%f", &game->price);
	getchar();

	printf(" ������ = ");
	scanf_s("%hu", &game->discount);
	getchar();

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

	printf(" ���������� = ");
	scanf_s("%u", &game->count);
	getchar();

	printf(" ������� = ");
	fgets(game->article, sizeof(game->article), stdin);
	game->article[strcspn(game->article, "\n")] = '\0';
}

int print_data_from_file(const char* file_name) {
	FILE* file;

	if (fopen_s(&file, file_name, "r") != 0) {
		printf("\n ������ �������� ����� %s !\n", file_name);
		return ERROR_FILE_OPPENING;
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file))
		printf("%s", buffer);

	fclose(file);

	return SUCCESS;
}

int write_data_to_file(const char* file_name, const char* mode) {
	FILE* file;

	if (fopen_s(&file, file_name, mode) != 0) {
		printf("\n ������ �������� ����� %s !\n", file_name);
		return ERROR_FILE_OPPENING;
	}

	char answ = 'y';
	while (answ != 'n') {
		system("cls");

		game_t game;
		fill_game_data(&game);

		char date_str[12];

		// ����������� ������ � �����
		sprintf_s(date_str, "%02hu-%02hu-%04hu", game.release_date.day, game.release_date.month, game.release_date.year);
		// ��������� ���� �� �������
		float final_price = game.price * (1 - (game.discount / 100.0));

		//fprintf_s(file, "\n");
		fprintf_s(file, "%-20s ", game.name);
		fprintf_s(file, "%-9s ", game.platform);
		fprintf_s(file, "%-9s ", game.genre);
		fprintf_s(file, "%-7s ", game.age_rating);
		fprintf_s(file, "%-8s ", game.format);
		fprintf_s(file, "%-11.2f ", final_price);
		fprintf_s(file, "%-9hu ", game.discount);
		fprintf_s(file, "%-11s ", date_str);
		fprintf_s(file, "%-10u ", game.count);
		fprintf_s(file, "%-14s\n", game.article);

		printf("\n ������ �������� ���-�� ��� (y/n)? ");
		answ = getchar();
		getchar();
	}

	fclose(file);

	return SUCCESS;
}

int find_record_in_file_by_name(const char* file_name) {
	FILE* file;

	if (fopen_s(&file, file_name, "r") != 0) {
		printf("\n ������ �������� ����� %s !\n", file_name);
		return ERROR_FILE_OPPENING;
	}

	game_t game = { 0 };
	int game_found = 0;
	char date_str[12];

	char game_name[100];
	printf("\n ������� �������� ������� ����: ");
	fgets(game_name, sizeof(game_name), stdin);
	game_name[strcspn(game_name, "\n")] = '\0';

	while (fscanf(file, "%s %s %s %s %s %f %hu %s %u %s",
		game.name, game.platform, game.genre, game.age_rating,
		game.format, &game.price, &game.discount, date_str,
		&game.count, game.article) == 10)
	{
		// ����������� ������ � ����� � ���������
		sscanf_s(date_str, "%hu-%hu-%hu", &game.release_date.day, &game.release_date.month, &game.release_date.year);

		// ���������, ���� �������� ���� ���������
		if (strcmp(game.name, game_name) == 0) {
			// ����� ������� �� �����
			printf("\n");
			print_game_table_header();
			print_game_data(game);

			game_found = SUCCESS;

			break;
		}
	}

	return game_found;
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

		// ��������� ������ ��� ���� � ������ � ��������� ���������
		float final_price = disc.discount == 0 ? disc.price :
			disc.price * (1 - (disc.discount / 100));
		sprintf_s(price_str, "%.2f ���.", final_price);
		sprintf_s(discount_str, "%.1f%%", disc.discount);

		fprintf_s(file, "\n");
		fprintf_s(file, "+----------------------+--------------------------------+\n");
		fprintf_s(file, "| %-20s | %-30s |\n", "��������", disc.name);
		fprintf_s(file, "| %-20s | %-30s |\n", "���������", disc.platform);
		fprintf_s(file, "| %-20s | %-30hu |\n", "��� �������", disc.release_year);
		fprintf_s(file, "| %-20s | %-30s |\n", "����", price_str);
		fprintf_s(file, "| %-20s | %-30s |\n", "���������", disc.is_used ? "�/�" : "�����");
		fprintf_s(file, "| %-20s | %-30u |\n", "����������", disc.count);
		fprintf_s(file, "| %-20s | %-30s |\n", "����", disc.genre);
		fprintf_s(file, "| %-20s | %-30s |\n", "���������� �������", disc.age_rating);
		fprintf_s(file, "| %-20s | %-30s |\n", "������", discount_str);
		fprintf_s(file, "| %-20s | %-30s |\n", "������", disc.format);
		fprintf_s(file, "| %-20s | %-30s |\n", "�������", disc.article);
		fprintf_s(file, "+----------------------+--------------------------------+\n");

		printf("\n ������ �������� ���-�� ��� (y/n)? ");
		answ = getchar();
		getchar();
	}

	fclose(file);

	return SUCCESS;
}*/
