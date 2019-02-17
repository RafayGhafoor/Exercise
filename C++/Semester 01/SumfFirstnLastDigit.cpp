#include <iostream>
#include <cmath>
#include <string>

using namespace std;
// Sum the first and last digit of a number.

int main() {
	int input; cout << "Please enter a number: "; cin >> input;	
	int first_number = (input / pow(10, to_string(input).length()-1));
	cout << first_number + input%10;	

}
