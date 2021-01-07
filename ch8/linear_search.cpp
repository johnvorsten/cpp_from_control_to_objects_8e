#include <iostream>
#include <vector>
#include <string>

using namespace std;

int linear_search_vector(vector<int>& x, const int criteria) {

    int n_elements = x.size();
    int index = 0;
    int position = 0;
    bool found = false;

    while (index < n_elements && !found) {
        if (x[index] == criteria) {
            found = true;
            position = index;
            }
        index++;
    }

    return position;
}

int main() {

    vector<int> x {1,2,3,4,5,6,7,8,9,10};
    int criteria = 7;
    int result = false;
    result = linear_search_vector(x, criteria);

    if (result) {
        std::cout << "Found match at position : " << result << " Value : " << x[result] << endl;
    }
    else {
        std::cout << "No match was found" << endl;
    }

    return 0;
}