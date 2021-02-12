#include <iostream>

using namespace std;

int main () {
    char c = 'n';

    while (c != 'Y' && c !='y' && c != 'N' && c != 'n') {
        std::cin >> c;
    }


    {/**/
        char ssn[9] = {'2','3','1','4','5','1','2','3','4'};
        // std::cin >> ssn;

        for (int i=0; i<3; i++) {
            std::cout << ssn[i] << endl;
        }
    }

    return 0;
}