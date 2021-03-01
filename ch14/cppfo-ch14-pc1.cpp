#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Numbers {

    private:
    // Value to convert to english
	int number;

    // 0 to 12
    static string zero_to_twelve[13];

    // 13 to 19
	static string thirteen_to_nineteen[7];

    // twenty, thrity, fourty, fifty, [...], ninety
    static string tens[8];
	
    static string hundred;
    static string thousand;


    public:
    Numbers(int a) : number(a) {}

    void print(int number) {

        auto res = stub(number);
        bool first = true;
        for (auto& x : res) {
            if (first) {
                std::cout << x;
            }
            else {
                std::cout << " " << x;
            }
            first = false;
        }
        std::cout << "\n";

    }

    vector<string> stub(int number) {
        /*Examples - 

        */

       vector<string> res;

        if (number / 1000 > 0) {
            // Append thousands position
            int thousands = number / 1000;
            res.push_back(zero_to_twelve[thousands]);
            res.push_back("thousand");
            // Convert the quotient
            if (number % 1000 > 0) {
                auto recursion = stub(number % 1000);
                res.insert(res.end(), recursion.begin(), recursion.end());
            }
        }

        else if (number / 100 > 0) {
            // Append hundreds position
            int hundreds = number / 100;
            res.push_back(zero_to_twelve[hundreds]);
            res.push_back("hundred");
            // Convert the quotient
            // if ((static_cast<float>(number) / 100.0) > 1.0 && (number % 100 > 0)) {
            if (number % 100 > 0) {
                auto recursion = stub(number % 100);
                res.insert(res.end(), recursion.begin(), recursion.end());
            }
        }

        else if (number > 19) {
            // Implicitly must be between 20-99
            int tens_ = number / 10;
            res.push_back(tens[tens_ - 2]);
            if (number % 10 > 0)
                res.push_back(zero_to_twelve[number % 10]);
        }

        else if (number > 13) {
            // Implicitly must be 13-19
            res.push_back(thirteen_to_nineteen[number - 13]);
        }

        else {
            // Implicily must be 0-12
            res.push_back(zero_to_twelve[number]);
        }

        return res;
        }
	
};

string Numbers::thirteen_to_nineteen[7] = {
    "thirteen","fourteen",
    "fifteen","sixteen",
    "seventeen","eighteen",
    "nineteen",};

string Numbers::zero_to_twelve[13] = {
    "zero", "one","two",
    "three","four",
    "five","six",
    "seven","eight",
    "nine","ten",
    "eleven","twelve"};

string Numbers::tens[8] = {
    "twenty","thirty",
    "forty","fifty",
    "sixty","seventy",
    "eighty","ninety"};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";


// Function definitions
void test_numbers() {

    // Test constructor
    Numbers number{0};

    // Test stub and all that
    int test = 0;
    auto res = number.stub(test);
    number.print(test);
    test = 1;
    res = number.stub(test);
    number.print(test);
    test = 10;
    res = number.stub(test);
    number.print(test);
    test = 11;
    res = number.stub(test);
    number.print(test);
    test = 19;
    res = number.stub(test);
    number.print(test);
    test = 20;
    res = number.stub(test);
    number.print(test);
    test = 21;
    res = number.stub(test);
    number.print(test);
    test = 23;
    res = number.stub(test);
    number.print(test);
    test = 99;
    res = number.stub(test);
    number.print(test);
    test = 100;
    res = number.stub(test);
    number.print(test);
    test = 101;
    res = number.stub(test);
    number.print(test);
    test = 199;
    res = number.stub(test);
    number.print(test);
    test = 200;
    res = number.stub(test);
    number.print(test);
    test = 201;
    res = number.stub(test);
    number.print(test);
    test = 999;
    res = number.stub(test);
    number.print(test);
    test = 1000;
    res = number.stub(test);
    number.print(test);
    test = 1001;
    res = number.stub(test);
    number.print(test);
    test = 1999;
    res = number.stub(test);
    number.print(test);
    test = 2000;
    res = number.stub(test);
    number.print(test);
    test = 2001;
    res = number.stub(test);
    number.print(test);
    test = 9999;
    res = number.stub(test);
    number.print(test);

}

int user_input() {
    int input = 0;
    std::cout << "Enter an integer:";

    std::cin >> input;
    return input;
}


int main () {

    // Test constructor
    Numbers number{0};

    // Test stub and all that
    auto input = user_input();
    auto res = number.stub(input);
    number.print(input);

    return 0;
}