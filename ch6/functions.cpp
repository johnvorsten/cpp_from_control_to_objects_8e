#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

// Space for function call signatures - CALLED PROTOTYPES
// The compiler must know the function name, return type, and parameter list
// The body may be defined elsewhere
// AKA Header files
void null_function ();
bool is_odd(int val) {
    return val % 2;
}
bool is_odd_by_ref(const int & val) {
    return val % 2;
}
int return_int (int& x);
string return_string(string & val);


int main () {

    // Pass by value
    for (int arg : {-2, -1, 0, 1, 2}) {
        std::cout << is_odd(arg) << " ";
    }
    std::cout << "\n\n";

    // Pass by reference
    for (int arg : {-2, -1, 0, 1, 2}) {
        std::cout << is_odd_by_ref(arg) << " ";
    }
    std::cout << "\n\n";

    // Call a null function
    null_function();
    std::cout << "\n\n";

    // Pass and return integer
    int val1 = 1;
    auto res1 = return_int(val1);
    auto res2 = return_int(val1);
    printf("Pass return integer results %i %i", res1, res2);
    std::cout << "\n\n";

    // Pass by reference and return string
    string str1 = "Something - ";
    auto res3 = return_string(str1);
    cout << res3;
    printf("Pass and return string results : %s", res3.c_str());
    std::cout << "\n\n";

    return 0;
}








void null_function() {
    // Just print to console
    std::cout << "null_function called" << endl;
}

int return_int(int & val) {
    return val + 9;
}

string return_string(string & val) {
    string other = "Other";
    // return other;
    return val.append(other);
}
