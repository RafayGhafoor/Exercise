#include <iostream>

using namespace std;

int main() {
  int myArray[6] = {1, 4, 5, 6, 12, 25};
  int check = 7, secondIndex = 0, maxIndex = 0;

  for (int i = 0; i < 6; i++)
    if (myArray[maxIndex] < myArray[i] && myArray[i] < check) {
      maxIndex = i;
    }

  for (int i = maxIndex - 1; i >= 0; i--) {
    if (myArray[i] + myArray[maxIndex] <= check) {
      secondIndex = i;
    }
  }

  cout << myArray[maxIndex] << " | " << myArray[secondIndex] << endl;
}
