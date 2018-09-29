#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() { 
	int amount; cout << "Please enter amount: "; cin >> amount;
	
	int hundreds = amount / 100;
	amount -= (hundreds * 100);
	int fifties = amount / 50;
	amount -= (fifties * 50);
	int tens = amount / 10;
	int ones = amount - (tens * 10);
	
	printf("\n100 * %d\n50 * %d\n10 * %d\n1 * %d\n\n", hundreds, fifties, tens, ones);

	system("pause");
}
