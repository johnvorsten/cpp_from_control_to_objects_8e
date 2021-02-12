/*10.15: Character Analysis
Write a program that reads the contents of a file named text.txt and 
determines the following:

    The number of uppercase letters in the file
    The number of lowercase letters in the file
    The number of digits in the file

Prompts And Output Labels. There are no prompts-- nothing is read 
from standard in, just from the file text.txt. Each of the numbers
 calculated is displayed on a separate line on standard output,
  preceded by the following prompts (respectively): "Uppercase 
  characters: ", "Lowercase characters: ", "Digits: ".

Input Validation. None. */


#include <fstream>
#include <regex>
#include <string>
#include <iostream>

using namespace std;

// Class definitions
class DigitCounter{
    public:
        int n_digits = 0;
        int n_uppercase = 0;
        int n_lowercase = 0;

        std::regex digits_regex;
        std::regex uppercase_regex;
        std::regex lowercase_regex;

        DigitCounter() : digits_regex("[0-9]{1}"), 
                        uppercase_regex("[A-Z]{1}"),
                        lowercase_regex("[a-z]{1}")
                        {}


        void count_file(std::string filename) {
            // Read file line by line
            std::string line;
            std::ifstream mfile(filename);
            std::smatch match;
            while(std::getline(mfile, line)) {
                for (auto& x : line) {
                    // Search digits
                    // std::regex_search(x, match, digits_regex);
                    if (isdigit(x))
                        // n_digits += match.size();
                        n_digits += 1;
                    // Search uppercase letters
                    // std::regex_search(x, match, uppercase_regex);
                    if (isupper(x))
                        n_uppercase += 1;
                        // n_uppercase += match.size();
                    // Search lowercase letters
                    // std::regex_search(x, match, lowercase_regex);
                    if (islower(x))
                        // n_lowercase += match.size();
                        n_lowercase += 1;
                }

            }

            // Read character by character of each line

            
        }

    private:

};

int main () {

    string filename = "./text.txt";
    DigitCounter counter;
    counter.count_file(filename);

    std::cout << "Uppercase characters: " << counter.n_uppercase << endl;
    std::cout << "Lowercase characters: " << counter.n_lowercase << endl;
    std::cout << "Digits: " << counter.n_digits << endl;

    return 0;
}