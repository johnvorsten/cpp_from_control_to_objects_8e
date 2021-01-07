#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main () {
    int var = 66;
    float var2 = 15.2533;
    char var3[] = "abcdefghi"; // An array of char
    std::string var4 = "A String"; // A string

    cout << "Print as decimal integer\n";
    printf("%d\n", var);
    cout << "Print as unsigned decimal integer\n";
    printf("%u\n", var);
    cout << "Print as octal\n";
    printf("%o\n", var);
    cout << "Print as hexidecimal\n";
    printf("%x\n", var);
    cout << "Print as floating\n";
    printf("%f\n", var2);
    cout << "Print as scientific notation\n";
    printf("%e\n", var2);
    cout << "Print as character\n";
    printf("%c\n", var);
    cout << "Print string of characters\n";
    printf("%s\n", var3);
    printf("%s\n", var4);
    cout << "Print as pointer\n";
    printf("%p\n", var);

    // Example of flags
    cout << "Example of flags\n";
    cout << "Justification\n";
    printf("%10d\n", var); // right justify in field width
    printf("%-10d\n", var); // left justify in field width
    // Positive negative indication
    cout << "Negative or positive indication\n";
    printf("%+10d\n", var);
    printf("%+10d\n", var * -1);
    // Precision
    printf("%10.5f\n", var2 * -1);
    printf("%-+10.5f\n", var2);

}