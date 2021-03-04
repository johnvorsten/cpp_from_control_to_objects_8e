#include <iostream>
#include <string>

using namespace std;

int main () {

    string name = "John Vorsten";
    // std::getline(std::cin, name);


    std::cout << name.substr(0, 1) << ". ";
    std::cout << name.substr(name.find(" ") + 1, std::string::npos);

    std::cout << name.substr(name.find(" ") + 1, 1) << ". ";
    //int len = name.find(" ");
    std::cout << name.substr(0, name.length() - name.find(" "));

    return 0;
}