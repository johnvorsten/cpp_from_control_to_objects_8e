#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i = 0;
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
        ++i;
    }
    cout << endl;

    vector<string> msg2 {"I Hope", "I", "Get an A+", "In", "This Class!!"};

    for (const string& word : msg2) // for (define variable type, variable name : in msg)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << msg2[0] << msg2[1] << msg2[2] << "And on and on we go...";

    return 0;
}