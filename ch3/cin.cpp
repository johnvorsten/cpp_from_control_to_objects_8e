// This program asks for user input
// Simple payroll calculator
// for cout and cin
#include <iostream>
using namespace std;

int main() {
    int length, width;
    float area;

    cout << "Calculate area of a rectangle\n";
    cout << "Enter dimension length : ";
    cin >> length;
    cout << "\n";
    cout << "Enter dimension width : ";
    cin >> width;
    cout << "\n";

    // Calculate area
    area = length * width;
    cout << "The area is : " << area << endl;

    // Multiple input
    cout << "Calculate area of a rectangle\n";
    cout << "Enter dimension length, width : ";
    cin >> length >> width;

    // Calculate area
    area = length * width;
    cout << "The area is : " << area << endl;

    // A program has the following variable definitions.
    // long miles; int feet; float inches; 
    //Write one cin statement that reads a value into each of these variables
    long miles; int feet; float inches;
    cout << "\n\nEnter miles, feet, inches : ";
    cin >> miles >> feet >> inches;
    cout << "\n";
    cout << "Miles : " << miles << "\n"; 
    cout << "feet : " << feet << endl;
    cout << "inches : " << inches << endl;


    return 0;
}