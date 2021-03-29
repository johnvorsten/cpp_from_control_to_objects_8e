#include <vector>
#include <string>
#include <exception>

// Local import
#include "BinarySearchTree.hpp"

namespace test {

void test_BST_search() {
    std::cout << "Beginning " << __func__ << endl;

    // Create binary tree
    std::vector<string> test_vec_str = {"A","B","C","D","E","F","G","H"};
    std::vector<double> test_vec_double = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    BinarySearchTree<std::string> bst_str;
    BinarySearchTree<double> bst_double;

    for (auto& str : test_vec_str) {
        bst_str.insert(str);
    }
    for (auto& val : test_vec_double) {
        bst_double.insert(val);
    }

    // Search head case
    if (!bst_str.search("A")) {
        string msg="Could not find value: 'A' in BinarySearchTree";
        msg+="\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }
    if (!bst_double.search(1.0)) {
        string msg="Could not find value: '1.0' in BinarySearchTree";
        msg+="\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    // Search any node
    for (auto it = test_vec_str.begin() + 1; it != test_vec_str.end(); ++it) {
        if (!bst_str.search(*it)) {
            string msg="Could not find value: ";
            msg+= std::string(*it) + " in BinarySearchTree";
            msg+="\nin " + std::string(__func__);
            throw std::logic_error(msg);
        }
    }

    for (auto it = test_vec_double.begin() + 1; it != test_vec_double.end(); ++it) {
        if (!bst_double.search(*it)) {
            string msg="Could not find value: ";
            msg+= std::to_string(*it) + " in BinarySearchTree";
            msg+="\nin " + std::string(__func__);
            throw std::logic_error(msg);
        }
    }

    // Search any leaf
    // Leafs are defined as a node that has no children
    // Which nodes do not have children in our test case? Only the tail..
    // We can insert values that will be leaf, such as 1.5, 2.5...
    bst_double.insert(1.5);
    bst_double.insert(2.5);
    bst_double.insert(16.5);
    for (auto& val : {1.5, 2.5, 16.5}) {
        if (!bst_double.search(val)) {
            string msg="Could not find value: ";
            msg += std::to_string(val) + " in BinarySearchTree";
            msg += "\nin " + std::string(__func__);
            throw std::logic_error(msg);
        }
    }

    std::cout << "Success - Passed " << __func__ << "\n\n";
}



}; // End namespace

