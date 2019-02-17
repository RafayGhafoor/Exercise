#include <cstring>
#include <iostream>

using namespace std;

bool strCmp(char w1[], char w2[]) {
  int w1_len = strlen(w1);
  bool match = true;

  if (w1_len != strlen(w2))
    match = false;

  for (int i = 0; (i <= w1_len && match); i++)
    if (w1[i] != w2[i])
      match = false;

  return match;
}

int main() {
  char a[100];
  char b[100];
  cin.getline(a, 100);
  cin.getline(b, 100);
  if (strCmp(a, b))
    cout << "Match Found!\n";
  else
    cout << "Match Not Found!\n";
}