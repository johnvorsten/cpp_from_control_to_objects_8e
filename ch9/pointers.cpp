#include <iostream>
#include <stdio.h>

using namespace std;

void print_section(const char* str) {
    printf("\n\n%s\n", str);
}

int main () {
    // Create a variable
    int a = 25;
    // Null initialization
    int* a_pointer = nullptr;
    // Reference the address of a. Remember & is like 'at' or 'address'
    a_pointer = &a; 

    // The value held by a_pointer is literally an address
    std::cout << "The address of a is : " << a_pointer << endl;
    // Reference the data value of a pointer by using the * indirection operator
    std::cout << "The value of a is : " << *a_pointer << endl;
    // Another way to print the address of a variable
    std::cout << "The address of a using reference & symbol : " << &a << endl;

    // Change the value at a using indirection operator
    *a_pointer = 100;
    std::cout << "The value of a is now : " << a << " (With indirection : " << *a_pointer << ")" << endl;

    /*Section 9.3 - Arrays and pointers*/
    // Define an array
    int arr[] {10,20,30,40,50};
    // Because array variables work like a pointer to the first element in the array
    // dereferencing the variable acts as retrieving the first element
    printf("The first value of arr is : %i\n", *arr);
    // Next memory location in array
    printf("The second value of arr is : %i\n", *(arr+1));
    printf("The third value of arr is : %i\n", *(arr+2));

    {/*9.4 - Pointer arithmetic*/
    printf("\n\n9.4 - Pointer arithmetic\n");
    // Number of elements in array
    int n_elements = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        // Print the contents of an array
        std::cout << *(arr + i) << " ";
    }
    std::cout << endl;


    for (int i=1; i <= n_elements; i++) {
        // Print referse contents
        std::cout << *(arr + n_elements - i) << " ";
    }
    std::cout << endl;
    }


    { /*9.5 - Initializing integers*/
    printf("\n\nSection 9.5 - Initializing integers\n");
    // int a = 25; // Already initialized
    int a = 10;
    int* aptr = &a; // Good, reference integer
    int arr[] {10,20,30,40,50};
    int* arrptr = arr; // Good, reference integer array
    float b = 20.3;
    // int* bptr = &b; // Bad - incompatible data type
    float* bptr = &b; 
    double readings[50], *marker = readings; // OK
    int myValue, *pint = &myValue; // OK
    }


    {/*9.6 - Comparing pointers*/
    printf("\n\nSection 9.6 - Comparing pointers\n");
    double readings[50], *marker = readings; // OK
    bool compare = (&readings[0] > &readings[1]); // False
    printf("Pointer comparision (&readings[0] > &readings[1]) : %i\n", compare);
    compare = (&readings[1] > &readings[0]); // true
    printf("Pointer comparision (&readings[1] > &readings[0]) : %i\n", compare);
    compare = (&readings[0] == readings); // true
    printf("Pointer comparision (&readings[0] == readings) : %i\n", compare);
    }

    {/*9.7 - Pointers as function parameters*/
    // printf("\n\nSection 9.7 - Pointers as function parameters\n");
    print_section("Section 9.7 - Pointers as function parameters");
    // Declare a lambda function
    auto pass_pointer = [](int* x) {
        *x += 1;
    };
    auto pass_reference = [](int& x) {
        x += 1;
    };
    // Initialization 
    int a = 10;
    double arr[10] {4.3,2.3,1.3};
    // Call a function that expects a pointer (memory address)
    printf("Initial value of a : %i\n", a);
    pass_pointer(&a);
    printf("Result of passing by pointer : %i\n", a);
    pass_reference(a);
    printf("Result of passing by reference : %i\n", a);

    // Either array designation or pointer designmation can be used for 
    // function signatures. The following two definitions are the same
    auto args_array_notation = [](double array[]) {
        std::cout << "First element in array : " << array[0] << endl;
    };
    auto args_array_pointer = [](double* array) {
        std::cout << "First element in array : " << array[0] << endl;
    };
    args_array_notation(arr);
    args_array_pointer(arr);


    // Pointers to constants
    // We must define pointers to constant variables as constant. We cannot change 
    // The data stored in constant variables with pointers
    const int a2 = 10;
    const int* aptr2 = &a2;
    const double arr2[] {1.2, 2.2, 0.32, 4.2, 5.2, 6.2};
    const double* arr2ptr = arr2;
    auto constant_pointer_function= [](const double* arr) {
        printf("First element in constant double array : %f\n", arr[0]);
        printf("First element address in constant double array : %i\n", arr);
    };
    auto constant_pointer_function_int = [](const int* aptr) {
        printf("Addres of constant integer pointer : %i\n", aptr);
        printf("Data at constant array pointer %i\n", *aptr);
    };
    constant_pointer_function(arr2);
    constant_pointer_function_int(aptr2);

    // Constant pointer versus pointer to constant
    int a3 = 10;
    int* const const_aptr2 = &a3; // This is a constant pointer
    // const int* aptr2 = $a2; // This is a pointer to a constant

    // What is the difference?
    const int some_other_variable = 9;
    aptr2 = &some_other_variable; // Valid
    // const_aptr2 = &some_other_variable; // Invalid

    }

    {/*9.8 - Dynamic memory allocation*/
    print_section("9.8 - Dynamic memory allocation");
    // Create new memory
    int* iptr = nullptr;
    iptr = new int; // Request more memory from the operating system
    *iptr = 25; // Define the address at iptr
    delete iptr; // Clean Up
    iptr = nullptr;

    iptr = new int[100]; // New memory for 100 element integer array
    for (int i=0;i<100;i++) {iptr[i] = 1;}
    delete [] iptr; // Clean up
    iptr = nullptr;
    
    /* BAD!! - memroy leak 
    The variable inside the function scope will be deleted. This means iptr will no longer exist,
    but the memory allocated by the function will still exist.
    This causes the program memory to grow by 100*4 bytes each time the function is called
    */
    auto grabMemory = []() {
        const int SIZE = 100;
        // Allocate space for a 100-element array of integers. 
        int *iptr = new int[SIZE];
        // The function ends without deleting the memory!
    };

    
    } // End section 9.8


    return 0;
}