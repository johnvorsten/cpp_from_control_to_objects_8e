/*Write a class named Car that has the following member variables: 
• yearModel—an int that holds the car’s year model 
• make—a string that holds the make of the car 
• speed—an int that holds the car’s current speed

In addition, the class should have the following constructor and other 
member functions: 
• Constructor—The constructor should accept the car’s 
year model and make as arguments. These values should be assigned to 
the object’s yearModel and make member variables. The constructor should 
also assign 0 to the speed member variables.

• Accessor—appropriate accessor functions to get the values stored in an 
object’s yearModel, make, and speed member variables
• accelerate—The accelerate function should add 5 to the speed member 
variable each time it is called.

• braki The brake function should subtract 5 from the speed 
member variable each time it is called.

Demonstrate the class in a program that creates a Car object, 
then calls the accel erate function five times. After each call to 
the accelerate function, get the current speed of the car and display 
it. Then, call the brake function five times. After each call to the 
brake function, get the current speed of the car and display it.

*/

#include <string>
#include <iostream>
#include <exception>
#include <chrono>
#include <ctime>

// Class declarations
namespace assignment {
typedef std::chrono::system_clock Clock;

class Car {
    public:
    void set_yearModel(int ayearModel) {
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);


        if (ayearModel > std::localtime(&time)->tm_year + 1900 + 1)
            throw std::logic_error("That model has not been released yet");
        else
            yearModel = ayearModel;
        }

    void set_make(std::string amake) {make = amake;}

    void set_speed(int aspeed) {
        if (aspeed > 120)
            throw std::logic_error("Cannot exceed 120 speed units");
        else
            speed = aspeed;
        }

    void accelerate() {
        if (speed < 120)
            speed += 5;
        else
            ;
    }

    void brake() {
        if (speed > 5)
            speed -= 5;
        else if (speed < 5)
            speed = 0;
    }

    int get_yearModel() {return yearModel;}

    std::string get_make() {return make;}

    int get_speed() {return speed;}

    Car(int ayearModel, std::string amake, int aspeed) 
        : yearModel(ayearModel), make(amake), speed(aspeed) {}

    private:
    int yearModel;
    std::string make;
    int speed;
};

}; // End namespace

using namespace std;

int main () {

    std::cout << "Initializing Car object with {2004, 'Ford', 25}" << endl;
    assignment::Car car {2004, "Ford", 25};

    std::cout << "Initial values: " << endl;
    std::cout << "The car year is: " << car.get_yearModel() << endl;
    std::cout << "The car make is: " << car.get_make() << endl;
    std::cout << "The car speed is: " << car.get_speed() << endl;
    for (int i=0; i<5; i++) {
        std::cout << "Calling accelerate at: " << car.get_speed() << endl;
        car.accelerate();
        std::cout << "The new speed is: " << car.get_speed() << endl;
    }

    std::cout << "\n\n";
    for (int i=0; i<5; i++) {
        std::cout << "Calling brake at: " << car.get_speed() << endl;
        car.brake();
        std::cout << "The new speed is: " << car.get_speed() << endl;
    }

    return 0;
}