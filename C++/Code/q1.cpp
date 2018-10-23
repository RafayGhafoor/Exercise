#include <iostream>

using namespace std;

bool searchTillIndex(int number[], int find,int size, int in) {
    for (int i=0; i<=in; i++) {
        if (number[i] == find)
            return 1;
    }
    
    return 0;
}

int main() {
    int size = 10;
    int number[size] = {1, 5, 77, 22, 1, 33, 111, 12, 33, 1};
    int find = 12;
    if (searchTillIndex(number, find, size, 7))
        cout << "Yes";
    
}
