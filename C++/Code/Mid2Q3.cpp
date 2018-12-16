#include <iostream>
using namespace std;

int main() {
  int arr[10] = {77, 88, 11, 3, 1, 5, 6, 30, 23, 0};
  int maxDiff = -10000;
  int k = 2;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
      if (j - i <= k && arr[j] - arr[i] > maxDiff) {
        maxDiff = arr[j] - arr[i];
      }
    }
  cout << maxDiff << endl;
}
