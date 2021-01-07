#include <iostream>
#include <exception>
using namespace std;

int main() {
    int a=0,b=0;
    int c=1,d=1;
    
    // If statement
    if (!a)
        printf("The value of a is evaluated to false\n");
    if (!b)
        printf("The value of a is evaluated to false\n");
    if (c)
        printf("The value of c is evaluated to true\n");
    if (d)
        printf("The value of c is evaluated to true\n");

    // Switch
    switch(a) {
        case 0:
            cout << "A is false by switch case" << endl;
            break;
        case 1:
            throw std::logic_error("A should not be true");
            break;
    }
    
    // and or
    if (a || c)
        cout << "A is false, but c is true so this is printed" << endl;
    if (a && c)
        throw std::logic_error("A should not be true");
    else
        cout << "A is false, and c is true. This printed from the else";
        cout << " result of a && operator" << endl;


    // Nested if statement
    a=0; 
    b=1;
    if (a==0){
        if (b==1){
            cout << "A is 0 and B is 1 (This is expected behavior)" << endl;
        }
        else if (b == 0){
            cout << "A is 0 and B is 0" << endl;
            throw std::logic_error("This shold not execute");
        }
    }
    else if (a == 1){
        if (b == 1){
            cout << "A is 1 and B is 0" << endl;
            throw std::logic_error("This should not execute");
        }
        else if (b == 0){
            cout << "A is 1 and B is 0" << endl;
            throw std::logic_error("This should not execute");
        }
    }
    else {
        throw std::logic_error("This should not execute");
    }

}