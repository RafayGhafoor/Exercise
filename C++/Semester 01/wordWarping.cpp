#include <cstring>
#include <iostream>
using namespace std;

int main() {

  char mat[8][9] = {"xxoxenwn", "enoxenf", "abcdeef", "abcdeef",
                    "aboxeng",  "abcdefg", "abcoxen", "oxeneeo"};

  char str[] = "oxen";

  int str_len = strlen(str) - 1, count = 0, len = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      bool found = true;

      for (int x = j; x <= j + str_len && found; x++) {
        if (mat[i][x] == str[len]) {
          cout << "MATCH > " << str[len] << endl;
          len++;
        }

        else if (mat[i][x] != str[len]) {
          cout << "NOT MATCH > " << mat[i][x] << endl;

          found = false;
          len = 0;
        }

        if (len >= str_len) {
          count++;
          len = 0;
        }
      }
      len = 0;
    }
  }
  cout << count;
  return 0;
}