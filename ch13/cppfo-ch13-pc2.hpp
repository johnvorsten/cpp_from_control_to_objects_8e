#include <string>
#include <iostream>

using namespace std;

class Employee {
    public:
    // Default Constructor
    Employee() : name(""), idNumber(0), department(""), position("") {
    }

    // Constructor - All parameters
    Employee(string aname, int aidNumber, string adepartment, string aposition) : 
        name(aname), idNumber(aidNumber), department(adepartment), position(aposition) {
    }

    // Constructor - mployee’s name and ID number. The department and position fields should 
    // be assigned an empty string
    Employee(string aname, int aidNumber) : 
        name(aname), idNumber(aidNumber), department(""), position("") {
    }

    // Getter and setter
    void set_name(string aname){name = aname;}
    void set_idNumber(int aidNumber){idNumber = aidNumber;}
    void set_department(string adepartment){department = adepartment;}   
    void set_position(string aposition){position = aposition;}
    string get_name(){return name;}
    int get_idNumber(){return idNumber;}
    string get_department(){return department;}
    string get_position(){return position;}

    // Operators
    friend ostream& operator<<(ostream& os, const Employee& employee);


    private:
    std::string name;
    int idNumber;
    std::string department;
    std::string position;

};

std::ostream& operator<<(ostream& os, const Employee& employee) {
    
    os << "Employee<";
    os << employee.name << ",";
    os << employee.idNumber << ",";
    os << employee.department << ",";
    os << employee.position;
    os << ">" << std :: endl;


    return os;
}