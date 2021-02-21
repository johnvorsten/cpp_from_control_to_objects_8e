/*Chapter 13 programming challenge 2

Employee Class Write a class named Employee that has the following member variables:
• name—a string that holds the employee’s name • idNumber—a n int variable that 
holds the employee’s ID number • department—a string that holds the name of the 
department where the employee works

• position—a string that holds the employee’s job title The class should have 
the following constructors:
• A constructor that accepts the following values as arguments and assigns them 
to the appropriate member variables: employee’s name, employee’s ID number, 
depart? ment, and position.
• A constructor that accepts the following values as arguments and assigns 
them to the appropriate member variables: employee’s name and ID number. The 
department and position fields should be assigned an empty string
• A default constructor that assigns empty strings ("") to the name, 
department, and position member variables, and 0 to the idNumber member variable.

Write appropriate mutator functions that store values in these member 
variables and accessor functions that return the values in these member 
variables. Once you have written the class, write a separate program that 
creates three Employee objects to hold the following data

Name
Susan Meyers Mark Jones Joy Rogers
ID Number
47899 39119 81774
Department
Accounting IT
Manufacturing Position
Vice President Programmer Engineer

The program should store this data in the three objects and then display 
the data for each employee on the screen.
*/

#include <iostream>
#include "cppfo-ch13-pc2.hpp"

using namespace std;


int main () {

    Employee employees[3]{
        {"Susan Meyers",47899,"Accounting","Vice President"},
        {"Mark Jones",39119,"IT","Programmer"},
        {"Joy Rogers",81774,"Manufacturing","Engineer"}};

    std::cout << "Look, Ma! I made a class!" << endl;
    for (auto& e : employees) {
        std::cout << e;
    }

    return 0;
}