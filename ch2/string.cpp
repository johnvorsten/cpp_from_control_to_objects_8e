// Declaring string data types from standard

#include <string>
#include <stdio.h>

using namespace std;

int main() {
    std::string sentence("This is a string");
    std::string str2 = "This is also a string declared differently";
    std::string str3{"Ditto"};

    printf(sentence.c_str());
    printf(str2.c_str());
    printf(str3.c_str());
    return 0;
}