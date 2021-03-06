// AutoKey.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <string.h>

using namespace std;

int encrypt(string Text, string mText, string key) {
	int k = 0, j=0, plen, klen;
	string computerPrank;
	getline(cin, computerPrank);
	cout << "Enter text: ";
	getline(cin, Text);
	cout << "Enter key: ";
	cin >> key;

	plen = Text.length();
	klen = key.length();

	if (klen < plen)
	{
		for (int i = klen; i < plen; i++)
		{
			key[i] = Text[j];
			j++;
		}
	}
	cout << "\nNoua Cheie va fi:";
	for (int i = 0; i < plen; i++)
	{
		cout << key[i];
	}

	for (int i = 0; i < plen; i++) {
		if (Text[i] == 32) {
			mText[i] = '\x84';
		}
		else {
			mText[i] = (((Text[i] - 97) + (key[k] - 97)) % 26) + 97;
			k++;
			/*if (k == klen) {
				k = 0;
			}*/
		}
	}
	cout << endl << "ciphertext: ";
	for (int i = 0; i < Text.length(); i++) {
		cout << mText[i];
	}
	cout << endl << endl;
	return 0;
}

int decrypt(string Text, string mText, string key) {

	// the sneakyText and plainText in this function have swapped placed since i initialized sneakyText to wwwwwwwww to make the program work but other than that the both variables are exactly the same.

	int k = 0, plen, klen, j=0;
	string computerPrank;
	getline(cin, computerPrank);
	cout << "Enter ciphertext: ";
	getline(cin, Text);
	cout << "Enter key: ";
	cin >> key;

	plen = Text.length();
	klen = key.length();

	for (int i = 0; i < plen; i++) {
		if (Text[i] == '\x84') {
			mText[i] = 32;
		}
		else {
			mText[i] = (((Text[i] - 122) - (key[k] - 97)) % 26) + 122;
			k++;
			if (k == klen || k > klen) {
				for (int i = klen; i < mText.length(); i++)
				{
					key[i] = mText[j];
					j++;
				}
			}
		}
	}
	cout << endl << "Text: ";
	for (int i = 0; i < Text.length(); i++) {
		cout << mText[i];
	}
	cout << endl << endl;
	return 0;
}

int main() {

	string Text;
	string mText = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
	string key;
	cout << "1 - encrypt text" << endl << "2 - decrypt text" << endl << endl;
	int input;
	cin >> input;
	switch (input) {
	case 1:
		encrypt(Text, mText, key);
		break;
	case 2:
		decrypt(Text, mText, key);
		break;
	default:
		cout << "invalid option" << endl << endl;
		break;
	}
	system("pause");
	return 0;
}