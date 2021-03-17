#include <iostream>
#include <string>

using namespace std;


template <typename T>
T maximum(T& a, T& b) {
    if (a > b) {
        return b;
    }

    else return a;
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



    }


    void user_type_choice_input() {

        string msg = 
            "Enter\n"
            "1)To compare integers\n"
            "2)To compare doubles\n"
            "3)To compare strings:";
        int choice;

        std::cout << msg;
        std::cin >> choice;
        switch (choice) {
            
            case 1: {
                result<int> res = val_input<int>();
                // Determine min or max choice
                auto min_max_choice = user_min_max_input();
                // Display the choice and result
                display_min_max(min_max_choice, res);
                break;
            }

            case 2: {
                result<double> res = val_input<double>();
                // Determine min or max choice
                auto min_max_choice = user_min_max_input();
                // Display the choice and result
                display_min_max(min_max_choice, res);
                break;
            }

            case 3: {
                result<string> res = val_input<string>();
                // Determine min or max choice
                auto min_max_choice = user_min_max_input();
                // Display the choice and result
                display_min_max(min_max_choice, res);
                break;
            }
        }
    }


    int user_min_max_input() {

        string msg_min_max = 
            "Enter\n"
            "1)To find minimum\n"
            "2)To find maximum\n";
        int min_max_choice;
        std::cin >> min_max_choice;

        return min_max_choice;
    }


    template <typename T>
    void display_min_max(int min_max_choice, result<T> res) {

        switch (min_max_choice) {
            case 1:
                auto min = minimum(res.val1, res.val2);
                std::cout << min << "\n";
                break;

            case 2:
                auto max = maximum(res.val1, res.val2);
                std::cout << max << "\n";
                break;

        }

    }


    template <typename T>
    result<T> val_input() {
        T val1;
        T val2;

        if (typeid(T).name() == "int") {
            std::cout << "Enter first integer:";
            std::cin >> val1;
            std::cout << "\n";
            std::cout << "Enter second integer:";
            std::cin >> val2;
            std::cout << "\n";
        }
        else if (typeid(T).name() == "double") {
            std::cout << "Enter first double:";
            std::cin >> val1;
            std::cout << "\n";
            std::cout << "Enter second double:";
            std::cin >> val2;
            std::cout << "\n";
        }
        else if (typeid(T).name() == "std::basic_string<char, std::char_traits<char>, std::allocator<char> >") {
            std::cout << "Enter first string:";
            std::cin >> val1;
            std::cout << "\n";
            std::cout << "Enter second string:";
            std::cin >> val2;
            std::cout << "\n";
        }

        return result<T>(val1, val2);
    }

};


int main () {

    verify(0, 10);

    return 0;
}