#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

std::map<char, std::string> morse_map;
// {
//     {" ", "space"},{",","--..--"},{".",".-.-.-"},{"?","..--.."},{"0","-----"},
//     {"1", ".----"},{"2","..---"},{"3","...--"},{"4","....-"},{"5","....."},
//     {"6", "-.... "},{"7","--... "},{"8","---.. "},{"9","----. "},{"A",".-"},
//     {"B", "-... "},{"C","-.-. "},{"D","-.."},{"E","."},{"F","..-."},
//     {"G", "--."},{"H","...."},{"I",".."},{"J",".---"},{"K","-.-"},
//     {"L", ".-.."},{"M","--"},{"N","-."},{"O","---"},{"P",".--."},
//     {"Q", "--.-"},{"R",".-."},{"S","..."},{"T","-"},{"U","..-"},
//     {"V", "...-"},{"W",".--"},{"X","-..-"},{"Y","-.--"},{"Z","--.."},
// };

void load_morse_map() {
morse_map[' '] = " ";
morse_map['0'] = "-----";
morse_map['1'] = ".----";
morse_map['2'] = "..---";
morse_map['3'] = "...--";
morse_map['4'] = "....-";
morse_map['5'] = ".....";
morse_map['6'] = "-....";
morse_map['7'] = "--...";
morse_map['8'] = "---..";
morse_map['9'] = "----.";
morse_map['a'] = ".-";
morse_map['b'] = "-...";
morse_map['c'] = "-.-.";
morse_map['d'] = "-..";
morse_map['e'] = ".";
morse_map['f'] = "..-.";
morse_map['g'] = "--.";
morse_map['h'] = "....";
morse_map['i'] = "..";
morse_map['j'] = ".---";
morse_map['k'] = "-.-";
morse_map['l'] = ".-..";
morse_map['m'] = "--";
morse_map['n'] = "-.";
morse_map['o'] = "---";
morse_map['p'] = ".--.";
morse_map['q'] = "--.-";
morse_map['r'] = ".-.";
morse_map['s'] = "...";
morse_map['t'] = "-";
morse_map['u'] = "..-";
morse_map['v'] = "...-";
morse_map['w'] = ".--";
morse_map['x'] = "-..-";
morse_map['y'] = "-.--";
morse_map['z'] = "--..";
morse_map['?'] = "..--..";
}


class MorseMapper {

    public:

        vector<string> translate(string str) {
            std::vector<string> translation;

            for (auto& x : str) {
                translation.push_back( morse_map[std::tolower(x)] );
            }

            return translation;
        }

        void print_morse(vector<string> morse_vector) {
            for (auto& str : morse_vector) {
                std::cout << str << endl;
            }
        }

        string user_input() {
            string str_input;
            std::cout << "Enter a word and I will translate it to Morse code: ";
            std::getline(std::cin, str_input);
            return str_input;
        }
};

int main () {

    load_morse_map();
    MorseMapper mapper;
    auto user_input = mapper.user_input();
    auto res = mapper.translate(user_input);
    mapper.print_morse(res);

    return 0;
}