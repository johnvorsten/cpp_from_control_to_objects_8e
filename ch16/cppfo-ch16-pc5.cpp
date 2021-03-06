/*16.5:
=====

Write a function template called total. The function will keep a running
total of values entered by the user, then return the total. The function will
accept one int argument that is the number of values the function is to read.
Test the template in a simple program that would prompt the user to enter
the number of values to read and then read these values from stdin and output
the total. The program will repeat this procedure first for integers, then for
doubles.

*/


#include <string>
#include <iostream>
#include <iomanip>

namespace hcc {

template <typename T> 
T total(int n_vals) {
    T sum = 0;
    T val = 0;

    for (int i = 0; i < n_vals; i++) {
        std::cin >> val;
        sum += val;
    }

    return sum;
}

template <typename T>
void stdout_total(T total, int n_vals) {
    // std::cout << std::setprecision(1);
    std::cout << "Total = " << total << "\n";
}

void user_input() {

    // Total integers
    int n_vals;
    std::cout << "Enter: the number of ints you wish to enter: ";
    std::cin >> n_vals;
    std::cout << "Enter: " << n_vals << " integers: ";
    auto res1 = total<int>(n_vals);
    stdout_total(res1, n_vals);

    // Total doubles
    std::cout << "Enter: the number of doubles you wish to enter: ";
    std::cin >> n_vals;
    std::cout << "Enter: " << n_vals << " doubles: ";
    auto res2 = total<double>(n_vals);
    stdout_total(res2, n_vals);

}


}; // End of namespace

using namespace hcc;

int main () {

    user_input();

    return 0;
}