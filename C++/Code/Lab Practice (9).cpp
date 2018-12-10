#include <fstream>
#include <iostream>

using namespace std;
// The file named fact_data.txt contains integers in each line. Write a program
// that reads each integer and then finds and displays the factorial of that
// integer as well as write it in a file named fact_out.txt in a new line.
// Factorial should be found using a function named factorial.

int calc_Factorial(int num) {
  int total = 1;
  for (int i = 2; i <= num; i++)
    total = total * i;
  return total;
}

int main() {
  // Write Integers to file
  ofstream file("fact_data.txt");

  // Add integers from 2 to 20 in the file
  for (int i = 2; i <= 10; i++)
    file << i << endl;

  file.close();

  //   Read Integers from file
  ifstream afile("fact_data.txt");

  int num;
  afile >> num;
  while (!afile.eof()) {
    cout << "Factorial of " << num << " is " << calc_Factorial(num) << endl;
    afile >> num;
  }
}
