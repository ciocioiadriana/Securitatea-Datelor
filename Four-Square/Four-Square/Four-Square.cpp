// Four-Square.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<bits.h>
#include<string>

using namespace std;

 int main() {
	string inText = "abcdefghijklmnopqrstuvwxyz0123456789", keyOne, keyTwo, plainText, cipherText;
	int keyOneLength, keyTwoLength, inTextLength, k1l1 = 0, k1l2 = 0, k1len = 0, i1len = 0, k2l1 = 0, k2l2 = 0, k2len = 0, i2len = 0, q1l1 = 0, q1l2 = 0, q3l1 = 0, q3l2 = 0, q1len = 0, q3len = 0;
	char currentChar;

	//creating 4 quadrant arrays
	char quadOne[6][6];
	char quadTwo[6][6];
	char quadThree[6][6];
	char quadFour[6][6];

	//initializing array values
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			quadOne[i][j] = '0';
			quadTwo[i][j] = '0';
			quadThree[i][j] = '0';
			quadFour[i][j] = '0';
		}
	}

	//get Keys
	cout<<"Enter the encryption key one: ";
	cout << "\nEnter the encryption key two: ";

	keyOneLength = keyOne.length();
	keyTwoLength = keyTwo.length();
	inTextLength = inText.length();

	//assign key one to quad four array												//quad four
	while (k1l1 < 6 && k1len < keyOneLength) {
		k1l2 = 0;
		while (k1l2 < 6 && k1len < keyOneLength) {

			currentChar = keyOne[k1len];
			int flag = 0;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (quadFour[i][j] == currentChar) {
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				quadFour[k1l1][k1l2] = currentChar;
				k1l2++;
			}
			k1len++;
		}
		k1l1++;

	}

	--k1l1;

	//assign remaining values to quad four array
	while (k1l1 < 6 && i1len < inTextLength) {

		while (k1l2 < 6 && i1len < inTextLength) {

			currentChar = inText[i1len];
			int flag = 0;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (quadFour[i][j] == currentChar) {
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				quadFour[k1l1][k1l2] = currentChar;
				k1l2++;
			}
			i1len++;
		}
		k1l1++;
		k1l2 = 0;
	}


	//assign key two to quad two array												//quad two
	while (k2l1 < 6 && k2len < keyTwoLength) {
		k2l2 = 0;
		while (k2l2 < 6 && k2len < keyTwoLength) {

			currentChar = keyTwo[k2len];
			int flag = 0;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (quadTwo[i][j] == currentChar) {
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				quadTwo[k2l1][k2l2] = currentChar;
				k2l2++;
			}
			k2len++;
		}
		k2l1++;

	}

	--k2l1;

	//assign remaining values to quad two array
	while (k2l1 < 6 && i2len < inTextLength) {

		while (k2l2 < 6 && i2len < inTextLength) {

			currentChar = inText[i2len];
			int flag = 0;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (quadTwo[i][j] == currentChar) {
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				quadTwo[k2l1][k2l2] = currentChar;
				k2l2++;
			}
			i2len++;
		}
		k2l1++;
		k2l2 = 0;
	}

	//assign quad one array															//quad one
	while (q1l1 < 6 && q1len < inTextLength) {
		q1l2 = 0;
		while (q1l2 < 6 && q1len < inTextLength) {

			currentChar = inText[q1len];
			int flag = 0;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (quadOne[i][j] == currentChar) {
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				quadOne[q1l1][q1l2] = currentChar;
				q1l2++;
			}
			q1len++;
		}
		q1l1++;

	}

	//assign quad three array														//quad three
	while (q3l1 < 6 && q3len < inTextLength) {
		q3l2 = 0;
		while (q3l2 < 6 && q3len < inTextLength) {

			currentChar = inText[q3len];
			int flag = 0;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (quadThree[i][j] == currentChar) {
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				quadThree[q3l1][q3l2] = currentChar;
				q3l2++;
			}
			q3len++;
		}
		q3l1++;

	}

	string choice;
	cout<<"Enter 'e' for Encryption and 'd' for Decryption: "<<endl;
	

	if (choice=="e") {

		//get plain text
		int txtLength;
		cout<<"\n\nEnter the plain text: ";
		txtLength = plainText.length();

		//encryption
		int q4r = 0, q4c = 0, q2r = 0, q2c = 0, counter = 0;

		cout<<"\nEncrypted text: ";
		while (counter < txtLength) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {

					if (quadFour[i][j] == plainText[counter])
					{
						q4r = i;
						q4c = j;
					}

					if (counter + 1 < txtLength) {

						if (quadTwo[i][j] == plainText[counter + 1]) {
							q2r = i;
							q2c = j;
						}

					}

				}
			}

			cout<<quadThree[q2r][q4c];
			cout<<quadOne[q4r][q2c];

			counter += 2;

		}
	}
	else if (choice=="d") {

		//get cipher text
		int txtLen;
		cout<<"\n\nEnter the cipher text: ";
		txtLen = cipherText.length();

		//decryption
		int q3r = 0, q3c = 0, q1r = 0, q1c = 0, count = 0;

		cout<<"\nDecrypted text: ";
		while (count < txtLen) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {

					if (quadThree[i][j] == cipherText[count]) {
						q3r = i;
						q3c = j;
					}

					if (count + 1 < txtLen) {

						if (quadOne[i][j] == cipherText[count + 1]) {
							q1r = i;
							q1c = j;
						}

					}

				}
			}

			cout<<quadFour[q1r][q3c];
			cout<<quadTwo[q3r][q1c];

			count += 2;

		}

	}

}