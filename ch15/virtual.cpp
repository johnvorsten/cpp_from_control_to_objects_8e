#include <iostream>

using namespace std;

class Base {
    public:
        virtual void func() {
            std::cout << "Base" << endl;
        }
};

class Derived : public Base {
    public:
    void func() {
        std::cout << "Derived" << endl;
    }
};

int main () {
    Base base;
    Derived derived;

    // Virtual function call through reference
    Base& br = base; // The type is Base&
    Base& dr = derived; // The type is Base&
    br.func(); // "Base"
    dr.func(); // "Derived"

    // Virtual function call through pointer
    Base* bp = &base;
    Base* dp = &derived;
    bp->func(); // "Base"
    dp->func(); // "Derived"

    // Non-virtual function call
    base.func(); // "Base"
    derived.func(); // "Derived"
    base.Base::func(); // "Base"
    derived.Base::func(); // "Base"

    return 0;
}