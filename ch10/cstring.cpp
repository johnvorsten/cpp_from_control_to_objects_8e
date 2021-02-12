#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main () {
    // Define a character array
    char str[10] = {'a','b','c','d','E','F','g','h','I'};

    if (isupper(str[0]))
        std::cout << "The string is upper case\n";
    else
        std::cout << "The string is lower case\n";

    if (isupper(str[4])) // 'E'
        std::cout << "The string is upper case\n";
    else
        std::cout << "The string is lower case\n";


    {/*Various CString functions*/
    char name[] = "Vohn Jorsten";
    int length;
    length = strlen(name);
    length = strlen(*(&name));
    length = strlen("Something else");

    // strcat
    char str1[25] = "Mister";
    char str2[] = "Roboto";
    strcat(str1, str2);
    std::cout << "Result of strcat : " << str1;

    // strcpy
    const int SIZE = 10;
    char string1[SIZE] = "Hello", string2[SIZE] = "World!"; 
    cout << string1 << endl;    // Hello
    cout << string2 << endl;    // World
    strcpy(string1, string2);   // World
    cout << string1 << endl;    // World
    cout << string2 << endl;    // World

    // strstr - search for function inside of string
    char song[] = "Somebody once told me the world is gonna...";
    char *ptr = nullptr;
    cout << song << endl;
    ptr = strstr(song, "once"); // Search
    std::cout << ptr << endl;

    // Strcmp - compare two strings
    if (strcmp(str1 ,str2)) {
        printf("The strings | %s %s | are equal\n\n", str1, str2);
    }
    else {
        printf("The strings | %s %s | are not equal\n\n", str1, str2);
    }

    if (strcmp("String1" , "String1")) {
        printf("The strings | %s %s | are equal\n\n", "String1", "String1");
    }
    else {
        printf("The strings | %s %s | are not equal\n\n", "String1", "String1");
    }
    } // End block


    {/*Section 10.5 - Numeric conversion functions*/
        string word = "dracula";
        string drWord = word.substr(word.find("dr"), word.find("dr") + 4);
        word = "George slew the dragon";
        drWord = word.substr(word.find("dr"), word.find("dr") + 4);
        auto x = word.find("dr");
        x = word.find("dr") + 4;

        
    }

    {
    string sentence =  "Broccoli is delicious.";
    string secondWord;
    auto start = sentence.find(" ");
    auto end = sentence.find(" ", start+1);

    secondWord = sentence.substr(start+1, end-start-1);
}

    return 0;
}