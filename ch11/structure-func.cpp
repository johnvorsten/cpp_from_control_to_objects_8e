#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// Local declarations
struct Parent {
    int id;
    int year;
    int month;
    int day;
};

struct Child {
    string description;
    Parent parent;

    void print_date() {
        std::cout << parent.year << "-" << parent.month << "-" << parent.day << endl;
    }
};

void print_child(const Child& x) {
    /*Always pass by reference*/
    printf("child<%s, %i, %i, %i, %i\n", x.description.c_str(), 
                x.parent.id, 
                x.parent.year, 
                x.parent.month, 
                x.parent.day);
}


int main () {

    Parent parent {132433, 2021, 1, 10};
    Child child {string("A Child structure"), parent};
    print_child(child);
    child.print_date();

    return 0;
}