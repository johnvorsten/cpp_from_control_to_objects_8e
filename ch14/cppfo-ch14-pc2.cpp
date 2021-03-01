#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class DayOfYear {

    private:
    // Value to convert to english
	int number;

    // 0 to 12
    static string months[12];
    static map<string, int> day_map;

    public:
    DayOfYear(int a) : number(a) {
        if (a > 365) {
            std::cout << "Program terminating: The day entered is >365." << endl;
            std::exit(1);
        }
        // else if (a < 1) {
        //     std::cout << "Program terminating: The day entered is <1" << endl;
        //     std::exit(1);
        // }
    }
    DayOfYear(string month, int day) {

        // Input validation
        if (day > day_map[month]) {
            std::cout << "Program terminating: The day number entered is outside the range for the month given." << endl;
            std::exit(1);
        }

        int counter = 0;
        for (const auto& [key, value] : day_map) {
            if (month == key) {
                break;
            }
            else {
                counter += value;
            }
        }

        number = day + counter;
    }

    void print() {

        auto res = stub(number);

        std::cout << "Day " << number << " would be ";
        std::cout << res["month"] << " ";
        std::cout << res["day"];
        std::cout << "\n";

    }

    map<string, string> stub(int number) {
        /*Examples - 
        */

       map<string, string> res = {{"month","0"}, {"day","0"}};
       int counter = 0;

        // for (auto const& [month, days] : day_map) {
        //     counter += // TODO
        // }
        for (const auto& month : months) {
            counter += day_map[month];
            if (counter >= number) {
                res["month"] = month;
                res["day"] = std::to_string(number - (counter - day_map[month]));
                break;
            }
        }

        return res;
        }
	
    void operator++() {
        if (number == 365) {
            number = 1;
        }
        else {
            number++;
        }
    }

    void operator--() {
        if (number == 1) {
            number = 365;
        }
        else {
            number--;
        }
    }

};

string DayOfYear::months[12] = {
    "January","February",
    "March","April",
    "May","June",
    "July","August",
    "September","October",
    "November","December",};

map<string, int> DayOfYear::day_map = 
    {{"January",31},{"February",28},{
    "March",31},{"April",30},{
    "May",31},{"June",30},{
    "July",31},{"August",31},{
    "September",30},{"October",31},{
    "November",30},{"December",31}};


// Function definitions
void test_DayOfYear() {

    // Test constructor
    DayOfYear number{1};

    // Test stub and all that
    int test = 1;
    auto res = number.stub(test);
    number.print();

}

int user_input() {
    int input = 0;

    std::cout << "Using the first constructor that only requires the day of the year (1-365)." << endl;
    std::cout << "Enter the a day of the year or a number <=0 to end:";

    std::cin >> input;
    return input;
}


int main () {

    // Test
    auto input = user_input();
    // auto input = 222;
    DayOfYear number{input};
    auto res = number.stub(input);
    number.print();

    std::cout << "Enter the a day of the year or a number <=0 to end:";
    std::cin >> input;
    DayOfYear number3{input};
    // number3.print();
    


    // User input 2
    string month = "August";
    int day = 30;

    std::cout << "Using the second constructor that accepts a month name and a day integer" << endl;
    std::cout << "Enter the name of a month:";
    std::cin >> month;
    std::cout << "Enter a valid day of the month you just entered or a number <=0 to end:";
    std::cin >> day;
    DayOfYear number2(month, day);
    number2.print();

    return 0;
}