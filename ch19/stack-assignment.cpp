/*Write a function that takes a string parameter and determines whether the string 
contains matching grouping symbols. Grouping symbols are parenthesis ( ) , 
brackets [] and curly braces { }.  For example, the string  {a(b+ac)d[xy]g} 
and  kab*cd contain matching grouping symbols. However, the 
strings ac)cd(e(k,  xy{za(dx)k, and {a(b+ac}d) do not contain matching 
grouping symbols.  (Note: open and closed grouping symbols have to match 
both in number and in the order they occur in the string).

Your function must use a stack data structure to determine whether the 
string parameter satisfies the condition described above. You may define 
your own stack class or use the STL stack class.

Write a driver program (i.e. a function main()) to test your function.

Deliverables:

1. a copy of your function and the test 
driver program source codes in a text file (e.g. a .cpp file)

2. screen shots of your test driver program 
runs showing it meets the problem's specifications.*/

#include <iostream>
#include <stack>
#include "dynstack.hpp"
#include <cassert>
#include <initializer_list>
// #include <ranges> // :*( MinGW

using namespace std;
bool MATCHING_DEBUG = true;


// Function definitions
template <typename T>
bool list_contains(T& test, std::initializer_list<T> items) {
    for (auto& item : items) {
        if (test == item)
            return true;
    }

    return false;
}


char paired_symbol(char& test) {
    /* Return the matching symmetric grouping symbol
    Grouping symbols are (), [], {}. This function will return the
    symmetric grouping symbol */
    if (test == '(') {
        return ')';
    }
    else if (test == ')') {
        return '(';
    }
    else if (test == '[') {
        return ']';
    }
    else if (test == ']') {
        return '[';
    }
    else if (test == '{') {
        return '}';
    }
    else if (test == '}') {
        return '{';
    }

    throw std::logic_error("Function argument must be one of {'(', '[', '{', '}', ']', ')'}");
}


bool matching_group(string str) {
    /*Return true if the string str contains matching grouping symbols
    Grouping symbols include (), [], {}
    The symbols must match in order and number that occur in the string
    Rigorous specification:
    1. Grouping symbols include (), {}, []
    2. Grouping symbols CAN envelope other grouping symbols - ([{}]) is valid
    3. Groups cannot overlap. ([{})]} is invalid
    4. The grouping can contain any number of other characters between opening and closing
    5. Groups MUST be paired. Grouping symbols that do not have
        a pair will NOT pass the test
        Example: (abc{defg} fails the test
    6. Non-symmetric groups are valid. Example {[]()}

    inputs
    ------
    str : (string) string of any characters
    outputs
    ------
    boolean if the above conditions are satisfied
    */

    // Debugging
    if (MATCHING_DEBUG) {
        std::cout << "Beginning " << __func__ << " with arguments: " << str << endl;
    }

    DynamicStack<char> stak;
    std::initializer_list<char> group_symbols = {'(', '[', '{', '}', ']', ')'};

    // Iterate through the string and insert matching elements onto a stack
    for (std::string::reverse_iterator rit = str.rbegin(); rit!=str.rend(); ++rit) {
        char character = *rit;
        if (list_contains(character, group_symbols)) {
            stak.push(character);
        }
    }

    /* Negative test (Automatic failure) */
    // A stack with an odd number of elements automatically fails (Non-paired group)
    if ((stak.get_length() % 2) != 0) {
        if (MATCHING_DEBUG) {
            std::cout << "Fail: string has an odd number of grouping symbols (non-paired group)" << "\n\n";
        }
        return false;
    }
    /* Positive test (Automatic pass) */
    // An empty stack automatically passes (no grouping symbols)
    if (stak.is_empty()) {
        if (MATCHING_DEBUG) {
            std::cout << "Pass: string has no grouping symbols (text only)" << "\n\n";
        }
        return true;
    }

    /* Positive test (Conditional pass) 
    Example stack contents: {'(', '{', '}', '[', ']', ')'} */
    while (!stak.is_empty()) {
        // 1. Pop an element
        auto element = stak.pop(); // '('
        // {'{', '}', '[', ']', ')'}

        if (list_contains(element, {')', ']', '}'})) {
            // Because of the structure of this loop and the stack
            // It is a negative condition to encounter a closing 
            // grouping symbol at the beginning of test phase
            if (MATCHING_DEBUG) {
                std::cout << "Fail: string has backwards facing grouping symbol (unpaired)" << "\n\n";
            }
            return false;
        }
        
        if (paired_symbol(element) == stak.peek_back()) {
            // 2. See if the back element matches
            // Remove the back matching element
            stak.pop_back();
            // {'{', '}', '[', ']'}
        }
        else if (paired_symbol(element) == stak.peek_front()) {
            // 3. Test if the next element matches otherwise
            // Remove the next matching element
            stak.pop();
        }
        else {
            // 4. else fail
            if (MATCHING_DEBUG) {
                std::cout << "Fail: grouping symbols are unpaired or overlapping (unpaired/overlapping)" << "\n\n";
            }
            return false;
        }
    }

    // We made it :)
    if (MATCHING_DEBUG) {
        std::cout << "Pass: all requirements met" << "\n\n";
    }
    return true;
}


