#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() { 
	srand(time(0));
	int num = rand() % 20;
	
	while (1) {
		int input; cout << "Enter a number greater than or equal to 0 and less than 20: "; cin >> input;
		
		if (num == input) 
		{ 
			cout << "You guessed the correct number !!!\n\n"; 
			break; 
		}

		else if (input > num) cout << "Your guess is higher than the number.\nGuess again!\n\n";
			
		else if (input < num) cout << "Your guess is lower than the number.\nGuess again!\n\n";

	}
	system("pause");
}
