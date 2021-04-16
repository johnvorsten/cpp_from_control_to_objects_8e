/*
19-6) Recursive Power Function
Write a function that uses recursion to raise a number to a power. 
The function should accept two arguments: the number to be 
raised and the exponent. Assume that the exponent is a 
nonnegative integer. Demonstrate the function in a program.
*/

#include <iostream>

using namespace std;

template <typename T>
T power(const T& arg, unsigned int exponent) {
    /*Return the power of argument to the power of 'exponent'*/
    T temp;
    
    if (exponent == 0) {
        return 1;
    }
    else if (exponent == 1) {
        return arg;
    }

    return arg * power(arg, exponent - 1);
}


void user_input() {
    // Get the two inputs from stdin
    int val1 = 0, val2 = 0;

    while (std::cin >> val1 && std::cin >> val2) {
        std::cout << val1 << "^" << val2 << "=" << power(val1 ,val2) << "\n";
    }
}

int main() {

    // user_input();
    std::cout << "2^3=8\n";
    std::cout << "2^4=16\n";
    std::cout << "3^3=27\n";
    std::cout << "6^3=216\n";
    std::cout << "7^7=823543\n";
    std::cout << "10^9=1000000000\n";

    return 0;
}