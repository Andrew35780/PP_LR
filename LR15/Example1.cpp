#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
/*
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");

	char c[20]; 
	int i = 0, p;

	printf("\n Введите строку\n");
	gets_s(c, 20); // для Visual Studio выше 12-й версии
	
	puts(c);

	printf("\n Цифры в прямом порядке : \n");
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9') 
			printf(" %2c", c[i]);
		i++;
	}

	printf("\n Буквы в обратном порядке\n");
	p = i--;
	do
	{
		if ((c[p] >= 'a' && c[p] <= 'z') || (c[p] >= 'а' && c[p] <= 'я'))
			printf(" %2c", c[p]); 
		p--;
	} while (p >= 0);

	return 0;
}
*/