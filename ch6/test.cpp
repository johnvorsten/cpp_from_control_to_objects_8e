#include <iostream> 

using namespace std;

void showDouble(int); // Function prototype
void func1(double, int); // Function prototype

int main() {
    int num; 
    for (num = 0; num < 10; num++) showDouble(num);

    int x = 0; double y = 1.5;
    std::cout << x << " " << y << std::endl; 
    func1(y, x);
    std::cout << x << " " << y << std::endl;


    return 0;
}

// Definition of function showDouble. 
void showDouble(int value) {
    std::cout << value << "\t" << (value * 2) << std::endl; 
}

void func1(double a, int b) {
    std::cout << a << " " << b << std::endl; 
    a = 0.0; b = 10;
    std::cout << a << " " << b << std::endl; 
}