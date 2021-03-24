#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int word_counter(const char* str, int size) {
    int n_words = 0;

    for (int i=0; i<size; i++) {
        if (str[i] == ' ') {
            n_words++;
        }
    }
    return n_words;
}


string user_input() {
    string str;
    std::cout << "Enter a sentence: " << endl;
    std::getline(std::cin, str);
    return str;
}


int main () {

    auto str = user_input();
    // string str;
    // str = "This is a test sentence";
    auto count = word_counter(str.c_str(), str.size());
    std::cout << "The sentence has " << count << " words" << endl;

    std::cout << "Press enter to continue...";
    // NOTE - anything on standard input is ignored, but the program will hang until it receives \n
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

    return 0;
}