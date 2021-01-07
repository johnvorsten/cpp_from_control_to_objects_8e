#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

// Definitions
vector<float*> array_select_sort(vector<float>& arr) {
    /*Sort an array and return a pointer list to the array
    representing the values in ascending order*/

    // Initialization
    vector<float*> arr_ptr(arr.size()); // I dont care about reallocation here
    for (int i=0; i < arr.size(); i++) {
        arr_ptr[i] = &(arr[i]); // Initialize array of pointers
    }
    auto size = arr.size();
    int min_index = 0;
    auto min_value = *(arr_ptr[0]);
    auto min_pointer = arr_ptr[0];

    // Loop through each element in array
    for (int i=0; i<size; i++) {
        min_index = i;
        min_value = *(arr_ptr[i]);
        min_pointer = arr_ptr[i];

        // Loop through each element in sub-array
        for (int j=(i+1); j < size; j++) {
            if (*(arr_ptr[j]) < min_value) {
                min_value = *(arr_ptr[j]);
                min_pointer = arr_ptr[j];
                min_index = j;
            }
        }

        // Insert the pointer to the minimum value in passed array
        arr_ptr[min_index] = arr_ptr[i];
        arr_ptr[i] = min_pointer;
        
    }

    return arr_ptr;
}


void show_unsorted_vector(vector<float>& arr) {

    std::cout << "\n\nDisplaying un-sorted array values\n";
    for (float x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nEnd\n";

}


void show_sorted_vector(vector<float*>& arr) {

    std::cout << "\n\nDisplaying sorted array values\n";
    for (float* ptr : arr) {
        std::cout << *ptr << " ";
    }
    std::cout << "\nEnd\n";

}



int main () {

    // Initial Values
    // obtain a seed from the system clock:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(1,100);
    auto get_random = std::bind ( distribution, generator);
    vector<float> arr(10); // Initialize large enough to not get reallocated

    for (float &x : arr) {
        x = get_random();
    }

    // Sort initial donations
    auto arr_ptr = array_select_sort(arr);

    // Display donations
    show_unsorted_vector(arr);

    // Display sorted donations
    show_sorted_vector(arr_ptr);

    return 0;
}


