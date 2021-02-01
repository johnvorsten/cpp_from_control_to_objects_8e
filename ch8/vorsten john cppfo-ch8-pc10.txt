#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class declarations

// Data declarations

// Function declarations
template <typename T>
void select_sort(T&, int);

template <typename T>
void bubble_sort(T&, int);

template <typename T>
void display_array(T&, int);


int main () {
    vector<int> x1 = {2,1,4,3,5,6,8,7};
    vector<int> x2;
    std::copy(x1.begin(), x1.end(), std::back_inserter(x2));

    // Display and sort arrays
    std::cout << "Displaying array x1" << endl;
    display_array(x1, x1.size());
    bubble_sort(x1, x1.size());

    std::cout << "Displaying array x2" << endl;
    display_array(x2, x2.size());
    select_sort(x2, x2.size());

    return 0;
}

template <typename T>
void display_array(T& array, int size) {
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << endl;
}

template <typename T>
void select_sort(T& arr, int size) {
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

        // Display the array after each pass
        display_array(arr, arr.size());
        
    }

}

template <typename T>
void bubble_sort(T& array, int size) {
    bool swap; int temp;

    do {
        // Display the contents of array after each pass
        display_array(array, array.size());

        swap = false;
        for (int count = 0; count < (size - 1); count++) {
            if (array[count] > array[count + 1]) {
                temp = array[count];
                array[count] = array[count + 1]; 
                array[count + 1] = temp; 
                swap = true;
            }
        } 
    } while (swap);
}


