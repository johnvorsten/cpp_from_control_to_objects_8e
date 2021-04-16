/* Chapter 20 Programming challenge 5

Write a recursive function that accepts two arguments into the 
parameters x and y
The function should return the value of x times y
Remember, multiplication can be performed as repeated addition

*/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

int recursive_add(int val1, int val2) {

    // Integers work fine, but multiplication does not...
    if (val2 == 0) {
        return 0;
    }
    else {
        return val1 + recursive_add(val1, val2 - 1);
    }

    return val1;
}

void test_recursive_add() {

    if (recursive_add(2,2) != 4) {
        string msg = "Incorrect result, (2,2)";
        throw std::logic_error(msg);
    }

    if (recursive_add(7,2) != 14) {
        string msg = "Incorrect result, (7,2)";
        throw std::logic_error(msg);
    }

    if (recursive_add(2,7) != 14) {
        string msg = "Incorrect result, (2,7)";
        throw std::logic_error(msg);
    }

    if (recursive_add(100,965) != 96500) {
        string msg = "Incorrect result, (100,965)";
        throw std::logic_error(msg);
    }

}

int main () {

    test_recursive_add();

    return 0;
}