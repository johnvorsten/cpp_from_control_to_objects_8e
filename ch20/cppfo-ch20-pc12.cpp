/*19-12) Ackermann’s Function

Ackermann’s Function is a recursive mathematical 
algorithm that can be used to test how well a 
computer performs recursion. Write a function 
A(m, n) that solves Ackermann’s Function. Use 
the following logic in your function:

If m = 0 then return n + 1
If n = 0 then return A(m−1, 1) Otherwise, return A(m−1, A(m, n−1))

Test your function in a driver program that displays the following values:

A(0, 0) A(0, 1) A(1, 1) A(1, 2) A(1, 3) A(2, 2) A(3, 2)*/

#include <iostream>

using namespace std;

int ackermanns(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return ackermanns(m-1, 1);
    }
    else {
        return ackermanns(m-1, ackermanns(m, n-1));
    }

    return ackermanns(m-1, ackermanns(m, n-1));
}


int main () {

    std::cout << "The value of A(0, 0)= " << ackermanns(0, 0) << "\n";
    std::cout << "The value of A(0, 1)= " << ackermanns(0, 1) << "\n";
    std::cout << "The value of A(1, 1)= " << ackermanns(1, 1) << "\n";
    std::cout << "The value of A(1, 2)= " << ackermanns(1, 2) << "\n";
    std::cout << "The value of A(1, 3)= " << ackermanns(1, 3) << "\n";
    std::cout << "The value of A(2, 2)= " << ackermanns(2, 2) << "\n";
    std::cout << "The value of A(3, 2)= " << ackermanns(3, 2) << "\n";

    return 0;
}