#include <iostream>

using namespace std;

int findMin(int arr[][3], int column, int element) {
  int index = 0;
  int min = arr[0][column];
  
  for (int j = element; j < 3; j++) {
      if (min >= arr[j][column]) {
          cout << arr[j][column];
        min = arr[j][column];
        index = j;
      }
    }
  return index;
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

//   Sorting of Columns
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++)
        if (findMin(arr, i, j) != 0)
          swap(arr[j][i], arr[findMin(arr, i, j)][i]);
  }

  // Output Display
  for (int i = 0; i < 3; i++) {
    cout << "[Output for Column " << i << "]\n";
    for (int j = 0; j < 3; j++)
      cout << arr[j][i] << endl;
  }
}
