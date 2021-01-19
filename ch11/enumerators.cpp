#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// Named enumerated data type
enum enumeration {enum1, enum2, enum3, enum4, enum5};
// Anonymous enumeration
enum {a,b,c,d,e,f,g};
// Enumeration with default values
enum direction {East=11, West=22, North=33, South=44};

void marco_polo(direction& dir) {

    switch (dir) {
        case East:
            std::cout << "You are going East" << endl;
            std::cout << "You are getting colder..." << endl;
            break;
        case West:
            std::cout << "You are going West" << endl;
            std::cout << "You are getting colder..." << endl;
            break;
        case North:
            std::cout << "You are going North" << endl;
            std::cout << "You are getting Hotter!!!" << endl;
            break;
        case South:
            std::cout << "You are going South" << endl;
            std::cout << "You are getting colder..." << endl;
            break;
    };

}

int main () {

    enumeration a; // Loop counter
    // Step through contents of an array with enumerated data types
    for (int i=enum1; i<enum5; i++) {
        std::cout << "Looping through enumerator" << endl;
    }

    // Enumerations can only hold one of their enumerated values
    direction dir;
    dir = South; // OK
    dir = static_cast<direction>(11); // OK
    dir = static_cast<direction>(13); // OK...
    // dir = 22; // Error
    // dir = 13; // Error

    std::cout << "Value of enumerated data type : " << dir << endl;
    dir = North;
    std::cout << "Changing enumerated data value to : " << dir << endl;

    // Play a game
    vector<int> b = {11,22,33,44};
    for (direction dir : {East, West, North, South}) {
        marco_polo(dir);
    }

    return 0;
}