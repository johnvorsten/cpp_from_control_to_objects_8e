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
#define WITHOUT_NUMPY

// CPP Imports
#include <vector>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <exception>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <map>
#include <set>

// Third party imports
// #include <boost/lambda/lambda.hpp>

// Local imports
#include "assignment-merge-sort.cpp"
#include "assignment-merge-sort-test.cpp"
#include "boost-demo.cpp"

using namespace std;


// template <typename T>



int main () {

    // Prove simple operation of merging arrays
    try {
        test_merge_arrays();
    }
    catch (std::logic_error& e) {
        std::cout << e.what() << endl;
    }

    // Prove that the execution time is linear
    // PS this seems really fast... I wonder how fast this is in python lol
    test_merge_arrays_execution_time();

    return 0;
}