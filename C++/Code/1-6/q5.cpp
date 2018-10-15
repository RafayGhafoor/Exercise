#include <iostream>

using namespace std;

void calc_factorial(int num1, int &fact);

int main() {
    int factorial = 1;
    calc_factorial(6, factorial);
    cout << factorial;
}

void calc_factorial(int num1, int &fact){
    for (int i=1; i<=num1; i++)    
        fact *= i;
}