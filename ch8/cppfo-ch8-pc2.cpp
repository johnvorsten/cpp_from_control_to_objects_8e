#include <vector>
#include <iostream>

using namespace std;


int main () {

    vector<int> lucky = {13579, 26791, 26792, 33445, 55555,
                62483, 77777, 79422, 85647, 93121};
    int winning = {0};
    bool won = false;

    std::cout << "Enter this week's 5-digit winning lottery number:";
    std::cin >> winning;


    for (auto& x : lucky) {
        if (x == winning) {
            
            bool won = true;
        }
    }
    if (won)
        std::cout << "You won this week" << endl;
    else
        std::cout << "You did not win this week." << endl;

    return 0;
}