#include <iostream>
#include <string>
using namespace std;

int main() {

	bool is_birthday;
	string birthday;
	cout << "Is today your birthday?\nIf yes, enter 'y', otherwise 'n': ";
	cin >> birthday;

	if (birthday == "y")
		is_birthday = true;
	else if (birthday == "n")
		is_birthday = false;
	else
		cout << "\nYou've entered incorrect option";

	int speed; cout << "\nPlease enter your speed: "; cin >> speed;
	if (is_birthday) speed -= 5;

	if (speed <= 60)
		cout << 0;
	else if (speed > 61 && speed <= 80)	
		cout << 1;
	else if (speed >= 81)
		cout << 2;
	cout << "\n";
	system("pause");
}