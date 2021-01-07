// Define the use of char datatype
#include <iostream>
#include <stdio.h>
#include <float.h>
#include <limits.h>

using namespace std;

char invalid_char_assignment() {
    // String literals are not the same as char literals
    // string literals store a null terminator \0 at the end
    // Assigning a string to a char variable will not work
    // https://en.cppreference.com/w/cpp/language/try_catch

    string letter3 = "A";
    return letter3[0];
}


int main() {
    char letter = 'a';
    // note - do not define a char literal with double quotes ""
    // this represents a string literal (NOT char)

    cout << "The letter I declared as char is " << letter << endl;

    char letter2 = 66;
    cout << "char datatypes are actually stored as integer data types" << endl;
    std::cout << endl;
    cout << "The char value 66 prints as 'B' " << letter2 << endl;

    // String literals are not the same as char literals
    // string literals store a null terminator \0 at the end
    // Assigning a string to a char variable will not work
    // char letter3;
    // letter3 = "A"; // this will not work
    // https://en.cppreference.com/w/cpp/language/try_catch
    try {
        char res = invalid_char_assignment();
        // We shouldn't get this far...
        printf("Characters: %c \n", res);
    } catch (const std::exception& e) {//reference to the base of a polymorphic object
        std::cout << e.what();
    }
    return 0;
}

