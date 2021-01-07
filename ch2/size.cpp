// size of an object

#include <iostream>

using namespace std;

int main() {

    struct holder {
        int i1;
        long int i2; 
        short int i3;
        bool truth; 
        float f1;
        double f2;
        long double f3;
    } item;

    item.i1 = 1;
    item.i2 = 2;
    item.i3 = 3;
    item.truth = true;
    item.f1 = 1.1;
    item.f2 = 1.2;
    item.f3 = 1.3;

    cout << sizeof(item.i1) << endl;
    cout << sizeof(item.i2) << endl;
    cout << sizeof(item.i3) << endl;
    cout << sizeof(item.truth) << endl;
    cout << sizeof(item.f1) << endl;
    cout << sizeof(item.f2) << endl;
    cout << sizeof(item.f3) << endl;
}