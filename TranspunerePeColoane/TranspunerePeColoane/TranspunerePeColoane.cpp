// TranspunerePeColoane.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char k[20] = { '\0' }, pt[30] = { '\0' }, key[30] = { '\0' }, mat[10][10] = { '\0' }, ct[30] = { '\0' };
	int i = 0, j = 0, no[10] = { 0 }, ctr, z, c = 0, a = 0;
	// clear();
	printf("Enter the plaintext:\n");
	gets_s(pt);
	printf("Enter the key:\n");
	gets_s(k);
	strcpy_s(key, k);
	strcat_s(k, pt);
	strcpy_s(pt, k);
	printf("Enter the ordering starting from 0 to the (keylength-1):\n");

	for (i = 0; i < strlen(key); i++)
	{

		scanf_s("%d", &no[i]);
	}
	j = 0;
	ctr = j;
	printf("The matrix is:\n");
	for (i = 0; i < strlen(pt); i++)
	{
		for (j = j; ctr < strlen(key); j++)
		{
			if (pt[j] != '\0')
			{
				mat[i][ctr] = pt[j];
				printf("%c", mat[i][ctr]);
				ctr++;
			}
			else
			{
				goto out;
			}
		}
		ctr = 0;
		if (i == 0) printf("\n");
		printf("\n");
	}
out:
	printf("\n\nThe Encrypted  text is:\n");
	for (i = 0; i < strlen(key); i++)
	{
		for (j = 0; j < strlen(key); j++)
		{
			if (no[i] == j)
			{
				for (z = 1; z < 10; z++)
				{
					if (isalpha(mat[z][j]))
					{
						printf("%c", mat[z][j]);
						ct[a] = mat[z][j];
						a++;
					}

				}
			}
		}
	}
	printf("\n\nDecrypted Ciphertext is:\n");

	for (a = 0; a < 30; a++)
	{
		if (isalpha(ct[a]) || isspace(ct[a]))
			c++;
	}

	for (i = 1; i < c; i++)
	{
		for (j = 0; j < strlen(key); j++)
		{
			if (isalpha(mat[i][j]))
				printf("%c", mat[i][j]);
			else
				goto ext;
		}
	}
ext:

	_getch();
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
