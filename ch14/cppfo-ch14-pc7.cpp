/*Design a class named Month. The class must have a private member of type
int to hold the month number and a static member of type array of strings to
hold the month names in the fashion of a lookup table.
The class will have a default constructor that sets the month number to 1,
as well as a constructor that accepts an int argument representing the month
number.
In addition, write the appropriate mutator functions to set the month
based on month number and month name.
Overload both the prefix and postfix versions of ++ and -- operators, such
that they increment or decrement the month number respectively. Note: if month
number is 12 when the increment operator is called, the month number will
become 1. By the same token, if month number is 1 and the decrement operator
is called, the month number becomes 12.
Also overload the << and >> operators such that the << operator displays a
month name and >> operator allows the user to input a month number.
Write a test program that would demonstrate the Month class. The program
would allow the user input two month numbers and display the next 8 months and
the previous 8 months (including the month that the user entered).
You may assume the user will always input an integer between 1 and 12.*/


#include <string>
#include <iostream>


class Month {

    public:
    int month;
    static std::string names[12];

    // Constructor
    Month() : month(1) {}
    Month(int a) : month(a - 1) {}

    // Setters
    void setMonth(int a) {
        month = a - 1;
    }
    void setMonth(std::string a) {
        int i = 0;
        for (auto& str: names) {
            if (str == a) {
                month = i;
            }
            i++;
        }
    }

    // Operators
    Month operator++() {
        if (month < 11)
            month++;
        else 
            month = 0;
        
        return *this;
    }
    Month operator--() {
        if (month > 0)
            month--;
        else 
            month = 11;
        return *this;
    }
    Month operator++(int) {
        Month temp(month);

        if (month < 11)
            month++;
        else 
            month = 0;

        return temp;
    }
    Month operator--(int) {
        Month temp(month);
        if (month > 0)
            month--;
        else 
            month = 11;
        return temp;
    }
    
    // Friends
    friend std::ostream& operator<<(std::ostream& os, const Month& obj);
    friend std::istream& operator>>(std::istream& is, Month& obj);

};

std::string Month::names[12] = {
    "January","February",
    "March","April",
    "May","June",
    "July","August",
    "September","October",
    "November","December",};

std::istream& operator>>(std::istream& is, Month& obj) {
    int val;
    is >> val;
    obj.setMonth(val);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Month& obj) {
    os << obj.names[obj.month];
    return os;
}

int main () {

    // {
    // Month month(1);
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // std::cout << month;
    // month++;
    // }




    /*allow the user input two month numbers and display the next 8 months and
    the previous 8 months*/
    int i_month;
    std::cout << "Enter: month number (1-12):";
    std::cin >> i_month;
    Month month(i_month);
    std::cout << "The next 8 months are: ";
    for (int i = 0; i < 7; i++) {
        std::cout << month << ", ";
        month++;
    }
    std::cout << month << "." << "\n";

    // Backwards
    std::cout << "Enter: another month number (1-12):";
    std::cin >> i_month;
    month.setMonth(i_month);
    std::cout << "The previous 8 months were: ";
    for (int i = 0; i < 7; i++) {
        std::cout << month << ", ";
        month--;
    }
    std::cout << month << "." << "\n";

    return 0;
}