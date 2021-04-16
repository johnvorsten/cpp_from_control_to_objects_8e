/*
Design a class named TimeOff . The purpose of the class is to track an employee’s sick leave, 
vacation, and unpaid time off. It should have, as members, the following instances of the 
NumDays class described in Programming Challenge 4:

maxSickDays sickTaken maxVacation vacTaken
A NumDays object that records the maximum number of days of sick leave the employee may take.
A NumDays object that records the number of days of sick leave the employee has already taken.
A NumDays object that records the maximum number of days of paid vacation the employee may take.
A NumDays object that records the number of days of paid vacation the employee has already taken.
maxUnpaid A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
unpaidTaken A NumDays object that records the number of days of unpaid leave the employee has taken.

Additionally, the class should have members for holding the employee’s 
name and iden- tification number. It should have an appropriate 
constructor and member functions for storing and retrieving data 
in any of the member objects.

Input Validation: Company policy states that an employee may not 
accumulate more than 240 hours of paid vacation. The class should 
not allow the maxVacation object to store a value greater than this amount.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

class NumDays {
    public:
    NumDays(float ahours, float alimit_hours) : hours(ahours), limit_hours(alimit_hours) {
        days = hours / 24;
    }

    float hours;
    float days;
    float limit_hours;

    float get_hours() {
        return hours;
    }

    float get_days() {
        return hours / 24;
    }

    void set_hours(float ahours) {
        if (ahours > limit_hours) {
            string msg = "You cannot accumulate more than 240 hours of vacation";
        throw std::logic_error(msg);
        }
        else {
            hours = ahours;
            days = hours / 24;
        }
        
    }

    void add_hours(float ahours) {
        if ( (ahours + hours) > limit_hours) {
            string msg = "You cannot accumulate more than 240 hours of vacation";
            throw std::logic_error(msg);
        }
    }

    void set_days(float adays) {
        if ((adays * 24) > 240) {
            string msg = "You cannot accumulate more than 240 hours of vacation";
        throw std::logic_error(msg);
        }
        else {
            days = adays;
            hours = days * 24;
        }
    }

    NumDays operator+(const NumDays& other) {
        NumDays temp(hours + other.hours, this->limit_hours);
        return temp;
    }

    NumDays operator-(const NumDays& other) {
        NumDays temp(hours - other.hours, this->limit_hours);
        return temp;
    }

    NumDays operator--() { // Prefix operator
        add_hours(-1);
        return *this;
    }

    NumDays operator++() { // Prefix operator
        add_hours(1);
        return *this;
    }

    NumDays operator--(int) { // Postfix operator
        NumDays temp(hours, this->limit_hours);
        add_hours(-1);
        return temp;
    }

    NumDays operator++(int) { // Postfix operator
        NumDays temp(hours, this->limit_hours);
        add_hours(1);
        return temp;
    }

    void operator=(float aval) {
        // Set the number of days
        set_days(aval);
    }

};

class Employee {
    public:
    int id;
    string first;
    string middle;
    string last;

    Employee();

    Employee(string& name, int aid) : id(aid) {
        
        // tokenize the name into segments
        vector<string> name_vec;
        string delimeter = " ";
        size_t pos = 0;
        string token;
        while ((pos = name.find(delimeter)) != std::string::npos) {
            token = name.substr(0, pos);
            name_vec.push_back(token);
            name.erase(0, pos + delimeter.length());
        }

        // If there are three tokens
        if (name_vec.size() == 3) {
            last = name_vec[2];
            middle = name_vec[1];
            first = name_vec[0];
        }

        // Or two segments if only two are passed...
        else if (name_vec.size() == 2) {
            last = name_vec[1];
            // middle = name_vec.pop_back();
            first = name_vec[0];
        }

        else {
            string msg = "Incorrect value for name. Pass 'first middle last' or 'first last'";
            throw std::logic_error(msg);
        }

    }

    Employee(string& first, string& middle, string& last, int aid) : id(aid) {
        // KK
    }

};

class TimeOff : public Employee {
    public:
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;

    TimeOff() : 
        Employee(), maxSickDays(2*24, 2*24), sickTaken(0, 2*24), maxVacation(10*24, 10*24), vacTaken(0, 10*24), maxUnpaid(5*24, 5*24), unpaidTaken(0, 5*24) {}
    TimeOff(float vacation_limit) : 
        Employee(), maxSickDays(2*24, 2*24), sickTaken(0, 2*24), maxVacation(10*24, vacation_limit), vacTaken(0, vacation_limit), maxUnpaid(5*24, 5*24), unpaidTaken(0, 5*24) {}
    TimeOff(string name, int id, float vacation_limit) : 
        Employee(name, id), maxSickDays(2*24, 2*24), sickTaken(0, 2*24), maxVacation(10*24, vacation_limit), vacTaken(0, vacation_limit), maxUnpaid(5*24, 5*24), unpaidTaken(0, 5*24) {}


    void set_maxSickDays(float aval) {maxSickDays = aval;}
    void set_sickTaken(float aval) {sickTaken = aval;}
    void set_maxVacation(float aval) {maxVacation = aval;}
    void set_vacTaken(float aval) {vacTaken = aval;}
    void set_maxUnpaid(float aval) {maxUnpaid = aval;}
    void set_unpaidTaken(float aval) {unpaidTaken = aval;}

    NumDays get_maxSickDays() {return maxSickDays;}
    NumDays get_sickTaken() {return sickTaken;}
    NumDays get_maxVacation() {return maxVacation;}
    NumDays get_vacTaken() {return vacTaken;}
    NumDays get_maxUnpaid() {return maxUnpaid;}
    NumDays get_unpaidTaken() {return unpaidTaken;}

};


void test_TimeOff() {
    std::cout << "Begging test: " << __func__ << "\n";

    float limit_hours = 240;
    string name = "Jeffery Holland Bezos";
    int id = 1; // root
    TimeOff timeoff(name, id, limit_hours);

    // Test constructor
    if (!(timeoff.get_maxSickDays().get_hours() == 2*24)) {
        std::cout << "Failed constructor test: get_maxSickDays\n";
        return;
    }
    if (!(timeoff.get_maxVacation().get_hours() == 10*24)) {
        std::cout << "Failed constructor test: get_maxVacation\n";
        return;
    }
    if (!(timeoff.get_maxUnpaid().get_hours() == 5*24)) {
        std::cout << "Failed constructor test: get_maxUnpaid\n";
        return;
    }

    if (!(timeoff.get_sickTaken().get_hours() == 0)) {
        std::cout << "Failed constructor test: get_sickTaken\n";
        return;
    }
    if (!(timeoff.get_vacTaken().get_hours() == 0)) {
        std::cout << "Failed constructor test: get_vacTaken\n";
        return;
    }
    if (!(timeoff.get_unpaidTaken().get_hours() == 0)) {
        std::cout << "Failed constructor test: get_unpaidTaken\n";
        return;
    }
    
    // Test limit for hours off
    try {
        timeoff.vacTaken.add_hours(241); // Whoops...
    } catch(std::logic_error& e) {
        std::cout << "Success, caught too many hours: " << e.what() << "\n";
    }
    try {
        timeoff.sickTaken.add_hours(241); // Whoops...
    } catch(std::logic_error& e) {
        std::cout << "Success, caught too many hours: " << e.what() << "\n";
    }
    try {
        timeoff.unpaidTaken.add_hours(241); // Whoops...
    } catch(std::logic_error& e) {
        std::cout << "Success, caught too many hours: " << e.what() << "\n";
    }

    std::cout << "Success, passed: " << __func__ << "\n";
}


int main () {
    test_TimeOff();

    return 0;
}