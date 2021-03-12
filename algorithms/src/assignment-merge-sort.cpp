/*Write a  function that merges two sorted array-based lists 
into one sorted array-based list.  The function takes two arrays 
as parameters, each holding a sorted list of integers, merges 
them into  a single sorted list, and returns the result.  Note 
that this function performs the merge part of the merge sort algorithm.

The function should have a linear time complexity i.e. O(N), 
where N is the sum of the length of the two input lists it 
merges. Note: functions that are not linear will not get any credit.

Deliverables:

A copy of your merge function code in a text file.
A copy of a test program to test your function. Be sure to 
    test all cases e.g. two empty lists, one empty only, 
    lists with 1 element each, lists with multiple elements.
Screenshots of your test runs showing your function meets specifications.
*/

#include <vector>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <exception>
// #include "./algorithms/matplotlib-cpp-master/matplotlibcpp.h"
// #include "matplotlibcpp.h"

using namespace std;
// namespace plt = matplotlibcpp;

/*Function accepting arrays explicitly*/
template <typename T>
void merge_into(T* arr1, int left, int middle, int right, T* res) {
    /*Merge elemetns from arr1 into a resulting array
    inputs
    -------
    output
    -------
    */

    // Create a temporary array storing values until they are sorted
    int size1 = 0;
    int size2 = 0;
    T temp[];

}

template <typename T>
T* merge_arrays(T* arr1, int size1, T* arr2, int size2) {
    /*According to the specification, this function should accept
    two arrays and return an array
    Remember to call delete[] on the returned array
    inputs
    ------
    outputs
    -------*/

    // Special cases
    if (size1 == 1 || size2 == 1) {
        // TODO - size 1
    }
    else if (size1 == 0 || size2 == 1) {
        // TODO - empty
    }

    // Create new storage location for values
    int* res = nullptr;
    int new_size = size1 + size2;
    res = new T[new_size];

    // Merge arrays into one
    int i = 0, j = 0, insert = 0;
    // While we have not finished iterating through elements in each list
    while (insert < new_size) {

        if (arr1[i] < arr2[j] && i < size1) {
            // Insert element from arr1 to result
            res[insert] = arr1[i];
            i++;
            insert++;
        }
        else {
            // Insert element from arr2 to result
            res[insert] = arr2[j];
            j++;
            insert++;
        }
    }

    return res;
}

template <typename T>
bool test_array_equal(T* arr1, int size1, T* arr2, int size2) {

    if (size1 != size2) {
        return false;
    }

    for (int i=0; i<size1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool test_array_equal(T* arr1, int size1, std::initializer_list<T> l, int size2) {
    vector<T> arr2(l);

    if (size1 != size2) {
        return false;
    }

    for (int i=0; i<size1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
string array_to_string(T* arr1, int size1) {
    string res;
    for (int i=0; i<size1; i++) {
        res += to_string(arr1[i]);
        res += (" ");
    }

    return res;
}

void test_merge_arrays() {
    std::cout << "Starting: " << __func__ << endl;

    {// Create two arrays to sort
    int a1[5] {1,2,3,4,5};
    int a2[5] {10,11,12,13,14};
    int test[10] {1,2,3,4,5,10,11,12,13,14};
    auto res = merge_arrays(a1, 5, a2, 5);
    if (!test_array_equal(res, 10, test, 10) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 10);
        msg += " Versus ";
        msg += array_to_string(test, 10);
        throw std::logic_error(msg);
    }
    }

    {// Different size arrays
    int a1[5] {1,2,3,4,5};
    int a2[6] {10,11,12,13,14,15};
    int test[11] {1,2,3,4,5,10,11,12,13,14,15};
    auto res = merge_arrays(a1, 5, a2, 6);
    if (!test_array_equal(res, 10, test, 10) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 10);
        msg += " Versus ";
        msg += array_to_string(test, 10);
        throw std::logic_error(msg);
    }
    }

    {// a1 is smaller than a2
    int a1[3] {3,2,1};
    int a2[3] {0,-1,-2};
    int test[6] {-2,-1,0,1,2,3};
    auto res = merge_arrays(a1, 3, a2, 3);
    if (!test_array_equal(res, 6, test, 6) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 10);
        msg += " Versus ";
        msg += array_to_string(test, 10);
        throw std::logic_error(msg);
    }
    }
    
    {// Mixed arrays
    int a1[4] {3,5,1,0};
    int a2[4] {4,2,6,9};
    int test[8] {0,1,2,3,4,5,6,9};
    auto res = merge_arrays(a1, 4, a2, 4);
    if (!test_array_equal(res, 8, test, 8) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 10);
        msg += " Versus ";
        msg += array_to_string(test, 10);
        throw std::logic_error(msg);
    }
    }

    std::cout << "SUCCESS: " << __func__ << endl;
}

template <typename T>
void print_array(T* arr1, int size1) {
    for (int i=0; i<size1; i++) {
        std::cout << arr1[i] << " ";
    }
}



int main () {

    try {
        test_merge_arrays();
    }
    catch (std::logic_error& e) {
        std::cout << e.what() << endl;
    }
    


    /*
    {
    // Simple example
    plt::plot({1,3,2,4});
    plt::show();
    }

    {
    // Complex example
    // Prepare data.
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(i) = i*i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
    }

    // Set the size of output image to 1200x780 pixels
    plt::figure_size(1200, 780);
    // Plot line from given x and y data. Color is selected automatically.
    plt::plot(x, y);
    // Plot a red dashed line from given x and y data.
    plt::plot(x, w,"r--");
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot("log(x)", x, z);
    // Set x-axis to interval [0,1000000]
    plt::xlim(0, 1000*1000);
    // Add graph title
    plt::title("Sample figure");
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./basic.png");
    }



    {
    // Prepare data.
    int n = 5000; // number of data points
    vector<double> x(n),y(n);
    for(int i=0; i<n; ++i) {
        double t = 2*M_PI*i/n;
        x.at(i) = 16*sin(t)*sin(t)*sin(t);
        y.at(i) = 13*cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t);
    }

    // plot() takes an arbitrary number of (x,y,format)-triples.
    // x must be iterable (that is, anything providing begin(x) and end(x)),
    // y must either be callable (providing operator() const) or iterable.
    plt::plot(x, y, "r-", x, [](double d) { return 12.5+abs(sin(d)); }, "k-");


    // show plots
    plt::show();
    }
    */

    return 0;
}