/*10.18: Phone Number List
Write a program that has an array of at least 50 string objects that hold 
people’s names and phone numbers. The program then reads lines of text 
from a file named phonebook  into the array.

The program should ask the user to enter a name or partial name to search 
for in the array. All entries in the array that match the string entered 
should be displayed-- thus there may be more than one entry displayed.

Prompts And Output Labels. The program prints the message "Enter a 
name or partial name to search for: " and then after the user enters 
a some input and hits return, the program skips a line, and prints 
the heading: "Here are the results of the search:", followed by each 
matched string in the array on a line by itself.

Input Validation. None. */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

vector<string> read_names(string filename) {
    vector<string> names;
    string line;
    
    std::ifstream myfile(filename);

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            names.push_back(line);
        }
    }
    else {
        throw std::logic_error("Could not open File");
    }

    return names;
}

string user_input() {
    string name;

    std::cout << "Enter a name or partial name to search for: " << endl;
    std::cin >> name;

    return name;
}

void array_string_search(vector<string> names, string substring) {
    vector<string> found;
    // For each name in names do a substring search
    for (auto& name : names) {
        if (!(std::string::npos == name.find(substring))) {
            found.push_back(name);
        }
    }

    // Print to output all names that are found
    std::cout << "Here are the results of the search: " << endl;
    for (auto& name : found) {
        std::cout << name << endl;
    }
}


int main () {

    string filename = "phonebook";
    auto names = read_names(filename);
    auto substring = user_input();
    array_string_search(names, substring);

    return 0;
}