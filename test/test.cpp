#include <iostream>

using namespace std;

int main () {

    string str = {"This is a pretty string"};

    str[1203] = 'a';

    std::cout << str[25149252];

    // auto a = str * 2;
    // auto a = "jdfksal" * 2;


    return 0;
}