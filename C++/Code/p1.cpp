// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void get(char *arr, int size) {
	for(int i = 0; i < size; ++i)
		cin >> *(arr + i);
}


void print(char *arr, int size) {
	for(int i = 0; i < size; ++i)
		cout << *(arr + i);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int size; cin >> size;
	char *ptr = new char[size];
	get(ptr, size);
	print(ptr, size);
	system("pause");
	return 0;
}

