// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{

	char mat[8][9] = {"encedeox",
				"encdeefg",
				"abcdeefg",
				"abcdeefg",
				"aboxenge",
				"abcdefge",
				"abcdefeg",
				"abcdeeox"};

	char str[] = "oxen";
	int len = strlen(str);

	bool flag, stop = false;
	int count = 0;

	for (int i = 0; i < 8 && !stop; i++)
		for (int j = 0; j < 8 && !stop; j++)
			if (str[0] == mat[i][j]) {
				flag = true;
				for (int k = 0; k < len && flag; k++) {
					if (str[k] != mat[i][j])
						flag = false;
					else {
						j++;
						if (j > 7) {
							j = 0;
							if (i == 7) { i = 0; stop = true; } else i++;
						}
					}
				}
				if (flag)
					count++;
				else {
					j--;
					if (j < 0) {
						j = 7;
						if (i == 0)
							i = 7;
						else
							i++;
					}
				}
			}


	cout << "Number of times it appears: " << count;

	cout << endl;

	system("pause");

    return 0;
}