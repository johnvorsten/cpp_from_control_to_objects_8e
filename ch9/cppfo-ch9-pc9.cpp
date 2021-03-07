/*In statistics, when a set of values is sorted in ascending or descending order, 
its median is the middle value. If the set contains an even number of values, 
the median is the mean, or average, of the two middle values. Write a 
function that accepts as arguments the following: 
A) An array of integers 
B) An integer that indicates the number of elements in the array 
The function should determine the median of the array. 
This value should be returned as a double . (Assume the values in the array are already sorted.) 
Demonstrate your pointer prowess by using pointer notation 
instead of array notation in this function.*/

#include <iostream>

using namespace std;

// Function definition
template <typename T>
double median_sorted_array(T* arr, int size) {
    // Retrun the median (middle) element of the array
    int middle_index = 0;

    // Calculate middle index
    if (size <= 1)
        return 0;
    middle_index = size / 2;

    T val = *(arr + middle_index); // Dereference based on address
    // Cast middle element to a double
    return static_cast<double>(val);
} 

int main () {

    int arr[] {1, 2, 3, 4, 5, 10, 22, 413, 6611, 24545, 10000000};
    auto val = median_sorted_array(arr, sizeof(arr) / sizeof(int));
    std::cout << "The median value of {";
    for (auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "} is " << val << std::endl;


    return 0;
}