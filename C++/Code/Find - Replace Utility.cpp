#include <cstring>
#include <iostream>

using namespace std;

bool findSubstring(char sentence[], char find[], int &index) {

  bool match = false;

  int find_len = strlen(find) - 1;

  while (!match && index < strlen(sentence)) {

    if (sentence[index] == find[0] &&
        sentence[index + find_len] == find[find_len]) {

      match = true;

      for (int i = 0, enumeration = index; i <= find_len && match;
           i++, enumeration++) {

        if (sentence[enumeration] != find[i])
          match = false;
      }
    }

    index++;
  }
  index--;
  return match;
}

void replaceSubStr(char sentence[], char sub[], int index) {
  int sub_len = strlen(sub) + index;

  for (int i = 0; index < sub_len; index++, i++)
    sentence[index] = sub[i];
}

void replaceAll(char sentence[], char find[], char sub[], int index) {
  bool match = true;
  while (index < strlen(sentence) && match)

    if (findSubstring(sentence, find, index))
      replaceSubStr(sentence, sub, index);

    else
      match = false;
}

int main() {
  char sen[100], find[10], rep[10];
  cout << "********** [Find - Replace Utility] **********\n";
  cout << "Please enter a sentence:\n>>> ";
  cin.getline(sen, 100);
  cout << "Please enter the characters you want to find:\n>>> ";
  cin.getline(find, 100);
  cout << "Please enter the characters you want to replace find with:\n>> ";
  cin.getline(rep, 100);

  int fIndex = 0;

  if (findSubstring(sen, find, fIndex)) {
    cout << "[" << find << "]"
         << " - Found!\n";

    replaceAll(sen, find, rep, fIndex);

    cout << "Altered Sentence is: " << sen << endl;
  } else
    cout << "[" << find << "]"
         << " - Not Found!\n";
}