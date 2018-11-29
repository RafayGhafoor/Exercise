#include "stdafx.h"
#include <iostream>

using namespace std;

int findMax(int arr[], int size, int maxValIndex) {
	
  int maxIndex = 0; 
  for (int j = 0; j < size; j++) {
	if (maxValIndex == 0)
		if (arr[j] > arr[maxIndex]) 
		  maxIndex = j;			
  }
	
  
  return maxIndex;

}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter a size: ";
	int size; cin >> size;
	int *ptr = new int[size];
	cout << "Please enter elements: ";
	for (int i=0; i < size; i++) {
		cin >> ptr[i];
	}
	
	int maxIndex = findMax(ptr, size, 0);
	int sMax = 0;
	for (int i=0; i < size; i++) {
		if (ptr[i] < ptr[maxIndex] && ptr[i] > ptr[sMax])
			sMax = i;
	}
	cout << "\nIndex: " << sMax << endl;
	cout << "Number: " << ptr[sMax] << endl;
	system("pause");
	return 0;
}