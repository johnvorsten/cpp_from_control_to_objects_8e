// On paper, write a program that will display your name on 
// the first line, your street address on the second line, 
// your city, state, and ZIP code on the third line, and your 
// telephone number on the fourth line. Place a comment with 
// today’s date at the top of the program. Test your program by 
// entering, compiling, and running it.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"John Vorsten","1234 Happy Ways Ln.", "Houston, TX 77837", "553-234-3244"};
    cout << msg[0] << endl;
    cout << msg[1] << endl;
    cout << msg[2] << endl;
    cout << msg[3] << endl;
    return 0;
}