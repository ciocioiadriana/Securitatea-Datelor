// FrecventaLitera.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int alpha[26] = { 0 };

int main(void)
{
	string text;

	cout << "Introduceti textul:" << endl;
	getline(cin, text);

	for (int i = 0; i < text.length(); i++)
	{
		int a = text[i];

		if (a >= 'A' && a <= 'Z')
		{
			alpha[a - 'A']++;
		}
		else if (a >= 'a' && a <= 'z')
		{
			alpha[a - 'a']++;
		}
	}

	cout << "Frecventa:" << endl;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i])
		{
			cout << right << char('a' + i) << setw(2) << right << alpha[i] << endl;
		}
	}
	return 0;
}
