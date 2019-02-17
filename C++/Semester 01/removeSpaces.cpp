#include <cstring>
#include <iostream>
using namespace std;

int main()
{

    char word[] = "Hello    World";

    int i = 0;

    for (int j = 0; i < strlen(word); i++, j++)
    {

        while (word[j] == ' ')
        {
            j++;
        }

        word[i] = word[j];
    }

    word[i] = 0;

    cout << word;
}
