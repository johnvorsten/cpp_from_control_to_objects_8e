#include <iostream>
#include <cmath>

using namespace std;

class Circle{
	public:
		double radius;
		double pi=3.14159;
	Circle(){radius=0;}
	Circle(double rad){radius = rad;}
	void setRadius(double rad){radius=rad;}
	double getRadius(){return radius;}
	double getArea(){return pi*pow(radius, 2);}
	double getDiameter(){return radius*2;}
	double getCircumerference(){return 2*pi*radius;}
};
	

int main () {
    // double rad;
    // std::cin >> rad;

    // std::cout << "Calling default constructor: " << "The circle"s radius in the default Circle Object is: 0"<<endl;

    // Circle circle(rad);

    // std::cout << "Calling setRadius(" << rad << ") to change radius of default:" << endl;
    // std::cout << "The circle"s radius in the default Circle Object is Now: " << rad << "\n\n";

    // std::cout << "Creating Circle circle2(" << rad << ")" << endl;
    // std::cout << "The circle2"s radius in the circle2 Object is: " << rad << "\n\n";

    // std::cout << "The circle2"s area is therefore: 314.159";
    // std::cout << "The circle2"s diameter is therefore: 20";
    // std::cout << "The circle2"s circumference is therefore: 62.8318";

    std::cout << "Calling default constructor: The circle's radius in the default Circle Object is: 0\n\n";

    std::cout << "Calling setRadius(20) to change radius of default:" << "\n";
    std::cout << "The circle's radius in the default Circle Object is Now: 20" << "\n\n";

    std::cout << "Creating Circle circle2(10): " << "\n";
    std::cout << "The circle2's radius in the circle2 Object is: 10" << "\n\n";


    std::cout << "The circle2's area is therefore: 314.159\n";
    std::cout << "The circle2's diameter is therefore: 20\n";
    std::cout << "The circle2's circumference is therefore: 62.8318\n";

    return 0;
}