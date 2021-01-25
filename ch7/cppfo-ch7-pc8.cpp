#include <iostream>
#include <random>
#include <functional>
#include <cassert>
#include <stdexcept>
#include <string>

using namespace std;

// Function declarations
template <typename T, std::size_t rows, std::size_t cols>
bool is_lo_shu_magic_square(T (&array)[rows][cols]) {
    /*3 rows 3 columns
    Properties
    The sum of each row, each column, and each diagonal all add 
    up to the same number
    */

    int n_checks = (rows + cols + 2);
    T sum[n_checks] = {};

    std::cout << __func__ << std::endl;

    // Rows
    for (int i=0; i<rows; i++) {
        
        for (int j=0; j<cols; j++) {
            sum[i] += array[i][j]; // Store all row sums
            sum[i + rows] += array[j][i]; // Store all column sums
        }

        // Store diagonal sums
        sum[n_checks - 1 - 1] += array[i][i]; // Second to last element
        sum[n_checks - 1] += array[i][rows - i - 1]; // Last element

    }

    // Make sure all values in sum are equal
    for (int i; i<(n_checks - 1); i++) {
        if (!(sum[i] == sum[i + 1])) {
            string ex = "This is not a lo shu magic square";
            throw std::invalid_argument(ex);
        }
    }

    return true; // If we make it this far
}



int main () {

    // Create a couple of arrays
    int test1[3][3] = {{4,9,2}, {3,5,7}, {8,1,6}}; // True
    int test2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}; // False

    try {
        if (is_lo_shu_magic_square(test1))
            std::cout << "test2 is a lo shu magic square" << endl;
    }
    catch (std::invalid_argument& e) {
        std::cout << "test1 is not a lo shu magic square" << endl;
    }

    // This will cause the program to exit!!
    try  { 
        if (is_lo_shu_magic_square(test2))
            std::cout << "test2 is a lo shu magic square" << endl;
    }
    catch (std::invalid_argument& e) {
        std::cout << "test2 is not a lo shu magic square" << endl;
    }

    return 0;
}