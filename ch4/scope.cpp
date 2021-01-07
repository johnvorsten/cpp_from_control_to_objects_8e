// Variable scope

#include <iostream>
using namespace std;

int main () {
    // Define a variable in the local function scope
    int foo = true;

    // Define a variable in another block scope
    // anonymous scope
    if (foo) {
        bool foo = false;
        cout << "The value of foo is : " << foo << "in an anonymous scope" << endl;
    }

    cout << "The value of foo is : " << foo << " in the main function scope" << endl;

}