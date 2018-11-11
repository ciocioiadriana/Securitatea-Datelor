// cezar_tema.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

int key;
void alfabet_initial()
{
	for (char i = 65; i <= 122; i++)
	{
		if (i != 91 && i != 92 && i != 93 && i != 94 && i != 95 && i != 96)
		{
			std::cout << i << ' ';
		}
	}
}
void alfabet_defazat()
{

	std::cout << std::endl;
	std::cout << "defazajul alfabetului " << std::endl;
	std::cout << "key="; std::cin >> key;
	for (char j = 65; j <= 122; j++)
	{
		if (j + key > 122)
			if (char(j + key) == ' ') std::cout << ' ';
			else
				std::cout << char(j - 58 + key) << ' ';
		else
			if (j + key != 91 && j + key != 92 && j + key != 93 && j + key != 94 && j + key != 95 && j + key != 96)
				std::cout << char(j + key) << ' ';
	}
}

void afisare1(char sir_dat[])
{
	std::cout << "sir_criptat=";

	for (char j = 0; j < strlen(sir_dat); j++)
	{
		if ((sir_dat[j] + key > 122) && ('#' == 32))
			std::cout << char(sir_dat[j] - 58 + key) << ' ';
		else
			std::cout << char(sir_dat[j] + key);
	}
}

int main()
{
	char key;
	char i;
	char sir_dat[50] = "Ana are mere";
	alfabet_initial();
	alfabet_defazat();
	std::cout << std::endl << std::endl;
	afisare1(sir_dat);
	std::cout << std::endl;
}
