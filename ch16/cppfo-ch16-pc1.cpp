#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


template <typename T>
T maximum(T& a, T& b) {
    if (a > b) {
        return a;
    }

    else return b;
}


template <typename T>
T minimum(T& a, T& b) {
    if (a < b) {
        return a;
    }

    return b;
}


class UserInput {

    public:
    UserInput(){}

    template <typename T>
    struct result {
        result(T aval1, T aval2) {
            val1 = aval1;
            val2 = aval2;
        }

        T val1;
        T val2;

    };


    void user_input() {
        auto choice = user_type_choice_input();
        
        switch(choice) {
            case 1: {
                auto res = val_input(0);
                auto min_max_choice = user_min_max_input();
                display_min_max(min_max_choice, res);
                break;
            }

            case 2: {
                auto res = val_input(0.0);
                auto min_max_choice = user_min_max_input();
                display_min_max(min_max_choice, res);
                break;
            }

            case 3: {
                auto res = val_input("something");
                auto min_max_choice = user_min_max_input();
                display_min_max(min_max_choice, res);
                break;
            }
        }

    }


    private:
    int user_type_choice_input() {

        string msg = 
            "Enter\n"
            "1)To compare integers\n"
            "2)To compare doubles\n"
            "3)To compare strings:";
        int choice;

        std::cout << msg;
        std::cin >> choice;

        return choice;
    }


    int user_min_max_input() {

        string msg_min_max = 
            "Enter\n"
            "1)To find minimum\n"
            "2)To find maximum:";
        int min_max_choice;
        std::cout << msg_min_max;
        std::cin >> min_max_choice;

        return min_max_choice;
    }


    template <typename T>
    void display_min_max(int min_max_choice, result<T> res) {

        switch (min_max_choice) {
            case 1: {
                auto min = minimum(res.val1, res.val2);
                std::cout << min << "\n";
                break;
            }

            case 2: {
                auto max = maximum(res.val1, res.val2);
                std::cout << max << "\n";
                break;
            }

        }

    }


    result<int> val_input(int a) {
        int val1;
        int val2;

        std::cout << "Enter first integer:";
        std::cin >> val1;
        // std::cout << "\n";
        std::cout << "Enter second integer:";
        std::cin >> val2;
        // std::cout << "\n";
        return result<int>(val1, val2);
    }

    result<double> val_input(double a) {
        double val1;
        double val2;

        std::cout << "Enter first double:";
        std::cin >> val1;
        // std::cout << "\n";
        std::cout << "Enter second double:";
        std::cin >> val2;
        // std::cout << "\n";
        return result<double>(val1, val2);
    }

    result<string> val_input(string a) {
        string val1;
        string val2;

        std::cout << "Enter first string:";
        std::cin >> val1;
        // std::cout << "\n";
        std::cout << "Enter second string:";
        std::cin >> val2;
        // std::cout << "\n";
        return result<string>(val1, val2);
    }

};


// template <typename T>
// void test_typeid() {
//     std::cout << *typeid(T).name() << "\n";
//     std::cout << *typeid(int).name() << "\n";
//     std::cout << *typeid(double).name() << "\n";
//     std::cout << *typeid(string).name() << "\n";

//     std::cout << (*typeid(string).name() == 'N'); //St7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE);
//     std::cout << (*typeid(int).name() == 'i');
//     std::cout << (*typeid(double).name() == 'd');

//     auto a = *typeid(int).name();
//     auto b = *typeid(double).name();
//     auto c = *typeid(string).name();

// }


int main () {

    UserInput userInput;
    userInput.user_input();

    return 0;
}