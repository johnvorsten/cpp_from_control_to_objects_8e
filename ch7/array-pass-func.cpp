#include <iostream>

using namespace std;

// Function definitions
void pass_array_reference (int (&bar)[3]) {
    /*Pass an array by reference
    No templates*/
    std::cout << __func__ << std::endl;
    for (auto& x : bar) {
        std::cout << x << '\t';
    }
    std::cout << endl;
}


void pass_array_decayed_pointer(int* bar, size_t array_size) {
    /*Pass an array by pointer
    This is equivalent to 
    void func(int bar[], size_t array_size){}
    
    Call this function like pass_array_decayed_pointer(array)
    */
    std::cout << __func__ << std::endl;
    for (int i=0; i < array_size; i++) {
        std::cout << bar[i] << '\t';
    }
    std::cout << endl;
}


void pass_array_pointer(int (*array)[3][6]) {
    /*Pass by true pointer, not decayed pointer
    When using this function we should pass the array address like
    pass_array_pointer(&array)
    */
    std::cout << __func__ << std::endl;
    for (size_t i=0; i < 3; i++) {
        std::cout << i << ", ";

        for (size_t j=0; j<6; j++) {
            std::cout << (*array)[i][j] << "\t";
        }

        std::cout << std::endl;
    }

}


// int array[][10] is the same notation as this..
void pass_array_pointer_to_decayed_type(int (*array)[6], size_t rows) {
    /*How is this differnet than pass_array_pointer??
    array is a single pointer to an array of 10 integers
    The number of elements in a row is known (10)
    The number of rows must be passed
    */
    std::cout << __func__ << std::endl;

    for (size_t i=0; i<rows; i++) {
        std::cout << i << ", ";

        for (size_t j=0; j<6; j++) {
            std::cout << array[i][j] << '\t';
        }

        std::cout << std::endl;
    }
}


void pass_pointer_to_pointer(int **array, size_t rows, size_t cols) {
    /*array is a pointer to a pointer
    It is an alternative syntax to *array[cols]*/
    std::cout << __func__ << std::endl;
    for (size_t i=0; i<rows; i++) {
        std::cout << ", ";
        for (size_t j=0; j<cols; j++) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}


template <std::size_t array_size>
void pass_array_template(int (&bar)[array_size]) {
    /*Pass an array by reference without having to define the array size
    This only works if the array size is known at compile time
    It will not work with dynamic/freestore arrays*/
    std::cout << __func__ << std::endl;
    for (auto& x : bar) {
        std::cout << x << ",";
    }
    std::cout << endl;
}


template <typename T, std::size_t array_size>
void pass_array_template_typename(T (&bar)[array_size]) {
    /*Pass an array by reference without having to define the array size
    OR its type
    This only works if the array size is known at compile time
    It will not work with dynamic/freestore arrays
    The array type must be known at compile time also*/
    std::cout << __func__ << std::endl;
    for (auto& x : bar) {
        std::cout << x << '\t';
    }
    std::cout << endl;
}


template <typename T, std::size_t rows, std::size_t columns>
void pass_array_template_typename_2d(T (&bar)[rows][columns]) {
    
    std::cout << __func__ << std::endl;
    for (auto& row : bar) {
        for (auto& val : row) {
            std::cout << val << '\t';
        }
        std::cout << "\n";
    }

}




// Data definitions

int main () {

    int arr1[3] = {3,2,1};
    int arr2[6] = {1,2,3,4,5,6};
    float arr3[3] = {1.1, 2.2, 3.3};
    int arr2d1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2d2[3][6] = {{1,2,3,4,5,6}, {7,8,9,10,11,12}, {13,14,15,16,17,18}};
    float arr2d3[3][3] = {{1.1, 2.2, 3.3}, {4.1, 5.2, 6.3}, {7.1, 8.2, 9.3}};

    // Example
    pass_array_reference(arr1);
    //pass_array_reference(arr2); // Error - Invalid size
    // pass_array_reference(arr3) // Error - Invalid type
    // pass_array_reference(arr2d1); // Error - Invalid size
    // pass_array_reference(arr2d2); // Error - Invalid size
    // pass_array_reference(arr2d3); // Error - Invalid size

    pass_array_decayed_pointer(arr1, 3);
    pass_array_decayed_pointer(arr2, 6);
    // pass_array_decayed_pointer(arr3, 3) 
    // pass_array_decayed_pointer(arr2d1); 
    // pass_array_decayed_pointer(arr2d2); 
    // pass_array_decayed_pointer(arr2d3); 

    // pass_array_pointer(&arr1); // Error - Size
    // pass_array_pointer(&arr2); // Error - Size
    // pass_array_pointer(&arr3); // Error - Size
    // pass_array_pointer(&arr2d1); // Error - Size
    pass_array_pointer(&arr2d2); 
    // pass_array_pointer(&arr2d3); // Error - Size

    // pass_array_pointer_to_decayed_type(arr1); // Error - Size
    // pass_array_pointer_to_decayed_type(arr2); // Error - Size
    // pass_array_pointer_to_decayed_type(arr3); // Error - Size
    // pass_array_pointer_to_decayed_type(arr2d1); // Error - Size
    pass_array_pointer_to_decayed_type(arr2d2, 3); 
    // pass_array_pointer_to_decayed_type(arr2d3); // Error - Size

    pass_pointer_to_pointer(&arr1, 0, 3);
    pass_pointer_to_pointer(&arr2, 0, 6);
    pass_pointer_to_pointer(&arr3, 0, 3);
    pass_pointer_to_pointer(&arr2d1, 3, 3); 
    pass_pointer_to_pointer(&arr2d2, 3, 6); 
    pass_pointer_to_pointer(&arr2d3, 3, 3); 

    pass_array_template(arr1);
    pass_array_template(arr2);
    // pass_array_template(arr3);
    // pass_array_template(arr2d1); 
    // pass_array_template(arr2d2); 
    // pass_array_template(arr2d3); 

    pass_array_template_typename(arr1);
    pass_array_template_typename(arr2);
    pass_array_template_typename(arr3);
    pass_array_template_typename(arr2d1); 
    pass_array_template_typename(arr2d2); 
    pass_array_template_typename(arr2d3); 

    // pass_array_template_typename_2d(arr1);
    // pass_array_template_typename_2d(arr2);
    // pass_array_template_typename_2d(arr3);
    pass_array_template_typename_2d(arr2d1); 
    pass_array_template_typename_2d(arr2d2); 
    pass_array_template_typename_2d(arr2d3); 

    return 0;
}