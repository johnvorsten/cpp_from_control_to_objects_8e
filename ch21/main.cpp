//
//  main.cpp
//  BST_Demo
//
//  Created by ali.berrached on 7/5/19.
//  Copyright © 2019 ali.berrached. All rights reserved.
//

/*Do the following:

1. [10 %] add code to test the deleteNode and search member functions. 
Save screenshot of your test program run. 

2. [25 %] add code to implement the nodeCount member function of 
class BinaryTree.  Test it and save screenshot of your test program run.

3. [25 %]add code to implement the leafCount member function of 
class BinaryTree.  Test it and save screenshot of your test program run.

4. [40 %] The insert member function uses an iterative algorithm 
to insert a new value into the BST. Define a new insert function 
name it recursiveInsert that uses a recursive algorithm instead. 
Hint: watch video tutorials. Write a test program to test your 
function and save a screenshot of a test run showing your insert 
function works properly.*/


#include <iostream>
#include "BinarySearchTree.hpp"
#include "test_BST.cpp"
#include <vector>

using namespace std;

int main() {
    BinarySearchTree<int> integerTree;
    
    // integerTree.insert(12);
    // integerTree.insert(38);
    // integerTree.insert(25);
    // integerTree.insert(5);
    // integerTree.insert(15);
    // integerTree.insert(8);
    // integerTree.insert(55);
    // integerTree.preorderTraversal();

    // Test search function
    try {
        test::test_BST_search();
    } catch(const std::logic_error& e) {
        std::cout << e.what();
    }

    // Test delete function
    try {
        test::test_BST_deleteNode();
    } catch(const std::logic_error& e) {
        std::cout << e.what();
    }

    // Test leaves count function
    try {
        test::test_BST_leavesCount();
    } catch(const std::logic_error& e) {
        std::cout << e.what();
    }
    
    // Test node count function
    try {
        test::test_BST_nodeCount();
    } catch(const std::logic_error& e) {
        std::cout << e.what();
    }

    // Test recursive insert
    try {
        test::test_BST_recursiveInsert();
    } catch(const std::logic_error& e) {
        std::cout << e.what();
    }

    return 0;
}
