#include <iostream>

using namespace std;

int main() {
  int array[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  //   1 2 3  1 4 7
  //   4 5 6  2 5 8
  //   7 8 9  3 6 9
  int count = 0;
  for (int i = 1, x = 0; i < 3; i++, x++) {
    swap(array[i][x], array[x][i]);
  }
  //   00 01 02
  //   10 11 12
  //   20 21 22
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      cout << array[i][j] << " ";
    cout << endl;
  }
}