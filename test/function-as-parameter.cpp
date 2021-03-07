#include <iostream>
#include <string>

using namespace std;

void callback(std::string str) {
    std::cout << "Printing: " << str << std::endl;
}

template <typename f_callback>
void caller(std::string str1, std::string str2, f_callback&& callback) {
    std::cout << "Priming function with: " << str1 << std::endl;
    callback(str2);
}

class Base {

    public:
    template <typename Callback>
    void caller(std::string str1, Callback&& callback) {
        /* Reduce boilerplate?? */
        this->callback(str1);
    }

};

class Derived : public Base {

    public:
    virtual void func1(std::string a) {
        std::cout << "Doing something one way..." << std::endl;
        std::cout << a;
    }

    virtual void func2(std::string b) {
        std::cout << "Doing it another way..." << std::endl;
        std::cout << b;
    }

};

int main () {

    // Functions only..
    caller("My Primter", "Call me...", callback);

    // Base and derived classes..
    Base base;
    Derived derived;
    derived.caller("Call me...", derived.func1);
    derived.caller("Call me...", derived.func2);

    return 0;
}