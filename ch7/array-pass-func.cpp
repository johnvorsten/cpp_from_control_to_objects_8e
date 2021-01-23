#include <iostream>

using namespace std;

// Function definitions
void pass_array_reference (int (&bar)[3]) {
    /*Pass an array by reference*/
    std::cout << "\n\n";
    for (auto& x : bar) {
        std::cout << x << ",";
    }
}

template <std::size_t array_size>
void pass_array_template(int (&bar)[array_size]) {
    /*Pass an array by reference without having to define the array size*/
    std::cout << "\n\n";
    for (auto& x : bar) {
        std::cout << x << ",";
    }
}

template <typename T, std::size_t array_size>
void pass_array_template_typename(T (&bar)[array_size]) {
    std::cout << "\n\n";
    for (auto& x : bar) {
        std::cout << x << ",";
    }
}

void pass_array_pointer(int* bar, size_t array_size) {
    /*Pass an array by pointer*/
    std::cout << "\n\n";
    for (int i=0; i < array_size; i++) {
        std::cout << bar[i] << " : ";
    }
}
// Data definitions

int main () {

    int bar[3] = {3,2,1};
    int bar2[6] = {1,2,6,5,4,3};
    float bar3[4] = {4.25,1.55,2.7,3.9};

    // Example
    pass_array_reference(bar);
    //pass_array_reference(bar2); // Error - Invalid for array size

    pass_array_template(bar);
    pass_array_template(bar2);
    // pass_array_template(bar3); // Error - Mismatched identifier

    pass_array_template_typename(bar);
    pass_array_template_typename(bar2);
    pass_array_template_typename(bar3);

    pass_array_pointer(bar, 3);
    pass_array_pointer(bar2, 6);

    return 0;
}