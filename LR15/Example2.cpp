#include <stdio.h>
#include <string.h>
#include <windows.h>
/*
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");

	char gwords[10][40], temp[40];
	int i = 0;

	printf(" Введите 10 слов, начинающихся с 'd': \n");
	
	while (i < 10)
	{
		gets_s(temp, 40);

		if (temp[0] != 'd') // проверка первого символа
			printf(" %s не начинается с 'd'!\n", temp);
		else {
			strcpy_s(gwords[i], temp); 
			i++; 
		}
	}

	puts("\n Следующие слова соответствуют условию: ");
	for (i = 0; i < 10; i++) 
		puts(gwords[i]);

	return 0;
}
*/