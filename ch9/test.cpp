#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;



void open_file() {

    string line;
    ifstream myfile ("ch9/data.txt");
    if (myfile.is_open())
    {
      while ( myfile.good() )
      {
        getline (myfile,line);
        cout << line << endl;
      }
      myfile.close();
      }
      else cout << "Unable to open file"; 

}

int main () {

  {
    /*Declare an array
    Is an address operator needed to assign an array's address to a pointer?*/
    int* array = nullptr;
    array = new int[10]; // This works

  /*Can I use the delete operator with a pointer not used with a enw operator??*/
  int* test_pointer = nullptr;
  int* test_array_ptr = array;
  delete test_pointer;
  delete test_array_ptr;

  std::cout << array[5];
  std::cout << *(array + 5);

  /*An array name is a pointer constant because the address stored 
  in it cannot be changed at runtime. */
  std::cout << "\n\n";
  std::cout << array[0] << endl;
  std::cout << array << endl;
  array += 1;
  std::cout << array[0] << endl;
  std::cout << array << endl;
  std::cout << "\n\n";

  unique_ptr<int> uniq(new int);
  int* integer_ptr = nullptr;
  //integer_ptr = 12345; // Does not work

  // Arrays
  // delete array;
  delete [] array;
  


  }


  return 0;
}