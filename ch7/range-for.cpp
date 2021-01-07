#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main () {

    // Range based for loop
    std::string song[] {"99","bottles","of","beer","on","the","wall"};
    for (auto x : song) {
        std::cout << x << " ";
    }

    std::cout << "Attempting to modify loop in range based for" << endl;
    for (auto x : song) {
        x = "Something else";
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "But range based for loops create copies of values" << endl;
    for (auto x : song) {
        std::cout << x << " ";
    }

    return 0;
}