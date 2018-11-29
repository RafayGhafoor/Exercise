#include "stdafx.h"
#include <iostream>

using namespace std;

int* resize(int *ptr, int &size) {
	size += 10;
	int *ptr1 = new int[size];
	for (int i=0; i<size; i++)
		ptr1[i] = *(ptr + i);
	return ptr1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter a size: ";
	int size; cin >> size;
	int *ptr = new int[size];
	cout << "Please enter elements: ";
	int temp;
	for (int i = 0;; i++) {
		cin >> temp;
		if (temp == -99) {
			ptr[i] = -99;
			break;
			}
		if (i > size)
			ptr = resize(ptr, size);
		ptr[i] = temp;	
	}
	
	for (int i=0; i<size && ptr[i] != -99; i++)
		cout << ptr[i] << endl;

	system("pause");
	return 0;
}
