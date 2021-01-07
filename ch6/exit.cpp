#include <iostream>
#include <cstdlib>

using namespace std;

void func() {
    std::cout << "Beginning function call" << endl;
    std::cout << "Exiting program - Bye!" << endl;
    exit(0);
    std::cout << "This line will never be displayed" << endl;
}


int main () {
    func();
    return 0;
}