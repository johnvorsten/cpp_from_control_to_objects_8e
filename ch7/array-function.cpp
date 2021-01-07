#include <iostream>

using namespace std;

void const_array(const int some_array[], int size) {
    // Do stuff
}

void pass_array(int some_array[], int size) {
    // Do stuff
}


int main () {

    const int ARRAY_SIZE = 5;
    int some_array[ARRAY_SIZE];

    const_array(some_array, ARRAY_SIZE);
    pass_array(some_array, ARRAY_SIZE);

    return 0;
}