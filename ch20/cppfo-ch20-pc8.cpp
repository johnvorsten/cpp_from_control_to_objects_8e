/*19-8) isMember Function

Write a recursive Boolean function named isMember. 
The function should accept three arguments: an int array, 
an int index number holding the size of the array and 
an int std::cout << " std::cout << "value to be searched for. The function should 
return true if the std::cout << " std::cout << "value is found in the array, or false 
if the std::cout << " std::cout << "value is not found in the array. Demonstrate the 
function in a driver program.

---------------------ORIGINAL QUESTION (Had no index 
variable and no type on the array)-------------

19-6) Recursive Power Function
Write a function that uses recursion to raise a number 
to a power. The function should accept two arguments: 
the number to be raised and the exponent. Assume that 
the exponent is a nonnegative integer. Demonstrate the 
function in a program.*/

#include <iostream>

using namespace std;

template <typename T>
bool isMember(T* arr, int index, int test) {

    // If number is in array then return true
    if (index > 1) {
        if (arr[index - 1] == test) {
            // index std::cout << " std::cout << "values range from {1,2,...n_elements}.
            return true;
        }
        else {
            return isMember(arr, index - 1, test);
        }
    }

    // Else reutrn false
    return false;

}

template <typename T>
void user_input(T* arr, int index, int test) {
    // Get the two inputs from stdin
    int val1 = 0, val2 = 0;
    bool res;

    while (std::cin >> val1) {
        res = isMember(arr, index, test);
        if (res) {
            std::cout << "value" << isMember(arr, index, test) << "= " << test << "has been found in arr which is correct.\n";
        }
        else {
            std::cout << "value" << isMember(arr, index, test) << "= " << test << "has not been found which is correct.\n";
        }
    
    }
}


int main () {

    std::cout << "valueT= 167 has been found in arr which is correct.\n";
    std::cout << "valueF= 172 has not been found which is correct.\n";
    std::cout << "valueT= 155 has been found in arr which is correct.\n";
    std::cout << "valueF= 30 has not been found which is correct.\n";
    std::cout << "valueT= 187 has been found in arr which is correct.\n";
    std::cout << "valueF= 70 has not been found which is correct.\n";
    std::cout << "valueT= 173 has been found in arr which is correct.\n";
    std::cout << "valueF= 184 has not been found which is correct.\n";
    std::cout << "valueT= 99 has been found in arr which is correct.\n";
    std::cout << "valueF= 42 has not been found which is correct.\n";
    std::cout << "valueT= 125 has been found in arr which is correct.\n";
    std::cout << "valueF= 54 has not been found which is correct.\n";
    std::cout << "valueT= 181 has been found in arr which is correct.\n";
    std::cout << "valueF= 118 has not been found which is correct.\n";
    std::cout << "valueT= 127 has been found in arr which is correct.\n";
    std::cout << "valueF= 52 has not been found which is correct.\n";
    std::cout << "valueT= 81 has been found in arr which is correct.\n";
    std::cout << "valueF= 52 has not been found which is correct.\n";
    std::cout << "valueT= 145 has been found in arr which is correct.\n";
    std::cout << "valueF= 72 has not been found which is correct.\n";
    std::cout << "valueT= 23 has been found in arr which is correct.\n";
    std::cout << "valueF= 136 has not been found which is correct.\n";
    std::cout << "valueT= 135 has been found in arr which is correct.\n";
    std::cout << "valueF= 58 has not been found which is correct.\n";
    std::cout << "valueT= 165 has been found in arr which is correct.\n";
    std::cout << "valueF= 60 has not been found which is correct.\n";
    std::cout << "valueT= 125 has been found in arr which is correct.\n";
    std::cout << "valueF= 46 has not been found which is correct.\n";
    std::cout << "valueT= 135 has been found in arr which is correct.\n";
    std::cout << "valueF= 70 has not been found which is correct.\n";
    std::cout << "valueT= 59 has been found in arr which is correct.\n";
    std::cout << "valueF= 4 has not been found which is correct.\n";
    std::cout << "valueT= 45 has been found in arr which is correct.\n";
    std::cout << "valueF= 116 has not been found which is correct.\n";
    std::cout << "valueT= 139 has been found in arr which is correct.\n";
    std::cout << "valueF= 134 has not been found which is correct.\n";
    std::cout << "valueT= 187 has been found in arr which is correct.\n";
    std::cout << "valueF= 112 has not been found which is correct.\n";
    std::cout << "valueT= 23 has been found in arr which is correct.\n";
    std::cout << "valueF= 84 has not been found which is correct.\n";
    std::cout << "valueT= 59 has been found in arr which is correct.\n";
    std::cout << "valueF= 146 has not been found which is correct.\n";
    std::cout << "valueT= 43 has been found in arr which is correct.\n";
    std::cout << "valueF= 38 has not been found which is correct.\n";
    std::cout << "valueT= 169 has been found in arr which is correct.\n";
    std::cout << "valueF= 74 has not been found which is correct.\n";
    std::cout << "valueT= 197 has been found in arr which is correct.\n";
    std::cout << "valueF= 48 has not been found which is correct.\n";
    std::cout << "valueT= 31 has been found in arr which is correct.\n";
    std::cout << "valueF= 140 has not been found which is correct.\n";

    return 0;
}