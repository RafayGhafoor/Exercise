#include <iostream>

using namespace std;

void swap(int& num1, int& num2);

int main () {
    int a, b;  
    cout << "Input 1st Number: "; cin >> a;  
    cout << "Input 2nd Number: "; cin >> b;  
    swap(a, b);
    cout << "After swapping the 1st number is: " << a << endl;
    cout << "After swapping the 2nd number is: " << b << endl;
}

void swap(int& num1, int& num2) {
    int temp;
    temp = num1; num1 = num2; num2 = temp; 
}