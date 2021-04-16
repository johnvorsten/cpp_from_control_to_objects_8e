#include <array>
#include <iostream>

using namespace std;

int main () {

    // Declare an array with variable size (not allowed)
    int n;
    std::cout << "Enter an integer";
    std::cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = i;
    }

    // This might cause an error
    const int size=5;
    double x[size];
    for (int i = 2; i <= size; i++) {
        x[i] = 0.0;
    }


    return 0;
}