/*In Program 15-20 , the file Time.h contains a Time class. 
Design a class called MilTime that is derived from the Time 
class. The MilTime class should convert time in military 
(24-hour) format to the standard time format used by the 
Time class. The class should have the following member 
variables: milHours :
Contains the hour in 24-hour format. For example, 1:00 pm 
would be stored as 1300 hours, and 4:30 pm would be stored 
as 1630 hours.
milSeconds : Contains the seconds in standard format. The 
class should have the following member functions:
Constructor : The constructor should accept arguments for 
the hour and seconds, in military format. The time should 
then be converted to standard time and stored in the hours , 
min , and sec variables of the Time class.
setTime :
Accepts arguments to be stored in the milHours and milSeconds variables. The time should then be converted to standard time and stored in the hours , min , and sec variables of the Time class.

getHour : Returns the hour in military format. getStandHr : 
Returns the hour in standard format.
Demonstrate the class in a program that asks the user to 
enter the time in military for- mat. The program should then 
display the time in both military and standard format.
Input Validation: The MilTime class should not accept hours 
greater than 2359, or less than 0. It should not accept 
seconds greater than 59 or less than 0

Time Clock
Design a class named TimeClock . The class should be 
derived from the MilTime class you designed in 
Programming Challenge 4. The class should allow the 
programmer to pass two times to it: starting time and 
ending time. The class should have a member function that 
returns the amount of time elapsed between the two times. 
For example, if the starting time is 900 hours (9:00 am), 
and the ending time is 1300 hours (1:00 pm), the elapsed 
time is 4 hours.

Input Validation: The class should not accept hours greater than 2359 or less than 0.
*/


#include <iostream>
#include <string> 
#include <exception>
#include <algorithm>

using namespace std;

// Testing
template <typename T> 
bool assert_isclose(T a, T b, float resolution=0.03) {

    if (abs(a - b) < resolution) {
        return true;
    }

    return false;
}

// Specification for the Date class 2 
#ifndef DATE_H
#define DATE_H
class Date {
    protected:
        int day;
        int month;
        int year;

    public: 
        // Default constructor
        Date() : day(1), month(1), year(1990) {}

        // Constructor
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        // Accessors
        int getDay() const{ return day; }

        int getMonth() const { return month; }

        int getYear() const { return year; }
};
#endif

// Specification for the Time class 2 
#ifndef TIME_H
#define TIME_H
class Time {

    protected: 
        int hour;
        int minute;
        int second;

    public: 
        // Default constructor
        Time() { hour = 0; minute = 0; second = 0; }

        // Constructor
        Time(int h, int m, int s) { hour = h; minute = m; second = s; }

        // Accessor functions
        int getHour() const{ return hour; }

        int getMinute() const { return minute; }

        int getSecond() const { return second; }
};
#endif


// Specification for the DateTime class
#ifndef DATETIME_H 
#define DATETIME_H 

using namespace std; 

class DateTime : public Date, public Time { 
    public: 

    // Default constructor
    DateTime() : Date(), Time() {}

    // Constructor
    DateTime(int day, int month , int year, int hour, int minute, int second) : 
        Date(day, month, year), Time(hour, minute, second) {}

    // The showDateTime function displays the
    void showDateTime() const {
        cout << getMonth() << "/" << getDay() << "/" << getYear() << " ";
        // Display the time in the form HH:MM:SS. 
        cout << getHour() << ":" << getMinute() << ":" << getSecond() << endl;
    }

}; 
#endif


// Specification for military time
class MilTime : public Time {
    public:
        int milHours;
        int milMinute;
        int milSeconds;
        // Constructor
        MilTime() : Time(), milHours(0), milMinute(0), milSeconds(0) {}
        
        MilTime(int hour, int min, int sec) : Time(hour, min, sec) {
            setTime(hour, min, sec);
        }
        
        void setTime(int hour, int min, int sec) {
            if (hour >= 24 || hour < 0) {
                throw std::logic_error("Hour cannot be greater than 24 or less than 0");
            }
            else {
                milHours = hour;
            }

            if (min >= 60 || min < 0) {
                throw std::logic_error("Minutes cannot be greater than 60 or less than 0");
            }
            else { 
                milMinute = min;
            }

            if (sec >= 60 || sec < 0) {
                throw std::logic_error("Minutes cannot be greater than 60 or less than 0");
            }
            else {
                milSeconds = sec;
            }
        }

        int getMilHour() {
            return milHours;
        }

        int getMinute() {
            return milMinute;
        }

        int getStandHr() {
            return milHours % 12;
        }
};


struct TimeClock : public MilTime {

    MilTime start;
    MilTime end;

    // Default constructor
    TimeClock() : start(0,0,0), end(0,0,0) {}
    // Constructor - accept time object
    TimeClock(MilTime astart, MilTime aend) : start(astart), end(aend) {}
    // Constructor - accept explicity integer start and end times
    TimeClock(int ahour, int amin, int asec, int bhour, int bmin, int bsec) : 
        start(ahour, amin, asec), end(bhour, bmin, bsec) {}

