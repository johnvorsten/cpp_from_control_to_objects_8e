#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Function declartions
bool isPalindrome(string& palindrome, std::string::iterator it_start, std::string::iterator it_end){
    /*Determine if a function is a palindrome through recursion*/
    auto len = palindrome.size();
    std::string::iterator it_middle;
    bool res = false;
    // End Iterators of strings start at null termination \0
    if (*it_end == '\0')
        --it_end;

    if (len % 2 == 0) // Even length string
        it_middle = it_start + ((len / 2) - 1);
    else // Odd
        it_middle = it_start + (len / 2);

    // Stop condition
    // If the value pointed to by iterator do not equal each other
    if (tolower(static_cast<unsigned char>(*it_start)) != tolower(static_cast<unsigned char>(*it_end))) {
        return false;
    }

    // If the iterator is at the middle of the container and
    // we made it this far then true
    else if (it_start >= it_middle) {
        return true;
    }

    // Else we recursively loop until the return condition is met
    else {
        // Fix the way these are passed to the function..
        res = isPalindrome(palindrome, ++it_start, --it_end);
    }
    
    return res; // Return the result of the recursion
};


int main () {

    // Data declarations - Palindromes
    vector<string> palindromes = {"Poop","Civic",
    "Anna", "Civic",
    "Kayak", "Level",
    "Madam", "Mom", 
    "Noon", "Racecar", 
    "Radar", "Redder", 
    "Refer", "Repaper", 
    "Rotator",};

    std::cout << *(palindromes[0].rbegin());

    vector<string> non_palandromes = {"Some", "other",
    "words","It", 
    "irrelevant","What",
    "They","are",
    "21561gdakny48"""};

    for (auto& palindrome : palindromes) {
        assert(isPalindrome(palindrome, palindrome.begin(), palindrome.end()));
    }



    return 0;
}
