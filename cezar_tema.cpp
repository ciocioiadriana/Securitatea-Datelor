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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