    float time_elapsed() {
        int rhour;
        int rmin;
        int rsec;

        // Hours
        if (end.getMilHour() >= start.getMilHour()) {
            rhour = end.getMilHour() - start.getMilHour();
        }
        else if (end.getMilHour() < start.getMilHour()) {
            // Same - its OK to be negative
            rhour = end.getMilHour() - start.getMilHour();
        }

        // Minutes
        if (end.getMinute() >= start.getMinute()) {
            rmin = end.getMinute() - start.getMinute();
        }
        else if (end.getMinute() < start.getMinute()) {
            // Same - its OK to be negative
            rmin = end.getMinute() - start.getMinute();
        }

        // Seconds
        if (end.getSecond() >= start.getSecond()) {
            rsec = end.getSecond() - start.getSecond();
        }
        else if (end.getSecond() < start.getSecond()) {
            // Same - its OK to be negative
            rsec = end.getSecond() - start.getSecond();
        }

        return  static_cast<float>(rhour) + 
                static_cast<float>(rmin) / 60.0 + 
                static_cast<float>(rsec) / 3600.0;
    }
};


void test_TimeClock() {
    std::cout << "Begining test: " << __func__ << "\n";

    MilTime start{10,10,10};
    MilTime end{11,11,11};

    TimeClock t {start, end};
    TimeClock t2 {10,10,10, 11,11,11};

    // 1 hour, 1 minute, 1 second
    std::cout << t.time_elapsed();
    // 1 hour, 1 minute, 1 second
    std::cout << t2.time_elapsed();

    // Test end < beginning
    int ahour = 10, amin = 10, asec = 10;
    int bhour = 11, bmin = 11, bsec = 11;
    float test = (static_cast<float>(bhour - ahour) + 
        static_cast<float>(bsec - asec)/60 + 
        static_cast<float>(bsec - asec)/3600 );
    t = TimeClock{ahour, amin, asec, bhour, bmin, bsec};
    if (!assert_isclose(t.time_elapsed(), test)) {
        string msg = "Incorrect duration calculation: ";
        msg += std::to_string(t.time_elapsed()) + std::string(" Expected: ") + std::to_string(test);
        throw std::logic_error(msg);
    }

    // Test end < beginning
    ahour = 11, amin = 11, asec = 11;
    bhour = 10, bmin = 10, bsec = 10;
    test = (static_cast<float>(bhour - ahour) + 
        static_cast<float>(bsec - asec)/60 + 
        static_cast<float>(bsec - asec)/3600 );
    t = TimeClock{ahour, amin, asec, bhour, bmin, bsec};
    if (!assert_isclose(t.time_elapsed(), test)) {
        string msg = "Incorrect duration calculation: ";
        msg += std::to_string(t.time_elapsed()) + std::string(" Expected: ") + std::to_string(test);
        throw std::logic_error(msg);
    }

    // Only the hour is negative
    ahour = 11, amin = 10, asec = 10;
    bhour = 10, bmin = 11, bsec = 11;
    test = (static_cast<float>(bhour - ahour) + 
        static_cast<float>(bsec - asec)/60 + 
        static_cast<float>(bsec - asec)/3600 );
    t = TimeClock{ahour, amin, asec, bhour, bmin, bsec};
    if (!assert_isclose(t.time_elapsed(), test)) {
        string msg = "Incorrect duration calculation: ";
        msg += std::to_string(t.time_elapsed()) + std::string(" Expected: ") + std::to_string(test);
        throw std::logic_error(msg);
    }

    // Input validation
    ahour = 23, amin = 59, asec = 59;
    bhour = 23, bmin = 59, bsec = 59;
    test = (static_cast<float>(bhour - ahour) + 
        static_cast<float>(bsec - asec)/60 + 
        static_cast<float>(bsec - asec)/3600 );
    t = TimeClock{ahour, amin, asec, bhour, bmin, bsec}; // Should not throw error
    try {
        t = TimeClock{24, 0, 0, 23, 59, 59}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{23, 59, 59, 24, 0, 0}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{25, 0, 0, 0, 0, 0}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{0, 0, 0, 25, 0, 0}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{0, 60, 0, 0, 0, 0}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{0, 0, 60, 0, 0, 0}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{0, 0, 0, 0, 60, 0}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }

    try {
        t = TimeClock{0, 0, 0, 0, 0, 60}; // Should throw error
    } catch(std::logic_error& e) {
        std::cout << "Caught std::logic_error successfully: " << e.what() << "\n";
    }



    std::cout << "Success, Passed: " << __func__ << "\n";
}





int main () {

    try {
    test_TimeClock();
    } catch (std::logic_error& e) {
        std::cout << "Failed... " << e.what();
    }


    return 0;
}