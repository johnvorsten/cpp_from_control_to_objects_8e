#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

template <typename k, typename v>
int map_get(map<k, v>& mmap, const k& key, const v& def) {
    std::map<char,int>::const_iterator it = mmap.find( key );
    if (it == mmap.end()) 
        return def;
    else
        return it->second;
}
 
int vowel_counter(const char* str, int size) {
    /*Count the number of vowels in a string*/
    int n_vowel = 0;

    n_vowel += std::count(str, str+size, 'a');
    n_vowel += std::count(str, str+size, 'e');
    n_vowel += std::count(str, str+size, 'i');
    n_vowel += std::count(str, str+size, 'o');
    n_vowel += std::count(str, str+size, 'u');  
    n_vowel += std::count(str, str+size, 'y');

    return n_vowel;
}

int constant_counter(const char* str, int size) {
    int n_consonants = 0;
    map<char, int> letter_map;

    for (int i=0; i<size; i++) {
        letter_map[str[i]] += 1;
    }

    n_consonants += map_get(letter_map, 'a', 0);
    n_consonants += map_get(letter_map, 'b', 0);
    n_consonants += map_get(letter_map, 'c', 0);
    n_consonants += map_get(letter_map, 'd', 0);
    n_consonants += map_get(letter_map, 'f', 0);
    n_consonants += map_get(letter_map, 'g', 0);
    n_consonants += map_get(letter_map, 'h', 0);
    n_consonants += map_get(letter_map, 'j', 0);
    n_consonants += map_get(letter_map, 'k', 0);
    n_consonants += map_get(letter_map, 'l', 0);
    n_consonants += map_get(letter_map, 'm', 0);
    n_consonants += map_get(letter_map, 'n', 0);
    n_consonants += map_get(letter_map, 'p', 0);
    n_consonants += map_get(letter_map, 'q', 0);
    n_consonants += map_get(letter_map, 'r', 0);
    n_consonants += map_get(letter_map, 's', 0);
    n_consonants += map_get(letter_map, 't', 0);
    n_consonants += map_get(letter_map, 'v', 0);
    n_consonants += map_get(letter_map, 'w', 0);
    n_consonants += map_get(letter_map, 'x', 0);
    n_consonants += map_get(letter_map, 'z', 0);
    
    return n_consonants;
}

enum choices {vowels, consonants, both, again, exitt};

struct user_inputs {

    public:
        string sentence;
        choices choice;
};

user_inputs user_input() {
    string str;
    string choice;
    user_inputs m_user_inputs;

    std::cout << "Enter a sentence: " << endl;
    std::getline(std::cin, str);
    std::cout << "Choose an option: " << endl;
    std::cout << "A) count the number of vowels\n"
                "B) Count the number of consonants\n"
                "C) Count both vowels and consonants\n"
                "D) Enter another string\n"
                "E) Exit program\n" << endl;
    std::getline(std::cin, choice);

    m_user_inputs.sentence = str;
    if (choice == "A")
        m_user_inputs.choice = vowels;
    else if (choice == "B")
        m_user_inputs.choice = consonants;
    else if (choice == "C")
        m_user_inputs.choice = both;
    else if (choice == "D")
        m_user_inputs.choice = again;
    else if (choice == "E")
        m_user_inputs.choice = exitt;
    else {
        std::cout << "You must enter one of {A,B,C,D,E}" << endl;
        m_user_inputs = user_input();
    }

    return m_user_inputs;
}



int main () {

    user_inputs result;
    // result.sentence = "This is a test sentence";
    // result.choice = both;
    int n_vowels;
    int n_consonants;

    do {
    result = user_input();
    switch (result.choice) {
        case vowels:
            // vowels
            n_vowels = vowel_counter(result.sentence.c_str(), result.sentence.size());
            std::cout << "There are " << n_vowels << " vowels in the sentence" << endl;
            break;

        case consonants:
            // consonants
            n_consonants = constant_counter(result.sentence.c_str(), result.sentence.size());
            std::cout << "There are " << n_consonants << " consonants in the sentence" << endl;
            break;

        case both:
            // both
            n_vowels = vowel_counter(result.sentence.c_str(), result.sentence.size());
            n_consonants = constant_counter(result.sentence.c_str(), result.sentence.size());
            std::cout << "There are " << n_vowels << " vowels in the sentence" << endl;
            std::cout << "There are " << n_consonants << " consonants in the sentence" << endl;
            break;

        case again:
            // Enter another string
            break;

        case exitt:
            // Exit
            return 0;
            break;
    }
    } while (result.choice == again || result.choice > 5);


    return 0;
}