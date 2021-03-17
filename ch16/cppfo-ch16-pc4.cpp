#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

template <typename T>
T abs_value(T& val) {
    return abs(val);
}

void WaitEnterv1() { 
    /*This function will continually check cin until an enter character is encountered
    It will print "You did not press enter?? for every character that is not a newline
    Finally, it will exit once a newline is enountered */
    std::cout << "Press Enter to continue..."; 
    while (std::cin.get()!='\n') {
        std::cout << "You did not press enter??";
    }; 
}


void WaitEnterv2() {
    // This will read the maximum number of characters from standard input until the '\n' character is read
    std::cout << "Press enter to continue...";
    // NOTE - anything on standard input is ignored, but the program will hang until it receives \n
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    std::cout << "You pressed enter at least once!" << endl;
}


void WaitEnterv3() {
    /*I'm not exactly sure what this does, but I think it will execute 'Continuing'
    unless there are multiple characters AND a space in cin*/
    int val;
    std::cout << "Enter a short or just enter to move to next data type:";
    if (std::cin >> val && std::cin.get() != '\n') {
        std::cout << "You entered a number";
    }
    else {
        std::cout << "Continuing";
    }
}


void WaitEnterv4() {

    int val;
    std::cout << "Enter a short or just enter to move to next data type:";

    // If the first character in cin is NOT newline then read standard input
    if (std::cin.peek() != '\n') {
        std::cin >> (val);
        // And.. ignore everything after that
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // If the newline character IS encountered.. then just discard everything in there
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "OK.. continuing..." << endl;
}


void user_input() {

    {
    int val;
    std::cout << "Enter a short or just enter to move to next data type:";
    while (std::cin.peek() != '\n') {
        std::cin >> (val);
        std::cout << "The absolute value of " << val << " is: " << abs_value(val) << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a short or just enter to move to next data type:";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n";
    }


    {
    int val;
    std::cout << "Enter an int or just enter to move to next data type:";
    while (std::cin.peek() != '\n') {
        std::cin >> (val);
        std::cout << "The absolute value of " << val << " is: " << abs_value(val) << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter an int or just enter to move to next data type:";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n";
    }


    {
    double val;
    std::cout << "Enter a double or just enter to move to next data type:";
    while (std::cin.peek() != '\n') {
        std::cin >> (val);
        std::cout << "The absolute value of " << val << " is: " << abs_value(val) << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a double or just enter to move to next data type:";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n";
    }


    {
    float val;
    std::cout << "Enter a float or just enter to move to next data type:";
    while (std::cin.peek() != '\n') {
        std::cin >> (val);
        std::cout << "The absolute value of " << val << " is: " << abs_value(val) << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a float or just enter to move to next data type:";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n";
    }


    {
    long val;
    std::cout << "Enter a long or just enter to move to next data type:";
    while (std::cin.peek() != '\n') {
        std::cin >> (val);
        std::cout << "The absolute value of " << val << " is: " << abs_value(val) << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a long or just enter to move to next data type:";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n";
    }
}


int main () {

    user_input();

    return 0;
}