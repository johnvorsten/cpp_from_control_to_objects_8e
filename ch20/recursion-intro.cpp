#include <iostream>
#include <array>
#include <string>

using namespace std;

// Classes
// ADT
// Function Definitions
size_t factorial(size_t n) {
    /*Calculate the factorial of a number*/
    if (n == 0) [[unlikely]]
        return 0;
    else if (n == 1)
        return 1;
    else [[likely]]
        return n * factorial(n - 1);
}

int starsCount(string& str, int index) {
    if (str.length() < index) {
        return 0;
    }
    else if (str[index] == '*') {
        return 1 + starsCount(str, index + 1);
    }

    return starsCount(str, index + 1);
}

int main () {

    // Factorial recursion
    std::cout << "The factorial of 10 is : " << factorial(10) << endl;
    std::cout << "The factorial of 8 is : " << factorial(8) << endl;
    std::cout << "The factorial of 7 is : " << factorial(7) << endl;
    std::cout << "The factorial of 5 is : " << factorial(5) << endl;


    string str = "*341nngfj**jrka*";
    std::cout << "Number of stars..." << starsCount(str, 0) << std::endl;
    std::cin.ignore(100, '\n');



    return 0;
}