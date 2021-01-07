#include <iostream>

using namespace std;

int reference(int & alias) {
    alias++;
    return alias;
}

int main() {
    int primary = 0;
    std::cout << "Initial values : \nprimary : " << primary;

    for (int i=0;i<10;i++) {
        reference(primary);
    }
    std::cout << "\n\n";
    std::cout << "Final values : \nprimary: " << primary;
    std::cout << "\n\n";
    
    for (int i=0; i<10; i++) {
        cout << "Current loop iteration : " << i << endl;
        reference(i);
    }

    return 0;
}