#include <iostream>
#include <math.h>

using namespace std;

// Design and write a C++ program that takes as input an integer larger than 1
// and calculates the sum of the squares from 1 to that integer. The output
// should be the value of the squares and the sum, properly labelled on the
// screen. For example, if the integer equals 4, your program would display “1 +
// 4 + 9 + 16 = 30”

int main()
{

    int num, sum = 0;
    cin >> num;
    if (num > 1)
    {
        for (int i = 1; i <= num; i++)
        {

            if (i == num)
                cout << pow(i, 2) << " = ";
            else
                cout << pow(i, 2) << " + ";

            sum = sum + pow(i, 2);
        }
        cout << sum;
    }

    else
        cout << "Invalid Input";
}
