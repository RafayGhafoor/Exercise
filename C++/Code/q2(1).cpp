#include <iostream>

using namespace std;


bool is_present(int number, int array[], int size) {
    for (int i=0; i<=size; i++)
        if (number == array[i]) return 1;
    return 0;
}


int filter(int array[], int filtered_array[], int size) {
    int index=0;
    for (int i=0; i<=size; i++) {
        if (is_present(array[i], filtered_array, size) == false) {
            filtered_array[index] = array[i];
            index++;
        }
    }
    return index;
}


int main() {
    int user_array[25] = {1, 5, 77, 22, 1, 33, 111, 33, 12, 1, 44, 22, 1, 1, 22};
    int set[25] = {0}; // Contains unique elements of user_array
    int breakpoint = filter(user_array, set, 25);   
    
    for (int i=0; set[i]!=set[breakpoint]; i++) {
        int frequency=0;
        for (int j=0; j<=25; j++) {
            if (set[i] == user_array[j])
                frequency += 1;
        }
    
        cout << set[i] << ": " << frequency << endl; 
    }
}
