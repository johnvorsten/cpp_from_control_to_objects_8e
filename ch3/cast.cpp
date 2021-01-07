#include <iostream>
using namespace std;

int main() {
    char var = 'b';
    cout << var << endl;
    cout << static_cast<int>(var) << endl;

    int var2 = 20;
    cout << var2 << endl;
    cout << static_cast<double>(var2) << endl;
    cout << static_cast<float>(var2) << endl;
    cout << static_cast<chr>(var2) << endl;

    return 0;

}