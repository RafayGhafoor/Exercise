#include <cstring>
#include <iostream>

using namespace std;

bool findSubstring(char sentence[], char sub[], int index, int &foundIndex) {

  bool match = false;

  int sub_len = strlen(sub) - 1;

  while (!match && index < strlen(sentence)) {

    if (sentence[index] == sub[0] &&
        sentence[index + sub_len] == sub[sub_len]) {

      match = true;
      foundIndex = index;

      for (int i = 0, enumeration = index; i <= sub_len && match;
           i++, enumeration++) {

        if (sentence[enumeration] != sub[i])
          match = false;
      }
    }

    index++;
  }

  return match;
}

// void replaceSubStr(char sentence[], char sub[], int index) {}

int main() {
  char sen[30] = "Rafay Ghafoor Awan";
  char sub[10] = "or";
  int fIndex = 0;
  if (findSubstring(sen, sub, fIndex, fIndex))
    cout << "Yes\n" << fIndex << "\n";
}