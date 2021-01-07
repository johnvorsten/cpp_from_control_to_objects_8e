// for loop
/* Syntax
for ( (initialization expression); (test expression); (update expression)) {
    statement;
    statement;
}
*/
#include <iostream>
#include <string>
#include <vector>
// #include <thread>
// #include <chrono>
// #include <windows.system.threading.core.h>
// #include <synchapi.h> // win32 api threading??
#include <windows.h>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

int main () {
    vector<string> sentence;

    /* initialize counter variable or iterator
    Test counter variable by comparing to maximum. 
        If it is above maximum then terminate
    Update counter each iteration
    */

   cout << "Launching in... " << endl;
   for (int i=5; i > 0; --i) { 
       cout << i << endl;
       Sleep(500);
    //    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // range based for loop
    string str = "Somebody once told me the world is gonna roll me...";
    cout << str << " Let me break this down for you" << endl;
    for (char part : str) {
        cout << part << endl;
    }

    vector<int> v1 {1,2,3,4,5,6,10};
    cout << "Iterating over a vector" << endl;
    for (int x : v1) {
        cout << x << endl;
    }

    // Using break and continue in loops
    // Generate a random vector of numbers
    // If a vector element falls within a range then skip processing
    vector<double> v2;
    int sz = 100;
    cout << "Inital Vector contains " << v2.capacity() << " elements." << endl;
    // Creating random numbers is not trivial in CPP
    // First create a generator object - this generates uniformly distributed
    // Numbers - https://www.cplusplus.com/reference/random/
    // Other generators - linear_congruential_engine, mersenne_twister_engine, sutract_with_carry_engine;
    // default_random_engine, minstd_rand, minstd_rand0, mt19937, mt19937_64, ranlux24_base, ranlux48_base, ranlux24, ranlux48, knuth_b
    
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(1.0,100.0);
    for (int i=0; i < sz; i++) {
        v2.push_back(distribution(generator));
    }

    int n_5 = 0;
    int n_10 = 0;
    const int jackpot = 99;
    for (double x : v2) {
        if (x < 5) { 
            std::cout << "A value is less than 5\n"; 
            n_5++; 
            std::cout << "Total number of less than 5 : " << n_5 << endl; 
            }
        if (x < 10) { 
            std::cout << "A value is less than 10\n"; 
            n_10++; 
            std::cout << "Total number of less than 10 : " << n_10 << endl;}
        if (x > 99) { 
            std:cout << "You won the jackpot! (Greater than 99)\n\n";
            break;
        }
    }
    
    std::random_device rnd_device;
    mt19937 mersenne_engine {rnd_device()}; // Generate random integers

    return 0;
}