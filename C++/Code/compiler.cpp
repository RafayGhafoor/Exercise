#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

bool checkParanthesis(char input[]) {
  bool left_paranthesis = false, right_paranthesis = false;

  for (int i = 0; i < strlen(input); i++)
    if (input[i] == '(')
      left_paranthesis = true;
    else if (input[i] == ')')
      right_paranthesis = true;

  if (left_paranthesis && !right_paranthesis) {
    cout << "Error: ')' expected\n";
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

bool checkBraces(char input[]) {
  bool left_braces = false, right_braces = false;

  for (int i = 0; i < strlen(input); i++)
    if (input[i] == '{')
      left_braces = true;
    else if (input[i] == '}')
      right_braces = true;

  if (left_braces && !right_braces) {
    cout << "Error: '}' expected\n";
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
    else if (!checkBraces(input))
      continue;
    else if (!checkParanthesis(input))
      continue;
    else if (!checkSemiColon(input))
      continue;
  }
}