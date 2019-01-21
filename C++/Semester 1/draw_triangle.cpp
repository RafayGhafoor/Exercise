#include <iostream>

using namespace std;

void spaces(int N) {
    for (int i=1; i<=N; i++)
        cout << " ";
}

void stars(int N) {
    for (int i=1; i<=N; i++)
        cout << "*";
}

int main() {
    cout << "==============Drawing Right Triangle===============\n";
    cout << "Enter size: "; int size;
    cin >> size;
    for (int i=size; i>=1; i--) {
        spaces(size - i); stars(i); cout << endl;
    }
    
    cout << "==============Drawing Left Triangle===============\n";
    for (int i=size; i>=1; i--) {
        stars(i); cout << endl;
    }
    
}
