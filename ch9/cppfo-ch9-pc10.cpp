/*9.10: Reverse Array
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a copy of the array, except that the element values 
should be reversed in the copy. The function should return a pointer to the 
new array. Demonstrate the function by using it in a main program that reads 
an integer N  (that is not more than 50) from standard input and then reads 
N  integers from a file named data into an array. The program then passes 
the array to the your reverse array function, and prints the values of the 
new reversed array on standard output, one value per line. You may assume 
that the file data  has at least N  values.

Prompts And Output Labels. There are no prompts for the integer and no 
labels for the reversed array that is printed out.

Input Validation. If the integer read in from standard input exceeds 
50 or is less than 0 the program terminates silently. */

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

// Function definitions
int* reverse_array(int* arr, int size) {
    int* new_arr = nullptr;
    new_arr = new int[size];

    for (int i = 0; i < size; i++) {
        new_arr[i] = (arr[size - i - 1]);
    }

    return new_arr;
}

int read_n() {
    int n = 0;
    std::cin >> n;
    return n;
}

int* read_file(string file_name, int n) {

    int* arr = nullptr;
    int val = 0;
    arr = new int[n];
    string line;

    ifstream myfile(file_name);
    // myfile.open(file_name, ios::in);
    if (myfile.is_open()) {
        int count = 0;
        while (count < n && myfile >> val) {
            arr[count] = val;
            // std::cout << val;
            count++;
        }

        // for (int i=0; i<n; i++) {
        //     // arr[i] = myfile.getline();
        //     myfile >> val;
        //     arr[i] = val;
        //     std::cout << val << " ";
        //     // std::cout << arr[i] << " ";
        //     getline(myfile, line);
        //     std::cout << line << " ";
        //     // getline(myfile, arr[i]);
        // }
    }
    else {
        throw std::runtime_error("Unable to open file");
    }

    return arr;
}

void print_array(int* arr, int size) {
    for (int i=0; i<size; i++) {
         std::cout << arr[i] << endl;
    }
    // std::cout << endl;
}

int main () {
    int n = 0;
    n = read_n();
    // n = 3;

    int* arr = nullptr;
    string filename = "data";
    arr = read_file(filename, n);

    auto new_array = reverse_array(arr, n);
    print_array(new_array, n);

    return 0;
}