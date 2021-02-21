#include <iostream>

using namespace std;

int main () {

    std::cout << "Creating a Float Class Array Object with a size of 5.Using setI function with calls (0,1.4),(1,2.3),(2,3.13),(3,6.66),(4,7.711) to load array.\n";

    std::cout << "Using getI with all legitmate index values to print array.\n";

    std::cout << "The value of fArray1[0]= 1.4\n";

    std::cout << "The value of fArray1[1]= 2.3\n";

    std::cout << "The value of fArray1[2]= 3.13\n";

    std::cout << "The value of fArray1[3]= 6.66\n";

    std::cout << "The value of fArray1[4]= 7.711\n";

    std::cout << "Calling getHi returns highest value in array as: 7.711\n";

    std::cout << "Calling getLow returns lowest value in array as: 1.4\n";

    std::cout << "Calling getAvg returns the average of the array as: 4.2402\n";

    return 0;
}