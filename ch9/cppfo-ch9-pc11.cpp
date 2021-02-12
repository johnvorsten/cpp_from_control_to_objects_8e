/*9.11: Array Expander
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a new array that is twice the size of the argument 
array. The function should copy the contents of the argument array to the new 
array, and initialize the unused elements of the second array with 0. The 
function should return a pointer to the new array. Demonstrate the function 
by using it in a main program that reads an integer N  (that is not more 
than 50) from standard input and then reads N  integers from a file named 
data  into an array. The program then passes the array to your array expander 
function, and prints the values of the new expanded array on standard output, 
one value per line. You may assume that the file data  has at least N  values. */
#include <string>
#include <iostream>
#include <exception>
#include <fstream>

using namespace std;

int* double_size_arr(int* arr, int size) {
    int* new_array = nullptr;
    new_array = new int[size*2]{0};

    for (int i=0; i<size; i++) {
        new_array[i] = arr[i];
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

    auto new_array = double_size_arr(arr, n);
    print_array(new_array, n*2);

    return 0;
}