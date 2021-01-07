// Math functions
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    float res;

    // absolute value
    cout << "abs\n";
    res = abs(-10);
    cout << res << endl;
    // cos
    cout << "cos\n";
    res = cos( 3.1415 / 2); // radians
    cout << res<< endl;
    
    //exp
    cout << "exp\n";
    res = exp( 2 );
    cout << res<< endl;
    
    // modulo only works with integers
    cout << "fmod\n";
    res = fmod(413, 15);
    cout << res<< endl;

    // Natural log
    cout << "log\n";
    res = log(10);
    cout << res<< endl;

    // Base 10 log
    cout << "log10\n";
    res = log10(10);
    cout << res;

    cout << "sin\n";
    cout << sin(3.1514 / 2)<< endl; // radians
    cout << "sqrt\n";
    cout << sqrt( 10 )<< endl;
    cout << "tan\n";
    cout << tan( 3.1514 / 2 )<< endl; // radians
}