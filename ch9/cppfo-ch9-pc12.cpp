/*9.12: Element Shifter
Write a function that accepts an int array and the array’s 
size as arguments. The function should create a new array 
that is one element larger than the argument array. The first 
element of the new array should be set to 0. Element 0 of the 
argument array should be copied to element 1 of the new array,
 element 1 of the argument array should be copied to element 
 2 of the new array, and so forth. The function should return 
 a pointer to the new array. Demonstrate the function by using 
 it in a main program that reads an integer N  (that is not more than 50)
  from standard input and then reads N  integers from a file named data 
   into an array. The program then passes the array to your element shifter 
   function, and prints the values of the new expanded and shifted array 
   on standard output, one value per line. You may assume that the file data
     has at least N  values. */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* f_new_array(int* arr, int size) {
    int* new_array = nullptr;
    new_array = new int[size + 1]{0};

    for (int i=1; i < size + 1; i++) {
        new_array[i] = arr[i-1];
    }
    return new_array;
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

    // int n = 0;
    auto n = read_n();
    // n = 3;

    int* arr = nullptr;
    string filename = "data";
    arr = read_file(filename, n);

    auto new_array = f_new_array(arr, n);
    print_array(new_array, n+1);

    return 0;
}