#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
void f(std::initializer_list<T> wtf) {
    for (auto& wt: wtf) {
        std::cout << wt << endl;
    }
}

template <typename T>
void f2(T& first, std::initializer_list<T> wtf) {
    for (auto& wt: wtf) {
        std::cout << first << wt << endl;
    }
}

template <typename T, typename U>
void f3(T& first, std::initializer_list<U> wtf) {
    for (auto& wt: wtf) {
        std::cout << first << wt << endl;
    }
}

template <typename T>
void f4(T& first, std::initializer_list<const T*> wtf) {
    for (auto& wt: wtf) {
        std::cout << first << wt << endl;
    }
}

template <typename T>
void f5(T& first, std::initializer_list<T> wtf) {
    for (auto& wt: wtf) {
        std::cout << first << wt << endl;
    }
}

int main () {

    f({"A character sequence"});
    f({"A","B","C"});
    // f2("a", {"A character sequence"}); // Error
    f3("a", {"A character sequence"}); // OK
    char A = 'A';
    f4(A, {"A String Literal"}); // OK
    f5(A, {'B','C','D'}); // OK

    return 0;
}