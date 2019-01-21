#include <cstring>
#include <iostream>
using namespace std;

bool findChar(char arr[][20], int rows, char word[])
{
    for (int i = 0; i < rows; i++)
        if (!strcmp(arr[i], word))
            return true;

    return false;
}

int main()
{
    // Define Array containing words
    char arr[3][20] = {"word", "test", "play"};

    char w[20];
    cout << "Enter Word to find:\n>>> ";
    cin >> w;

    // Search for word in array
    if (findChar(arr, 3, w))
        cout << w << " [FOUND]!";
    else
        cout << w << " [NOT FOUND]!";
}
