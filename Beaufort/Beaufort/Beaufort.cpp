// Beaufort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int encrypt(string Text, string mText, string key) {
	int k = 0;
	string computerPrank;
	getline(cin, computerPrank);
	cout << "Enter text: ";
	getline(cin, Text);
	cout << "Enter key: ";
	cin >> key;
	for (int i = 0; i < key.length(); i++) {
		if (key[i] == 32) {
			mText[i] = '\x84';
		}
		else {
			mText[i] = (((key[i] - 97) + (Text[k] - 97)) % 26) + 97;
			k++;
			if (k == Text.length()) {
				k = 0;
			}
		}
	}
	cout << endl << "ciphertext: ";
	for (int i = 0; i < key.length(); i++) {
		cout << mText[i];
	}
	cout << endl << endl;
	return 0;
}

int decrypt(string Text, string mText, string key) {

	// the sneakyText and plainText in this function have swapped placed since i initialized sneakyText to wwwwwwwww to make the program work but other than that the both variables are exactly the same.

	int k = 0;
	string computerPrank;
	getline(cin, computerPrank);
	cout << "Enter ciphertext: ";
	getline(cin, Text);
	cout << "Enter key: ";
	cin >> key;
	for (int i = 0; i < key.length(); i++) {
		if (key[i] == '\x84') {
			mText[i] = 32;
		}
		else {
			mText[i] = (((key[i] - 122) - (Text[k] - 97)) % 26) + 122;
			k++;
			if (k == key.length()) {
				k = 0;
			}
		}
	}
	cout << endl << "Text: ";
	for (int i = 0; i < key.length(); i++) {
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
