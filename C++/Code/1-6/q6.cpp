#include <iostream>

using namespace std;

const double pi = 3.141592653589793238463;

float Area(float);
float Area(float, float);
float Area_triangle(float, float);

int main() {
    int choice;
    cout << "#####Welcome to Area Calculator######\n";
    cout << "1) Press 1 to calculate area of a circle.\n\
2) Press 2 to calculate area of a triangle.\n\
3) Press 3 to calculate area of a cylinder.\n\nEnter your choice:\n>>> ";
    cin >> choice;
    if (choice == 1) {
        int radius; cout << "\nPlease enter radius:\n>>> "; cin >> radius;
        cout << "\nThe area of circle is: " << Area(radius) << endl;
    }

    else if (choice == 2 || choice == 3) {
        float height;
        cout << "\nPlease enter height:\n>>> "; cin >> height; 
        
        if (choice == 2) {
            float base;
            cout << "\nPlease enter base:\n>>> "; cin >> base; 
            cout << "\nThe area of triangle is: " << Area_triangle(height, base) << endl;
            }
        else {
            float radius;
            cout << "\nPlease enter radius:\n>>> "; cin >> radius;
            cout << "\nThe area of cylinder is: " << Area(height, radius) << endl;
        }
    }
    
}


float Area(float radius){
    // Calculates Area of Circle
    return pi*radius*radius;
}


float Area(float height, float radius){
    // Calculates Area of Cylinder
    return (2*pi*radius*height) + (2*pi*radius*radius);
}


float Area_triangle(float height, float base){
    return height * (base/2);
}

