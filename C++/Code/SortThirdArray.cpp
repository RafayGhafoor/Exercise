#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void populate_array(int arr[], int &len, ifstream &file) {
  int temp;

  for (int i = 0; i < len && !file.eof(); i++) {
    file >> temp;
    arr[i] = temp;
  }
}

int findMin(int arr[], int size, int index) {
  int minIndex = index;
  for (int j = index; j < size; j++) {
    if (arr[j] < arr[minIndex]) {
      minIndex = j;
    }
  }
  return minIndex;
}

void sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    swap(arr[i], arr[findMin(arr, size, i)]);
  }
}

int main() {

  ifstream myfile("file.txt");
  int len, len1, *arr, *arr1;

  if (myfile.is_open()) {

    myfile >> len;
    arr = new int[len];
    populate_array(arr, len, myfile);

    myfile >> len1;
    arr1 = new int[len1];
    populate_array(arr1, len1, myfile);
    sort(arr, len);
    sort(arr1, len1);
  }
  int sorted_arr[len + len1] = {0};
  int *minarr, *maxarr;
  // Arrays that contain maximum element by magnitude
  if (arr[len - 1] < arr1[len1 - 1]) {
    minarr = arr;
    maxarr = arr1;
  } else {
    minarr = arr1;
    swap(len1, len);
    maxarr = arr;
  }

  int index = 0, length = 0, y = 0;

  for (; index < len; length++) {
    if (minarr[index] < maxarr[y]) {
      sorted_arr[length] = minarr[index];
      index++;
    } else {
      sorted_arr[length] = maxarr[y];
      y++;
    }
  }

  for (int j = index; y < len1; j++, y++)
    sorted_arr[j] = maxarr[y];

  int check;
  for (int i = 0; i < len + len1; i++) {
    if (sorted_arr[i] == check)
      continue; // Duplicates Check
    cout << sorted_arr[i] << endl;
    check = sorted_arr[i];
  }

  myfile.close();
}
