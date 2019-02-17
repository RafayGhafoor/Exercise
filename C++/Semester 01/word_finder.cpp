#include <cstring>
#include <iostream>

using namespace std;

bool findWord(char array[][200], char word[], int &foundIndex) {
  bool flag = false;
  for (int i = 0; i < 10 && !flag; i++) {
    if (!strcmp(word, array[i])) {
      flag = true;
      foundIndex = i - 1;
    }
  }

  return flag;
}

int main() {
  int index = -1;
  char wordsLst[20][200];
  int inputSize = 0;
  cout << "Enter Number of Array Members to be entered: ";
  while (1) {
    cin >> inputSize;
    if (inputSize < 20)
      break;
    cout << "Invalid size specified";
  }

  for (int i = 0; i <= inputSize; i++)
    cin.getline(wordsLst[i], 200);

  char word[20];

  cout << "Enter the word to be searched in array: ";
  cin.getline(word, 20);

  if (findWord(wordsLst, word, index))
    cout << "Word found [" << word << "] "
         << "at index: " << index << endl;
}