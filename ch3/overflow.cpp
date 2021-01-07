// Overflow

#include <iostream>
using namespace std;

int main() {
    float test;

    test = 2.0e38 * 1000; //overflow
    cout << test << endl;
    test = 2.0e-38 / 2.0e38;
    cout << test << endl;
    return 0;
}