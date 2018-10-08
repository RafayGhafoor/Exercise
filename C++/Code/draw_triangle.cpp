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
    cout << "==============Print Right Triangle===============\n";
    cout << "Enter size: "; int size;
    cin >> size;
    int a = 0;
    for (int i=size; i>=0; i--, a++) {
        spaces(a); stars(i); cout << endl;
    }
    
    cout << "==============Print Left Triangle===============\n";
    cout << "Enter size: "; int size1;
    cin >> size1;
    int a1 = 0;
    for (int i=size1; i>=0; i--, a1++) {
        
        stars(i); spaces(a1); cout << endl;
    }
    
}
    
    
    
    

