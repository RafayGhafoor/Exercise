#include <iostream>

using namespace std;

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
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (j < 2 && arr[j][i] > arr[j + 1][i])
        swap(arr[j][i], arr[j + 1][i]);
      if (j > 1 && arr[j - 1][i] > arr[j][i])
        swap(arr[j - 1][i], arr[j][i]);
    }

  // Output Display
  for (int i = 0; i < 3; i++) {
    cout << "[Output for Column " << i << "]\n";
    for (int j = 0; j < 3; j++)
      cout << arr[j][i] << endl;
  }
}