void test_dynamic_stack() {
    std::cout << "Beginning " << __func__ << endl;

    { /* Test initialization, push, pop, push back, pop back operations */
    std::cout << "Initializing stack {1,2,3,4,5}" << endl;
    // Initialization
    DynamicStack<int> dstack{1,2,3,4,5};
    std::cout << dstack;

    // Push
    std::cout << "Pushing item to top: " << endl;
    dstack.push(10);
    std::cout << dstack;
    
    // Pop
    auto res = dstack.pop();
    std::cout << "Popping item from top: " << endl;
    std::cout << dstack;
    assert (res == 10);
    res = dstack.pop();
    std::cout << "Popping item from top: " << endl;
    std::cout << dstack;
    assert (res == 5);

    // Push back
    std::cout << "Pushing item to back: " << endl;
    dstack.push_back(6);
    std::cout << dstack;
    std::cout << "Pushing item to back: " << endl;
    dstack.push_back(7);
    std::cout << dstack;

    // Pop back
    std::cout << "Popping item from back: " << endl;
    res = dstack.pop_back();
    std::cout << dstack;
    assert (res == 7);
    std::cout << "Popping item from back: " << endl;
    res = dstack.pop_back();
    std::cout << dstack;
    assert (res == 6);
    }; // End block

    { /**/
    // Peek
    DynamicStack<int> dstack{1,2,3,4,5};
    assert(dstack.peek_front() == 5);
    assert(dstack.peek_back() == 1);
    // Perform some operations to make sure front and back pointers are preserved
    // Push operations
    dstack.push(6);
    assert(dstack.peek_front() == 6);
    assert(dstack.peek_back() == 1);
    dstack.push_back(0);
    assert(dstack.peek_front() == 6);
    assert(dstack.peek_back() == 0);
    // Pop operations
    dstack.pop(); // 6
    assert(dstack.peek_front() == 5);
    assert(dstack.peek_back() == 0);
    dstack.pop_back(); // 0
    assert(dstack.peek_front() == 5);
    assert(dstack.peek_back() == 1);
    }; // End block

    { /**/
    // Length
    DynamicStack<int> dstack{1,2,3,4,5};
    assert(dstack.get_length() == 5);
    // Perform some operations to make sure front and back pointers are preserved
    // Push operations
    dstack.push(6);
    assert(dstack.get_length() == 6);
    dstack.push_back(0);
    assert(dstack.get_length() == 7);

    // Pop operations
    dstack.pop(); // 6
    assert(dstack.get_length() == 6);
    dstack.pop_back(); // 0
    assert(dstack.get_length() == 5);
    }; // End block

    { /* Test length with non-initialized instance */
    // Non-initialized
    DynamicStack<int> dstack;
    assert(dstack.get_length() == 0);
    dstack.push(0);
    assert(dstack.get_length() == 1);
    dstack.push(1);
    assert(dstack.get_length() == 2);
    dstack.push(2);
    assert(dstack.get_length() == 3);
    dstack.push_back(-1);
    assert(dstack.get_length() == 4);
    dstack.push_back(-2);
    assert(dstack.get_length() == 5);
    dstack.push_back(-3);
    assert(dstack.get_length() == 6);

    dstack.pop();
    assert(dstack.get_length() == 5);
    dstack.pop();
    assert(dstack.get_length() == 4);
    dstack.pop();
    assert(dstack.get_length() == 3);
    dstack.pop();
    assert(dstack.get_length() == 2);
    dstack.pop();
    assert(dstack.get_length() == 1);
    dstack.pop();
    assert(dstack.get_length() == 0);
    }; // End block

    std::cout << "Success - Passed " << __func__ << "\n\n";
}


void test_matching_group() {
    std::cout << "Beginning " << __func__ << endl;

    /* 
    ##############
    ## Positive ##
    ##############
    */
    // Positive - simple symmetric
    string test = "(a)";
    auto res = matching_group(test);
    assert(res == true);

    // Positive - text only
    test = "Non-Matching-Group";
    res = matching_group(test);
    assert(res == true);

    // Positive - two layers symmetric
    test = "(~{some-test}11)";
    res = matching_group(test);
    assert(res == true);

    // Positive - three layers symmetric
    test = "*4378kk$#&*&^(9~{som{e-tes}t}191)";
    res = matching_group(test);
    assert(res == true);

    // Positive - Non symmetric
    test = "{a(b+ac)d[xy]g}";
    res = matching_group(test);
    assert(res == true); 


    /* 
    ##############
    ## Negative ##
    ##############
    */
    // Negative - Unpaired
    test = "a)a(a";
    res = matching_group(test);
    assert(res == false);

    // Negative - Unpaired w/ partial matching
    test = "[a)a(a]";
    res = matching_group(test);
    assert(res == false);

    // Negative - Unpaired, ungrouped, odd number
    test = "ac)cd(e(k";
    res = matching_group(test);
    assert(res == false);

    // Negative - Unpaired, ungrouped, even number
    test = "ac)cd(e(k(";
    res = matching_group(test);
    assert(res == false); 

    // Negative - Unpaired symbols (odd number)
    test = "xy{za(dx)k";
    res = matching_group(test);
    assert(res == false);

    // Negative - Overlapping
    test = "{a(b+ac}d)";
    res = matching_group(test);
    assert(res == false);

    // Negative - Overlapping
    test = "{x(x+x{x)x}x[xx]x}";
    res = matching_group(test);
    assert(res == false); 

    std::cout << "Success - Passed " << __func__ << "\n\n";
}


int main () {

    // Test pop, push, pop_back, push_back, initialization, and other operations
    // test_dynamic_stack(); // Comment out for demonstration of grouping phase

    // Test matching_group
    test_matching_group();


    try {
        // Do something
    } catch (const std::logic_error& e) {
        // Print something
    }

    
    return 0;
}