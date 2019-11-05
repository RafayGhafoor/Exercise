#include <iostream>

using namespace std;

void splitCurrency(int amount) {
  int hundreds = amount / 100;
  amount -= (hundreds * 100);
  int fifties = amount / 50;
  amount -= (fifties * 50);
  int twenties = amount / 20;
  amount -= (twenties * 20);
  int tens = (amount / 10);
  if (hundreds)
    cout << "\nDenomination for 100s - " << hundreds << endl;
  if (fifties)
    cout << "\nDenomination for 50s - " << fifties << endl;
  if (twenties)
    cout << "\nDenomination for 20s - " << twenties << endl;
  if (tens)
    cout << "\nDenomination for 10s - " << tens << endl << endl;
}

int main() { 
	int amount; cout << "Please enter amount: "; cin >> amount;
	
	splitCurrency(amount);

	
}
