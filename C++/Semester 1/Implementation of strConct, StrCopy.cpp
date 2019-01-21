#include <cstring>
#include <iostream>

using namespace std;

void strCont(char w1[], char w2[]) {
  for (int index = 0, i = strlen(w1); index < strlen(w2); i++, index++) {
    w1[i] = w2[index];
  }
}

void strCopy(char w1[], char w2[]) {
  int w2_len = strlen(w2);
  for (int i = 0; i < w2_len; i++) {
    w1[i] = w2[i];
  }

  w1[w2_len] = '\0';
}

int main() {
  char word1[10] = "test";
  char word2[10] = "ing";
  cout << "Concatenation:\n";
  strCont(word1, word2);
  cout << word1;
  cout << "\n\nCopying:\n";
  strCopy(word1, word2); // Copies w2 to w1
  cout << word1 << endl;
}