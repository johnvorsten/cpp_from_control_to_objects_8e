#include <iostream>
#include <vector>


/*How to pass arrays from functions

This will accept an array as an argument, and return the array pointer
int* function(int some_array[]) {
    // do stuff
   return some_array; 
}


#################

NOT allowed... (see later)
int* function(int some_array[]) {
    // do stuff
    // sizeof(some_array) - wont work
    return some_array;
}

// Later...
int some_array[20];
some_array = function(some_array); // NO - the function actually returns a pointer
// And the array data is operated on directly anyway...

// YES - The array data is operated on directly
function(some_array);

#####################

Pass array size to function
int* function(int some_array[], int sz) {
    
    for (int i=0; i<sz; i++) {
        // do stuff
    }

}
*/

using namespace std;

int* fish(int barrel[], size_t sz) {
    /*This is a bad way to operate on an array, and in general
    vector should be used instead of array
    This is because vector is an object which handles its own 
    memory allocation, and deletes itsself when it goes out of scope
    
    Also, I cannot pass an array to a function. The function will receive
    the pointer to an array, and the variable decays to a pointer before
    the function gets it. This means I cannot use things like sizeof() on 
    the varaible.*/

    for (int i=0; i < sz; i++) {
        std::cout << "Enter the number of fish for the " << i << "th fisherman : " << endl;
        std::cin >> barrel[i];
        std::cout << endl;
    }
    std::cout << "Thank you, you are done";

    return barrel;
}

void better_fish(std::vector<int>& barrel) {

    int n_fish;
    for (int i=0; i < barrel.size(); i++) {
        std::cout << "Enter the number of fish for the " << i << "th fisherman : ";
        std::cin >> n_fish;
        barrel[i] = n_fish;
        std::cout << endl;
    }
    std::cout << "Thank you, you are done" << endl;
}


int main () {
    // Initialize an array and find its total size
    int int_array[13];
    std::cout << "The array element is of type " << typeid(int_array[0]).name() << endl;
    std::cout << "The " << typeid(int_array[0]).name() << " data has a size of " << sizeof(int_array[0]) << endl;
    cout << "The array takes " << sizeof(int_array) << " bytes" << endl;
    std::cout << "The array has " << sizeof(int_array) / sizeof(int_array[0]) << " elements" << endl;

    int i = 0;
    for (int x : int_array) {
        cout << i << "th element in vector is " << x << endl;
        i++;
    }

    int empNums[100];
    float payRates[25];
    long miles[14];
    char cityName[26];
    double lightYears[1000];

    // Fisherman
    int barrel[2];
    fish(barrel, (sizeof(barrel) / sizeof(barrel[0])));
    std::cout << "Caught fish : ";
    for (int x : barrel) {
        std::cout << x << " ";
    }
    std::cout << endl;

    // Better fisherman
    vector<int> barrel2(5);
    better_fish(barrel2);
    std::cout << "Caught fish : ";
    for (int x : barrel2) {
        std::cout << x << " ";
    }
    std::cout << endl;

    // Initializing arrays
    const int ARRAY_SIZE = 4;
    std::string bricks[ARRAY_SIZE] = {"Red","Green","Blue","Yellow"};
    int init_array[5] {1,2,3}; // Partially initialized array
    int auto_initialize[] {1,2,3}; // Automatically sized to fit initialization list

    // Range based for loop
    std::string song[] {"99","bottles","of","beer","on","the","wall"};
    for (auto x : song) {
        std::cout << x << " ";
    }

    return 0;
}