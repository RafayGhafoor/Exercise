#include <iostream>
using namespace std;

int main()
{
    int num = 8;
    int *listPtr = new int[5];
    int *temp = listPtr;

    for (int j = 0; j < 5; j++)
    {
        *listPtr = num; // listptr[0] = 8, listptr[1] = 10, listptr[2] = 12,
        // listptr[3] = 14, listptr[4] = 16
        num = num + 2;
        listPtr++; // listptr now points towards 1
    }
    listPtr = temp;

    for (int k = 0; k < 5; k++)
    {
        *temp = *temp + 3; // temp[0] = 3
        temp++;
    }

    for (int k = 0; k < 5; k++)
    {
        cout << *listPtr << " ";
        listPtr++;
    }

    cout << endl;
}