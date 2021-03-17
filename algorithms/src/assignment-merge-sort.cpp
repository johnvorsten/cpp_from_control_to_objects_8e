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
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <map>
#include <set>

using namespace std;


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
    T* res = nullptr;
    int new_size = size1 + size2;
    res = new T[new_size];

    // Merge arrays into one
    int i = 0, j = 0, insert = 0;
    // While we have not finished comparing elements
    while (i < size1 && j < size2) {

        if (arr1[i] < arr2[j]) {
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

    // Copy remaining elements from left array if there are any
    while (i < size1) {
        res[insert] = arr1[i];
        insert++;
        i++;
    }

    // Copy remaining elements from right array if there are any
    while (j < size2) {
        res[insert] = arr2[j];
        insert++;
        j++;
    }

    return res;
}


