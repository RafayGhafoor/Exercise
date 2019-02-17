#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdlib.h>

class String
{
  public:
    static int count;

    int count = 0;
};
int main() { int String::count = 0; }
