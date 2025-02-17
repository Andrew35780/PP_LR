#include "Task.h"

//int select_game_by_year(const char* orig_file_name, const char* new_file_name);
void write_data_to_file_simple();
int select_game_by_year_simple(const char* orig_file_name, const char* new_file_name);

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
	//game_t game3; //game_temp for writing in cycle
	//fill_game_data(&game3);

	while (1) {
		system("cls");

		printf("\n 1: ������ ������\n");
		printf(" 2: ���������� ������\n");
		printf(" 3: ������ ������\n");
		printf(" 4: ����� �� ����\n");
		//printf(" 5: ����� �� ��������� ����� �� ��������\n");
		printf(" 5: ��������� ������\n");
		printf("\n �������� ��������: ");

		int choise;
		scanf_s("%d", &choise);
		getchar(); // ����������� �� ����������� /n

		switch ((operation)choise)
		{
		case WriteData:
			//write_data_to_file("file.txt", "w");
			write_data_to_file_simple();
			break;
		case AddData:
			write_data_to_file("file.txt", "a");
			break;
		case ReadData:
			system("cls");
			print_data_from_file("file.txt");
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
			printf("\n �� ����� �������������� ��������!\n");
		}
	}

	//write_data_to_file("file.txt", game1, "w");
	//write_data_to_file("file.txt", game2, "a");
	//print_data_from_file("file.txt");

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

	game_t game;
	int game_found = 0;

	// ������ ���� �� ��������� �����
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

		printf("���-�� ���������...");
		// ���������, ���� ��� ������ ���� ������ ����������
		if (game.release_year > sort_year) {
			game_found = 1;

			// ���������� ��������������� ���� � ����� ����
			fprintf(newFile, "+----------------------+--------------------------------+\n");
			fprintf(newFile, "| %-20s | %-30s |\n", "��������", game.name);
			fprintf(newFile, "| %-20s | %-30s |\n", "���������", game.platform);
			fprintf(newFile, "| %-20s | %-30hu |\n", "��� �������", game.release_year);
			fprintf(newFile, "| %-20s | %-30.2f ���. |\n", "����", game.price);
			fprintf(newFile, "| %-20s | %-30s |\n", "���������", game.is_used ? "�/�" : "�����");
			fprintf(newFile, "| %-20s | %-30u |\n", "����������", game.count);
			fprintf(newFile, "| %-20s | %-30s |\n", "����", game.genre);
			fprintf(newFile, "| %-20s | %-30s |\n", "���������� �������", game.age_rating);
			fprintf(newFile, "| %-20s | %-30.1f%% |\n", "������", game.discount);
			fprintf(newFile, "| %-20s | %-30s |\n", "�������", game.article);
			fprintf(newFile, "+----------------------+--------------------------------+\n");

			// ����� ������� �� �����
			printf("+----------------------+--------------------------------+\n");
			printf("| %-20s | %-30s |\n", "��������", game.name);
			printf("| %-20s | %-30s |\n", "���������", game.platform);
			printf("| %-20s | %-30hu |\n", "��� �������", game.release_year);
			printf("| %-20s | %-30.2f ���. |\n", "����", game.price);
			printf("| %-20s | %-30s |\n", "���������", game.is_used ? "�/�" : "�����");
			printf("| %-20s | %-30u |\n", "����������", game.count);
			printf("| %-20s | %-30s |\n", "����", game.genre);
			printf("| %-20s | %-30s |\n", "���������� �������", game.age_rating);
			printf("| %-20s | %-30.1f%% |\n", "������", game.discount);
			printf("| %-20s | %-30s |\n", "�������", game.article);
			printf("+----------------------+--------------------------------+\n");
		}
	}

	fclose(origFile);
	fclose(newFile);

	// ���� ���� �������� ����
	return game_found;
}

