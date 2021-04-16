/*
1.
    (10 %) Write a driver program to test the class with the following data:
        (520, "3100 Main St, Houston TX");
        (37, "2200 Hayes Rd, Austin TX");
        (226, "1775 West Airport St, San Antonio TX");
        (273, "3322 Walnut Bend, Houston TX");
        (491, "5778 Alabama, Waco TX");
        (94, "3333 New St, Paris TX");

Make sure to test the find function for exiting and non-existing data

2. (25%) Modify the key type in the class definition to a string, e.g. phone number or e-mail address. Use the string hash function discussed in class or search online for alternative functions that work on strings.

3. (40%) Modify the collision strategy of class HashMap to do separate chaining instead of linear probing.  Be sure to modify the display function so that items in the bucket chains are also displayed in a pre-defined order for debugging purpose.

4. (25%)  Add a delete function to class HashMap.  
*/

#include <iostream>
#include "hashMap.hpp"
#include <tuple>
#include <vector>

using namespace std;

void test_hash_map() {

    vector<tuple<int, string>> test_vals {
        {520, "3100 Main St, Houston TX"},
        {37, "2200 Hayes Rd, Austin TX"},
        {226, "1775 West Airport St, San Antonio TX"},
        {273, "3322 Walnut Bend, Houston TX"},
        {491, "5778 Alabama, Waco TX"},
        {94, "3333 New St, Paris TX"},
        };


    HashMap hashMap;
    for (auto& val : test_vals) {
        hashMap.insert(std::get<0>(val), std::get<1>(val));
    }

}




int main () {




    return 0;
}






