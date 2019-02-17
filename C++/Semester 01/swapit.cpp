#include <iostream>
#include <string>

using namespace std;

int main() {
    string input; cout << "Please enter a number: "; cin >> input;
    string new_input = "";
    new_input += input[input.length() - 1];

    for (int i=1; i<input.length()-1; i++) 
        new_input += input[i];  

    new_input += input[0];
    cout << new_input;
}