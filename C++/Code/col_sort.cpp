#include <iostream>

using namespace std;

int findMin(int arr[][3], int column, int &index) {
  int min = arr[0][column];
  for (int i = column; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (min > arr[j][i]) {
        min = arr[j][i];
        index = j;
      }
    }
  return min;
}

int main() {
  int arr[3][3];
  // Adding Elements in Array
  cout << "Enter Numbers (Entered Column Wise):\n\n";
  for (int i = 0; i < 3; i++) {
    cout << "[Input for Column " << i << "]\n";
    for (int j = 0; j < 3; j++) {
      cout << ">>> ";
      cin >> arr[j][i];
    }
  }

  // Sorting of Columns
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++)
      if (arr[j][i] < arr[j + 1][i])
        swap(arr[j][i], arr[j + 1][i]);

    if (arr[2][i] < arr[0][i])
      swap(arr[2][i], arr[0][i]);
  }
  // Output Display
  for (int i = 0; i < 3; i++) {
    cout << "[Output for Column " << i << "]\n";
    for (int j = 0; j < 3; j++)
      cout << arr[j][i] << endl;
  }
}