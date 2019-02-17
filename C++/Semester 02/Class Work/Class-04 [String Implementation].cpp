#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;

class String {

private:
  char str[256];

public:
  // Constructor 1 {Default Constructor}
  String() {
    str[0] = 0; // initialize the first index of str to null character
  }

  // Constructor 2
  String(char input[]) { strcpy(str, input); }

  // Constructor 3
  String(int input) {
    string var = to_string(input);
    for (int i = 0; i < var.length(); i++) {
      str[i] = var[i];
    }
  }

  String concat(String const &obj) {
    String ans = obj;

    int size = strlen(str), i = size, j = 0;

    for (; i < size + strlen(ans.str); i++, j++)
      ans.str[size + i] = str[j];

    ans.str[i] = 0;

    return ans;
  }

  const int length() {
    int len = 0;

    for (; str[len] != 0; len++)
      ;
    return len;
  }

  void print() { cout << str << endl; }
};

// A null terminated string (Constructor 1) [No argument specified]
//
int main() {
  char abc[] = "Hello!", test[] = "abc";
  String S(1234);
  S.print();
  // String S(test), x, t(abc);

  // cout << "Length of t is: " << t.length() << endl;

  // x = S.concat(t); // Concatenates the content of t at the end of s and the
  //                  // resultant is copied into x
  // x.print();

  // S = t; // Copies t in S

  // S.print();
  // t.print();
}