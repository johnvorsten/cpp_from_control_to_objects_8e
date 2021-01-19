#include <vector>
#include <cstdio>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <string>

using namespace std;

/*Class definition specifier

For base classes (not children)
class-key attr class-head-name { member-specification }

For children
class-key attr class-head-name : base-specifier-list { member-specification }

*/

class ClassHeadName {
    public: // Attribute declarations
        int public_data_member;

    public: // Function Declarations
        void set_private_data_member(vector<int> private_data_member) {
            insult(private_data_member);
            this->private_data_member = private_data_member;
            insult(private_data_member);
        }

        vector<int> get_private_data_member() const {
            return private_data_member;
        }

        void complement();

    private: // Attribute declarations
        vector<int> private_data_member;

    private: // Function declarations
        void insult(vector<int> private_data_member) {
            printf("That is so stupid... why would you set private_data_member to\n");
            std::cout << "[";
            for (int x : private_data_member) {
                std::cout << x << ", ";
            }
            std::cout << "]" << endl;
        }
};

// Define a function outside a class
void ClassHeadName::complement() {
    std::cout << "Just kidding I'm appreciative of you" << endl;
}

class Date {

    public:
        Date(int ayear, int amonth, int aday) {
            year = ayear;
            month = amonth;
            day = aday;
        }

    private:
        int year;
        int month;
        int day;

        string month_format() {
            
            if (std::to_string(month).length() == 1) {
                return std::to_string(month).insert(0, "0");
            }
            else if (std::to_string(month).length() == 2) {
                return std::to_string(month);
            }

            return string("00");
        }

        string day_format() {

            if (std::to_string(day).length() == 1) {
                return std::to_string(day).insert(0, "0");
            }
            else if (std::to_string(day).length() == 2) {
                return std::to_string(day);
            }

            return string("00");
        }


    public:
        void get_date_iso()  {
            std::cout << year << "-" << month_format().c_str() << "-" << day_format().c_str() << endl;
        }

};


int main () {

    // Instantiate
    ClassHeadName klass;
    klass.public_data_member = 1;
    klass.set_private_data_member(vector<int> {1,2,3,4});
    klass.get_private_data_member();    // Call methods
    klass.set_private_data_member(vector<int> {5,6,7,8});
    klass.get_private_data_member();    // Call methods
    klass.complement();                 // Call methods

    // Standard pointer
    ClassHeadName *klassp = nullptr;    // Instantiate null pointer with usual type *name = nullptr
    ClassHeadName *klassp2 = nullptr;
    klassp = new ClassHeadName;         // Set pointer to instance of object
    klassp2 = new ClassHeadName;
    klassp->public_data_member = 1;
    klassp->set_private_data_member(vector<int> {1,2,3,4});

    // Unique pointer (smart pointer)
    /*unique_ptr is deleted when a) the managing object is destroyed, or
    the object is assigned to another pointer via operator= or reset()
    
    unique_ptr<ClassHeadName> means that ClassHeadName is the template for 
    unique_ptr. It means unique_ptr can reference a CalssHeadName object
    The name of the unique_ptr is klassp3
    The expression (new ClassHeadName) allows a chunk of memory to hold
    a ClassHeadName instance. That memory chunk is assigned to the pointer*/
    std::unique_ptr<ClassHeadName> klassp3(new ClassHeadName);
    auto klassp4 = std::unique_ptr<ClassHeadName>(new ClassHeadName);

    auto ref = klassp4.get();
    ref->complement();
    ref->public_data_member = 1;
    ref->set_private_data_member(vector<int>{1,2,3});
    ref->get_private_data_member();

    // Print a date
    auto year = 2021;
    auto month = 1;
    auto day = 13;

    auto date = Date(year, month, day);
    date.get_date_iso();

    return 0;
}