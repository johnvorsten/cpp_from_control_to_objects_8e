#include <iostream>
#include <string>

using namespace std;

string default_args(string str = "Default") {
    std::cout << str << endl;
    return str;
}


int main () {

    return 0;
}