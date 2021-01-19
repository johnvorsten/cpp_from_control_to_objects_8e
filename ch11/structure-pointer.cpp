#include <iostream>
#include <string>
#include <cstdio>
#include <random>
#include <utility>

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

    /*Always pass structures by reference to functions*/
    Parent parent {132433, 2021, 1, 10};
    Child child {string("A Child structure"), parent};
    print_child(child);
    child.print_date();

    /*Pointer to structures*/
    Child* childp = &child;
    std::cout << (*childp).description << endl;
    std::cout << childp->description << endl;
    // Dereference a pointer
    (*childp).print_date();
    // Structure pointer operator
    childp->print_date();
    // print_child(childp); // Error!
    print_child(*childp);

    /*Dynamic allocation of structures*/
    std::default_random_engine engine;
    std::uniform_int_distribution<int> distribution(2,6);
    int n_children = distribution(engine);
    Child *childp2 = nullptr;
    childp2 = new Child[n_children];
    for (int i=0; i<n_children; i++) {
        print_child(childp2[i]);
    }


    return 0;
}