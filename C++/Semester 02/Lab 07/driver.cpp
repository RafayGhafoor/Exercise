#include "header.h"
#include <iostream>

using namespace std;

int main()
{
  BinaryNum b1;
  BinaryNum b2("101");   // noOfBits = 3
  cout << "b1 = " << b1; // Prints nothing
  BinaryNum b3("1001");
  cout << "b2 = " << b2;         // Prints 101
  cout << "b3 = " << b3 << endl; // Prints 1001

  b1 = b2 + b3;

  cout << "b1 = " << b1 << endl; // Prints 1110
  cout << "b1[0] = " << b1[0] << endl;
  cout << "b1[3] = " << b1[3] << endl; // Prints 0 (3rd bit in b1)

  cout << b3++; // Prints 1010
  bool flag = false;
  if (b3 == b2)
    flag = true;

  cout << "is equal = " << flag << endl; // Prints 0
  cout << ++b3;                          // Prints 1011
  b1 = "111" + b2;
  cout << b2; // Prints 1110
  cin >> b2;  // Input 10
  cout << b1 - b2;
  cout << b1; // Prints 10011
}
