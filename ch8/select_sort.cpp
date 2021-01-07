#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;

void select_sort(float* arr, int size) {
    /*Sort float array in place*/
    int min_index;
    auto min_value = arr[0];

    // Loop through each element in array
    for (int i=0; i<size; i++) {
        min_index = i;
        min_value = arr[i];

        // Loop through each element in sub-array
        for (int j=(i+1); j < size; j++) {
            if (arr[j] < min_value) {
                min_value = arr[j];
                min_index = j;
            }
        }

        // Swap the value at the current index with the value at the
        // That represents the minimum value in the scanned array
        arr[min_index] = arr[i];
        arr[i] = min_value;
        
    }

}


void select_sort_test() {

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(1,100);
    auto get_random = std::bind ( distribution, generator);
    float arr[100];

    for (float &x : arr) {
        x = get_random();
    }

    select_sort(arr, (sizeof(arr) / sizeof(arr[0])));

    std::cout << "Printing sorted array\n";
    for (float x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nEnd\n";

}

int main () {

    select_sort_test();

    return 0;
}