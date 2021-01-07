#include <vector>
#include <iostream>


using namespace std;

int main () {

    const int ARRAY_SIZE = 5;
    float array[ARRAY_SIZE] {1,2,3,4,5};
    // Fancy...
    for (auto& x : array) {
        x++;
    }

    // Automatic assignment is not allowed
    float new_array[ARRAY_SIZE];
    // new_array = array; // NOT allowed
    // Anytime the name of an array is used without 
    // brackets and a subscript, it is seen as the array’s 
    // beginning memory address .

    // CORRECT
    for (int i=0; i< ARRAY_SIZE; i++) {
        new_array[i] = array[i];
    }

    // Maximum value of array
    const int ARRAY_SIZE2 = 135233;
    float arr2[ARRAY_SIZE2];
    float highest = arr2[0];
    for (int i=1; i < (sizeof(arr2)/sizeof(arr2[0])); i++) {
        if (arr2[i] > highest) {
            highest = arr2[i];
        }
    }
    std::cout << "The highest value in the array is " << highest;



    return 0;
}