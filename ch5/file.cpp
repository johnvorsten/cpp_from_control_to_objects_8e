#include <iostream>
#include <fstream> // ofstream, ifstream, fstream
#include <string>

using namespace std;

int main () {
    // Read and write from files in a basic way
    fstream file;
    string file_path = "./test.txt";
    file.open(file_path, ios::in | ios::out | ios::app);
    
    if (file.is_open())
        cout << "File " << file_path << " was successfully opened" << endl;
    
    // Write to the file
    if (file.is_open()) {
        file << "The bits and bytes come marching down the street" << endl;
        file << "Hide before they find us! Yeet!" << endl;
        file.close();
    }

    // Read from the file
    string line;
    file.open(file_path, ios::in | ios::app);
    if (file.is_open()) {
        while ( getline(file, line)) {
            cout << line << endl;
            // Current position
            cout << "Current position : " << file.tellg() << endl;
        }
        file.close();
    }

    // Begin reading a file from an offset and read x bytes
    // Read the next 10 bytes
    file.open(file_path, ios::in | ios::app);
    int startpos = 10, n_read = 10;
    char * memblock; // read file contents to this location (pointer??)
    if (file.is_open()) {
        // Begin reading at the nth byte
        cout << "Beginning reading file at " << startpos << endl;
        cout << "Read " << n_read << " bytes and print to screen" << endl;
        file.seekg(startpos);
        memblock = new char [1];
        for (int i=0; i < n_read; i++) {
            file.read(memblock, 1);
            cout << *memblock << endl; // This prints the data at the address??
        }
        file.close();
    }
    else cout << "Unable to open file" << endl;

    // Determine size of file
    file.open(file_path, ios::in | ios::app);
    if (file.is_open()) {
        // Find the position of the end of the file
        std::streampos begin, end;
        file.seekg(0, ios::beg);
        begin = file.tellg();
        file.seekg(0, ios::end);
        end = file.tellg();
        file.close();
        cout << "The size of the file is " << (end-begin) << endl;
    }

    delete[] memblock; // Cant leave pointers hanging??

    return 0;
}