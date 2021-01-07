#include <iostream>

using namespace std;

void print_static_local() {
    static int local = 0;
    cout << local << " ";
    local++;
}

int main() {

    for (int i=0;i<5;i++) {
        print_static_local();
    }
    return 0;
}