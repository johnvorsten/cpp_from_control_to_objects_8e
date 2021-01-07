// Conditional operator expression ? expression : expression;
// Example (boolean expression) ? then value1 else value2
// (boolean expression) ? value1 : value2
// (x > 1) ? y=true : y=false; // If x > 1 then y=true, else y=false

#include <cassert>
#include <iostream>

using namespace std;

int main () {
    int a=0;
    // Test the value of a variable
    (a==true) ? (throw std::logic_error("A should be false")) : cout << "A is false";
    
    // Conditionally assign the value of a variable
    // if c is true, then b is also true
    int b, c=true;
    b = (c) ? true : false;
    assert(b == true);
}
