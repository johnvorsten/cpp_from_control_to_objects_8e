#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
void string_sort(string [], int);
void display_data(string [], int);
void read_file(string, string*, int);

int main()
{


    // Test the function with a driver program that reads an integer, N, 
    //from standard input and then reads the first N strings from a file called names
    int N = 0;
    std::cout << "Enter number of names to read: ";
    std::cin >> N;
    // string names[] = {"Amelia", "aa","bb","cc","dd","123","ggadksajfl","fda"};
    string names[N];
    read_file("./names", names, N);

    //call sorting function
    display_data(names, N);

    //call function to display data
    display_data(names, N);

    return 0;
}

void string_sort(string names[], int arraySize){
    //will sort in ASCENDING order

    //declare variables to start from beginning of array
    //and to store the temporary min name and index
    int startScan, minIndex;
    string minName;

    //begin looping on all elements until second to last
    for(startScan = 0; startScan < arraySize-1; startScan++){
        //initialize minValue and minIndex to first element
        minName = names[startScan];
        minIndex = startScan;
        //loop on all remaining elements of array
        for(int index = startScan+1; index < arraySize; index++){
            //check if current string element is less than current minValue
            if(names[index] < minName){
                //update minValue and minIndex to
                //respective values of current element
                minName = names[index];
                minIndex = index;
            }
        } //inner for loop ends here
        //put the current [startScan] element to its final position
        names[minIndex] = names[startScan];
        //put lowest value first
        names[startScan] = minName;
    }
}

void display_data(string names[], int arraySize){
    for(int counter = 0; counter < arraySize; counter++)
        cout << names[counter] << endl;
}

void read_file(string filename, string* container, int n_lines) {
    /*Read the first n_lines from a file into a string container*/
    string line;

    // Read line by line from a file and store in a string array
    fstream name_file;
    name_file.open(filename);
    if (name_file.is_open()) {
        for (int i=0; i < n_lines; i++) {
            getline(name_file, line);
            container[i] = line;
        }
    }
    else {
        std::cout << "Error opening names" << endl;
    }
    name_file.close();

}