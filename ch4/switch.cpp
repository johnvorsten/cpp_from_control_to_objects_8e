#include <iostream>

using namespace std;

int main () {
    int a=0;
    switch (a) {
        case 0:
            cout << "A is false" << endl;
            break;
        case 1:
            cout << "A is true" << endl;
            throw std::logic_error("A should be false");
        default:
            cout << "A should be false" << endl;
            throw std::logic_error("A should be false");
    }
}