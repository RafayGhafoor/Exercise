#include <iostream>

using namespace std;

int main() {
	int input;
	cout << "Please enter a number: "; cin >> input;
	while (input >= 10){
		cout << input % 10;
		input /= 10;
		if (input < 10) cout << input;
}
}
