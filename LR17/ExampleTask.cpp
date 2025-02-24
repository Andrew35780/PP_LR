#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <iostream>

using namespace std;

int add();
int wr();
int rd();
char funst();
int obryo();
void obrn();

typedef struct {
	char name[20];
	char author[20];
	int year;
} book;
/*
int main()
{
	setlocale(LC_CTYPE, "");

	while (1)
	{
		system("cls");

		cout << "\n 1: Запись данных\n";
		cout << " 2: Дополнение данных\n";
		cout << " 3: Чтение данных\n";
		cout << " 4: Отбор по году\n";
		cout << " 5: Отбор по введённому слову из названия\n";
		cout << " 6: Закончить работу\n";
		cout << "\n Выберите операцию: ";

		int n;
		cin >> n;

		switch (n)
		{
		case 1:
			wr(); 
			break;
		case 2:
			add(); 
			break;
		case 3:
			rd(); 
			break;
		case 4:
			obryo();
			break;
		case 5:
			obrn(); 
			break;
		case 6:
			return(0);
		default:
			cout << "\n У нас нет таких операций";
		}
	}
}*/

char funst()
{
	int i;

	for (i = 0; i < 49; i++)
		printf("*");
	return 0;
}

int wr()
{
	system("cls");

	book b; 
	char a = 'y';
	FILE* tf1;

	tf1 = fopen("fileb.doc", "wb");

	while (a != 'n')
	{
		system("cls");

		printf("\n Название = "); 
		scanf("%s", &b.name);

		printf("\n Автор = "); 
		scanf("%s", &b.author);

		printf("\n Год создания = "); 
		scanf("%d", &b.year);

		//printf ( "\n%15s %15s %4d",  b.name, b.author,  b.year);
		fprintf(tf1, "\n%15s %15s %4d", b.name, b.author, b.year);

		cout << "\n Хотите ввести больше данных? (y/n):";
		cin >> a;
	}

	fclose(tf1); 

	cout << endl;

	return 0;
}

int add()
{
	system("cls");

	book b; 
	char a = 'y';
	FILE* tf1;

	tf1 = fopen("fileb.doc", "ab");

	while (a != 'n')
	{
		system("cls");

		printf("\n Название = "); 
		scanf("%s", &b.name);

		printf("\n Автор = "); 
		scanf("%s", &b.author);

		printf("\n Год создания = "); 
		scanf("%d", &b.year);

		fprintf(tf1, "\n %15s %15s %4d", b.name, b.author, b.year);

		cout << "\n Хотите ввести больше данных? (y/n):";
		cin >> a;
	}

	fclose(tf1);

	cout << endl;

	return 0;
}

int rd()
{
	system("cls");

	book b; 
	FILE* tf1;

	tf1 = fopen("fileb.doc", "rb");

	if (tf1 == NULL)
	{
		printf(" \n Ошибка открытия файла");
		return 1;
	}

	funst();
	printf("\n| название книги  |   автор книги   |год выпуска| \n");
	funst();

	while (!feof(tf1))
	{
		fscanf(tf1, " %s  %s %d ", &b.name, &b.author, &b.year);
		printf("\n| % 15s | % 15s | % 9d | ", b.name, b.author, b.year);
	}

	cout << endl;

	system("pause");
	fclose(tf1);

	cout << endl;

	return 0;
}


int obryo()
{
	int yo; 
	char word[20];

	system("cls");

	book b; 
	FILE* tf1;  
	FILE* tf2;

	tf1 = fopen("fileb.doc", "rb");
	tf2 = fopen("fileobryo.doc", "wb");

	if (tf1 == NULL)
	{
		printf(" \n Ошибка открытия файла"); 
		return 1;
	}

	funst();
	printf("\n книга должна быть старше скольки лет? \n");
	scanf("%d", &yo);

	funst();
	printf("\n| название книги  |   автор книги   |год выпуска| \n");
	funst();

	while (!feof(tf1))
	{
		fscanf(tf1, "%s %s %d ", &b.name, &b.author, &b.year);

		if ((2025 - b.year) >= yo)
		{
			fprintf(tf2, " \n  %15s %15s %4d", b.name, b.author, b.year);
			printf("\n| % 15s | % 15s | % 9d | ", b.name, b.author, b.year);
		}
	}

	cout << endl; 

	system("pause");
	fclose(tf1);
	fclose(tf2);

	return 0;
}

void obrn() {

}
