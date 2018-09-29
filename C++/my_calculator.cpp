#include <iostream>
#include <math.h>
// #include </home/rafay/Music/conio.h>?
#include <curses.h>

using namespace std;

int main() {
    cout << "********************My Calculator********************\n\n";
    int choice;
    float operand;

     initscr();	
    while (1) {
    cout << "1. Add\n2. Divide\n3. Magnitude\n4. Power\n5. Exit\n\n";
    cout << "Please choose your option: ";
    cin >> choice;
    cout << endl;

    if (choice == 3 || choice == 4) {
    
        cout << "Please enter a number: ";
        cin >> operand;
    
        if (choice == 3) {
        
            if (operand < 0) 
                cout << "\nThe result is: " << operand *  -1 << endl;
            else
                cout << "\nThe result is: " << operand << endl;
        }
        
        else if  (choice == 4) 
            cout << "\nThe result is: " << pow(2, operand) << endl;
            
        }
    

    else if (choice == 1 || choice == 2 || choice == 3) {
    
        float operand1;
        cout << "Please enter first number: ";
        cin >> operand;
        cout << "Please enter second number: ";
        cin >> operand1;
    
        if (choice == 1)
            cout << "\nThe result is: " << operand1 + operand << endl;
        
        else if (choice == 2)
            cout << "\nThe result is: " << operand / operand1 << endl;        
    }

    else if (choice == 5)
        break;

    cout << "\nPress any key to return to the menu!\n\n";
    getch();
    // system("clear");
    }
}

