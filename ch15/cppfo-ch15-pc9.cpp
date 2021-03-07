/*15.9:
=====

A file filter reads an input file, transforms it in some way, and writes
the result to an output file. Write an abstact Filter class that defines
a pure virtual function char transform(char ch) for transforming a single
character. The Filter class should have member variables to hold the input and
output streams; it also should have a default constructor that initializes the
input/output streams to cin/cout respectively as well as a constructor that
accepts initialized input/output file streams and uses them to initialize the
Filter object. The Filter class will also have a member function void
doFilter() that will use the char transform(char ch) virtual function to do
the filtering.
Using your Filter class, create one derived class that performs encryption
using ROT13 algorithm (explained below), another that transforms a file to all
uppercase, and another that creates an unchanged copy of the original file.
Write the main function that would open the file named "input.txt" and
then use the three file filters to create 3 new files: input.txt_copy for the
copy filter, input.txt_encr for the encryption filter, and input.txt_upper for
the uppercase filter.

ROT13:
------

ROT13 stands for "rotate by 13 places" and is a simple cipher based on
substitution. To encrypt or decrypt using ROT13, each letter of the alphabet
is replaced by a letter that is 13 places further along the alphabet. For
example, A becomes N and M becomes Z; similarly, N becomes A and Z becomes M.
Only letters (both upper and lowercase) are affected by this algorithm;
i.e. spaces, punctuation marks, digits and special characters are unchanged.
*/

#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

namespace ffilt {

class FileTransformBase {
    public:
    // std::ifstream infile;
    // std::ofstream outfile;
    std::string infile_name;
    std::string outfile_name;

    FileTransformBase(std::string input_file_name, std::string output_file_name) : 
        infile_name(input_file_name), outfile_name(output_file_name) {
        }

    FileTransformBase() {
    }

    ~FileTransformBase() {
    }

};


class FileTransformROT13 : public FileTransformBase {

    public:
    template <typename CallbackFunction>
    void do_transform(std::string infile_name, std::string outfile_name, CallbackFunction&& callback) {
        // The only purpose of this is to reduce boilerplate
        std::ifstream infile(infile_name);
        std::ofstream outfile(outfile_name);

        // Call the function specified by the caller
        if (infile.is_open() && outfile.is_open()) {
            callback(outfile, infile);
        }
        else {
            std::cout << "Could not open file" << std::endl;
        }

        // Close the file when finished
        infile.close();
        outfile.close();

    }

    static void transform_uppercase(std::ofstream& outfile, std::ifstream& infile) {
        std::string line;
        std::string upper;

        if (!infile.is_open()) {
            std::cout << "Could not open file" << std::endl;
        }
        else {
            while (std::getline(infile, line)) {
                std::transform(line.begin(), line.end(), line.begin(), ::toupper);
                outfile.write(line.c_str(), line.length());
                outfile.write("\n", 1);
            }
        }

    }

    static char transform_character_ROT13(char ch) {
        char temp = 0;

        // Uppercase characters 65-90
        if (ch >= 65 && ch <= 90) {
            temp = ch + 13;
            if (temp > 90) 
                return (temp - 90 + 64);
            else
                return temp;
        }

        // Lowercase 97-122
        else if (ch >= 97 && ch <= 122) {

            if (ch > 109) // Loop around
                return (96 + (ch + 13 - 122));
            else // We are within range
                return ch + 13;
        }

        else {
            return ch;
        }

        return ch;
    }

    static void transform_ROT13(std::ofstream& outfile, std::ifstream& infile) {
        std::string line;
        char res;

        if (!infile.is_open()) {
            std::cout << "Cannot open file" << std::endl;
        }
        else {
            while (std::getline(infile, line)) {
                for (auto& ch : line) {
                    res = transform_character_ROT13(ch);
                    outfile << res;
                }
                outfile.write("\n", 1);
            }
        }
    }

    static void unchanged(std::ofstream& outfile, std::ifstream& infile) {
        std::string line;

        if (!infile.is_open()) {
            std::cout << "File failed to open";
        }
        else {
            // Copy the input file contents to the output file contents
            while (std::getline(infile, line)) {
                outfile.write(line.c_str(), line.length());
                outfile.write("\n", 1);
            }
        }

    }

};


};

using namespace std;


int main () {

    // // Create input file class if it is not already
    // string str{"I'm ready to be finished with this pearson assignment.\n"
    //     "I really don't think I have travelled down a path this is useful anymore."
    //     "The original assignment was about.. what?? Polymorphism, virtual functions, ABC, multiple inheritance"};
    // fstream ifile("./input.txt", ios::out);

    // if (ifile.is_open()) {
    //     ifile << str;
    //     ifile.write(str.c_str(), str.length());
    // }
    // ifile.close();

    // ifile.open("./input.txt", ios::in);
    // if (ifile.is_open()) {
    //     std::getline(ifile, str);
    //     std::cout << str;
    // }
    // ifile.close();


    // Initialize filter class
    ffilt::FileTransformROT13 FileTransformer;
    string input_file = "./input.txt";
    string output_file_copy = "./input.txt_copy";
    string output_file_upper = "./input.txt_upper";
    string output_file_encr = "./input.txt_encr";

    // Testing character rotation
    // auto res = FileTransformer.transform_character_ROT13('a');
    // res = FileTransformer.transform_character_ROT13('m');
    // res = FileTransformer.transform_character_ROT13('n');
    // res = FileTransformer.transform_character_ROT13('z');
    // res = FileTransformer.transform_character_ROT13('A'); 
    // res = FileTransformer.transform_character_ROT13('M');
    // res = FileTransformer.transform_character_ROT13('N');
    // res = FileTransformer.transform_character_ROT13('Z');

    
    // Filter and create three new files
    FileTransformer.do_transform(input_file, output_file_copy, FileTransformer.unchanged);
    FileTransformer.do_transform(input_file, output_file_upper, FileTransformer.transform_uppercase);
    FileTransformer.do_transform(input_file, output_file_encr, FileTransformer.transform_ROT13);


    return 0;
}