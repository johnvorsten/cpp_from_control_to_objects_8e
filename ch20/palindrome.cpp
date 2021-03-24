#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Function declartions
bool isPalindrome(string& palindrome, std::string::iterator it_start, std::string::iterator it_end){
    /*Determine if a function is a palindrome through recursion*/
    bool res = false;
    // End Iterators of strings start at null termination \0
    if (*it_end == '\0')
        --it_end;

    // Stop condition
    // If the value pointed to by iterator do not equal each other
    if (tolower(static_cast<unsigned char>(*it_start)) != tolower(static_cast<unsigned char>(*it_end))) {
        return false;
    }

    // If the iterator is at the middle of the container and
    // we made it this far then true
    else if (it_start >= it_end) {
        return true;
    }

    // Else we recursively loop until the return condition is met
    else {
        // Fix the way these are passed to the function..
        res = isPalindrome(palindrome, ++it_start, --it_end);
    }
    
    return res; // Return the result of the recursion
};

bool isPalindrome(string s) {
    auto res = isPalindrome(s, s.begin(), s.end());
    return res;
}


string user_input() {
    string input;
    std::cout << "Enter a palindrome : ";
    std::cin >> input;
    return input;
}

int main () {

    // Data declarations - Palindromes
    vector<string> palindromes = {"Poop","Civic",
    "Anna", "Civic",
    "Kayak", "Level",
    "Madam", "Mom", 
    "Noon", "Racecar", 
    "Radar", "Redder", 
    "Refer", "Repaper", 
    "Rotator","xegera1s2eefdaadfee2s1aRegex",
    "XXPussySlayerreyalSyssuPXX", "++AnAevreseDIIDeserveAnA++"};
    

    vector<string> non_palindromes = {"Some", "other",
    "words","It", 
    "irrelevant","What",
    "They","are",
    "21561gdakny48"""};

    for (auto& palindrome : palindromes) {
        assert(isPalindrome(palindrome, palindrome.begin(), palindrome.end()));
        // std::cout << palindrome << " is a palindrome" << endl;
    }

    for(auto& non_palindrome : non_palindromes) {
        assert(!isPalindrome(non_palindrome, non_palindrome.begin(), non_palindrome.end()));
        // std::cout << non_palindrome << " is NOT a palindrome" << endl;
    }

    string exit_command;
    while (true) {
        auto test = user_input();
        auto res = isPalindrome(test, test.begin(), test.end());
        if (res)
            std::cout << "The string you entered <" << test << "> is a palindrome" << endl;
        else
            std::cout << "The string you entered <" << test << "> is ~NOT~ a palindrome" << endl;

        std::cout << "Enter 'q' to exit" << endl;
        std::cin >> exit_command; // How do determine if the user presses enter only??
        if (exit_command == "q") 
            break;
        else
            continue;
    }

    return 0;
}
