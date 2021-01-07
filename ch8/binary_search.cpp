#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int bisect_range(int start, int end) {
    /*Return the middle element between a range. Always round down
    inputs
    -------
    start : (int) beginning of range
    end : (int) end of range
    outputs
    -------
    middle : (int) middle of range*/

    return int( floor((end - start) / 2) + start );
}

int binary_search_vector(vector<int>& x, const int criteria) {

    int n_elements = x.size();
    int first = 0;
    int last = n_elements;
    int middle = 0;
    int position = false;
    bool found = false;

    // Initialize the middle value
    middle = bisect_range(first, last);

    while (!found && middle <= last) {
        /*Middle gets incremented past the last index
        if criteria is not in the vector and criteria is greater than the 
        last element in the vector.

        Last falls below middle when criteria is not in the vector and 
        criteria is less than the smallest value in the vector*/
        
        // Compare elements
        if (x[middle] == criteria) {
            found = true;
            position = middle;
            }

        // Lower half of range
        else if (x[middle] > criteria) {
            // first = first; // Does not change
            last = middle - 1;
            middle = bisect_range(first, last);
        }

        // Upper half of range
        else {
            first = middle + 1;
            middle = bisect_range(first, last);
            // last = last // does not change
        }

    }

    return position;
}

void print_result(int result, vector<int> x) {
    /*Print the outcome of the serarch for debugging
    */
    if (result) {
        std::cout << "Found match at position : " << result << " Value : " << x[result] << endl;
    }
    else {
        std::cout << "No match was found" << endl;
    }

}

int main() {

    /*Case 
    Criteria is in the upper half of the array
    Even number of elements*/
    vector<int> x {1,2,3,4,5,6,7,8,9,10};
    int criteria = 7;
    int result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is in the upper half of the array
    Odd number of elements*/
    x = {1,2,3,4,5,6,7,8,9};
    criteria = 7;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is in the Lower half of the array
    Even number of elements*/    
    x = {1,2,3,4,5,6,7,8,9,10};
    criteria = 4;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is in the Lower half of the array
    Odd number of elements*/
    x = {1,2,3,4,5,6,7,8,9};
    criteria = 4;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is greater than highest element in array
    Even number of elements*/
    x = {1,2,3,4,5,6,7,8,9,10};
    criteria = 11;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is greater than highest element in array
    Odd number of elements*/
    x = {1,2,3,4,5,6,7,8,9};
    criteria = 11;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is Less than Lowest element in array
    Even number of elements*/
    x = {1,2,3,4,5,6,7,8,9,10};
    criteria = 0;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    /*Case 
    Criteria is Less than Lowest element in array
    Odd number of elements*/
    x = {1,2,3,4,5,6,7,8,9};
    criteria = 0;
    result = false;
    result = binary_search_vector(x, criteria);
    print_result(result, x);

    return 0;
}