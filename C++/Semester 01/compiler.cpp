#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

bool checkBracket(char input[], string bracket) {
  bool left_bracket = false, right_bracket = false;

  for (int i = 0; i < strlen(input); i++)
    if (input[i] == bracket[0])
      left_bracket = true;
    else if (input[i] == bracket[1])
      right_bracket = true;

  if (left_bracket && !right_bracket) {
    cout << "Error: " << bracket[1] << " expected\n";
    return 0;
  } else
    return 1;
}

bool checkSemiColon(char input[]) {
  if (input[strlen(input) - 1] != ';') {
    cout << "Error : ';' expected\n";
    return 0;
  } else
    return 1;
}

bool checkDataType(char input[]) {
  string datatype = "";
  string CPPDT[10] = {"string", "char", "array",   "int",  "float",
                      "double", "long", "wchar_t", "bool", "void"};

  bool match = false;

  for (int i = 0; input[i] != ' ' && i < strlen(input); i++)
    datatype += input[i];

  for (int i = 0; i < 11 && !match; i++) {
    if (CPPDT[i] == datatype)
      match = true;
  }

  if (!match) {
    cout << "(" << datatype << ")   "
         << "Wrong Data Type\n";
    return 0;
  } else
    return 1;
}

int main() {
  char input[100];

  while (strcmp(input, "return 0;")) {
    cin.getline(input, 100);
    if (!checkDataType(input))
      continue;
    else if (!checkBracket(input, "{}"))
      continue;
    else if (!checkBracket(input, "()"))
      continue;
    else if (!checkSemiColon(input))
      continue;
  }
}