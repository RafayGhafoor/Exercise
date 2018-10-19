#include <iostream>

using namespace std;

bool is_present(int number, int array[], int size) {
    for (int i=0; i<=size; i++)
        if (number == array[i]) return 1;
    return false;
}

int main() {
    int iter_count = 0;
    int set[25] = {0}; // Contains unique elements of user_array
    int freq_array[25] = {0};
    int user_array[25] = {1, 5, 77, 22, 1, 33, 111, 33, 12, 1, 44, 22, 1, 1, 22};
    
    for (int i=0; i<=25; i++) {
    
        if (is_present(user_array[i], set, 25)) {
            iter_count += 1; continue;  
        }
    
        for (int j=0; j<=25; j++) {
    
            if (user_array[i] == user_array[j])
                freq_array[i] += 1;
    
        }
        
        set[i] = user_array[i]; 
    }
    
    cout << "Item:\tCount:" << endl;
    
    for (int i=0; i<=iter_count; i++) {
        if (freq_array[i] > 0) 
            cout << " " << set[i] << "\t" << "  " << freq_array[i] << endl;
    }
}
