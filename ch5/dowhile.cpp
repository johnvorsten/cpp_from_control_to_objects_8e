#include <iostream>
#include <string>

using namespace std;

int main () {
    /* do while loop syntax
    do
        statement;
    while (expression);

    do {
        statement;
        statement;
    } while (expression);
    */

    string user_input;

    do {
        cout << "Enter the number 1 : ";
        std::getline(cin, user_input);
        if (user_input == "1")
            cout << "Good job! :)" << endl;
        else
            cout << "Bad job! :(" << endl;
    } while ((user_input != "1"));

    return 0;
}