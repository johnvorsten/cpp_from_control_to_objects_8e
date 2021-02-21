#include <iostream>
#include <iomanip>

using namespace std;

class Payroll{
    public:
        double hours;
        double rate;
        void setRate(double arate){rate = arate;}
        double getGross(){return hours * rate;}
        void setHours(double ahours) {
            if (ahours >= 60) 
                hours = 60;
            else
                hours = ahours;
        }

        void print(int index) {
            // std::cout << "Employee # " << index << " worked " << hours << " hours at "
            // "$" << rate << " for a gross pay of $" << this->getGross() << "\n";
            std::printf("Employee # %i worked %.2f hours at $%.2f for a gross pay of $%.2f\n", index, hours, rate, this->getGross());
        }

};

void user_input(Payroll* payroll, int size){
    double rate;
    double hours;

    for (int i=0; i<size; i++) {
        std::cout << std::setprecision(2);
        std::cout << "Enter the # " << i << " employee's rate of pay per hour:";
        std::cin >> rate;
        payroll[i].rate = rate;
        std::cout << "Enter the # " << i << " employee's hours worked for the week:";
        std::cin >> hours;
        payroll[i].setHours(hours);
    }
    std::cout << "\n\n";

}


int main () {

// std::cout << "Creating 7 Payroll objects.\n";
// std::cout << "Enter the # 0 employee's rate of pay per hour:Enter the # 0 employee's hours worked for the week:Enter the # 1 employee's rate of pay per hour:Enter the # 1 employee's hours worked for the week:Enter the # 2 employee's rate of pay per hour:Enter the # 2 employee's hours worked for the week:Enter the # 3 employee's rate of pay per hour:Enter the # 3 employee's hours worked for the week:Enter the # 4 employee's rate of pay per hour:Enter the # 4 employee's hours worked for the week:Enter the # 5 employee's rate of pay per hour:Enter the # 5 employee's hours worked for the week:Enter the # 6 employee's rate of pay per hour:Enter the # 6 employee's hours worked for the week:\n\n";

// std::cout << "Employee # 0 worked 22.00 hours at $12.22 for a gross pay of $268.84\n";
// std::cout << "Employee # 1 worked 36.00 hours at $99.99 for a gross pay of $3599.64\n";
// std::cout << "Employee # 2 worked 20.00 hours at $45.67 for a gross pay of $913.40\n";
// std::cout << "Employee # 3 worked 0.00 hours at $56.78 for a gross pay of $0.00\n";
// std::cout << "Employee # 4 worked 5.00 hours at $40.45 for a gross pay of $202.25\n";
// std::cout << "Employee # 5 worked 60.00 hours at $30.35 for a gross pay of $1821.00\n";
// std::cout << "Employee # 6 worked 45.00 hours at $30.33 for a gross pay of $1364.85\n";

    std::cout << "Creating 7 Payroll objects.\n";
    Payroll payroll[7];
    user_input(payroll, 7);
    for (int i=0; i<7; i++) {
        payroll[i].print(i);
    }

    return 0;
}