int select_game_by_year_simple(const char* orig_file_name, const char* new_file_name) {
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
	int game_found = 0;

	// ������ ���� �� ��������� �����
	while (fscanf_s(origFile,
		"%30s\n"
		"%50s\n"
		"%50s\n"
		"%10s\n"
		"%hu\n"
		"%30s\n"
		"%f\n"
		"%f\n"
		"%u\n",
		game.name, game.platform, game.genre, game.age_rating,
		&game.release_year, game.article, &game.price, &game.discount,
		&game.count) == 9) {

		printf("���-�� ���������...");
		// ���������, ���� ��� ������ ���� ������ ����������
		if (game.release_year > sort_year) {
			game_found = 1;

			// ���������� ��������������� ���� � ����� ����
			fprintf(newFile, "+----------------------+--------------------------------+\n");
			fprintf(newFile, "| %-20s | %-30s |\n", "��������", game.name);
			fprintf(newFile, "| %-20s | %-30s |\n", "���������", game.platform);
			fprintf(newFile, "| %-20s | %-30hu |\n", "��� �������", game.release_year);
			fprintf(newFile, "| %-20s | %-30.2f ���. |\n", "����", game.price);
			fprintf(newFile, "| %-20s | %-30s |\n", "���������", game.is_used ? "�/�" : "�����");
			fprintf(newFile, "| %-20s | %-30u |\n", "����������", game.count);
			fprintf(newFile, "| %-20s | %-30s |\n", "����", game.genre);
			fprintf(newFile, "| %-20s | %-30s |\n", "���������� �������", game.age_rating);
			fprintf(newFile, "| %-20s | %-30.1f%% |\n", "������", game.discount);
			fprintf(newFile, "| %-20s | %-30s |\n", "�������", game.article);
			fprintf(newFile, "+----------------------+--------------------------------+\n");

			// ����� ������� �� �����
			printf("+----------------------+--------------------------------+\n");
			printf("| %-20s | %-30s |\n", "��������", game.name);
			printf("| %-20s | %-30s |\n", "���������", game.platform);
			printf("| %-20s | %-30hu |\n", "��� �������", game.release_year);
			printf("| %-20s | %-30.2f ���. |\n", "����", game.price);
			printf("| %-20s | %-30s |\n", "���������", game.is_used ? "�/�" : "�����");
			printf("| %-20s | %-30u |\n", "����������", game.count);
			printf("| %-20s | %-30s |\n", "����", game.genre);
			printf("| %-20s | %-30s |\n", "���������� �������", game.age_rating);
			printf("| %-20s | %-30.1f%% |\n", "������", game.discount);
			printf("| %-20s | %-30s |\n", "�������", game.article);
			printf("+----------------------+--------------------------------+\n");
		}
	}

	fclose(origFile);
	fclose(newFile);

	// ���� ���� �������� ����
	return game_found;
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
	getchar();

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
}

void write_data_to_file_simple() {
	FILE* file;

	fopen_s(&file, "simple_file.txt", "w");

	char answ = 'y';
	while (answ != 'n') {
		system("cls");

		game_t game;
		fill_game_data(&game);

		char price_str[50], discount_str[50];

		// ��������� ������ ��� ���� � ������ � ��������� ���������
		float final_price = game.discount == 0 ? game.price :
			game.price * (1 - (game.discount / 100));
		sprintf_s(price_str, "%.2f ���.", final_price);
		sprintf_s(discount_str, "%.1f%%", game.discount);

		fprintf_s(file, "\n");
		fprintf_s(file, "%-30s\n", game.name);
		fprintf_s(file, "%-30s\n", game.platform);
		fprintf_s(file, "%-30hu\n", game.release_year);
		fprintf_s(file, "%-30s\n", price_str);
		fprintf_s(file, "%-30s\n", game.is_used ? "�/�" : "�����");
		fprintf_s(file, "%-30u\n", game.count);
		fprintf_s(file, "%-30s\n", game.genre);
		fprintf_s(file, "%-30s\n", game.age_rating);
		fprintf_s(file, "%-30s\n", discount_str);
		fprintf_s(file, "%-30s\n", game.format);
		fprintf_s(file, "%-30s\n", game.article);

		printf("\n ������ �������� ���-�� ��� (y/n)? ");
		answ = getchar();
		getchar();
	}
	
}

//TODO: �������� ������� ���������� ����� ���������
// �������� ��������� �� ������ �������� ����� � ��������!
// ��������, ��� ������ ������ �� ����� �: ������������ ��������������, ������������ �������� ��� �� �������, ���������� ������ �� ������ �������, ������������ ���������� ��������� ����� � ���������� ��� ������, ������� ������ ����� � �������� ����
// ������ �����, ������� ���������� � ���� ������ � "�����" ����, � ����� ��������� �� � ������� �� ������!
