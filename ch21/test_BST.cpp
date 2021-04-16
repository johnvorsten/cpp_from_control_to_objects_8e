#include <vector>
#include <string>
#include <exception>

// Local import
#include "BinarySearchTree.hpp"
#include "nodeCount.cpp"
#include "leafCount.cpp"
#include "recursiveInsert.cpp"

namespace test {

void test_BST_search() {
    std::cout << "Beginning " << __func__ << endl;

    // Create binary tree
    std::vector<string> test_vec_str = {"A","B","C","D","@","AB"};
    std::vector<double> test_vec_double = {1,2,3,4,0.5,1.5};
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


void test_BST_deleteNode() {
    std::cout << "Beginning " << __func__ << endl;

    // Create binary tree
    std::vector<string> test_vec_str = {"A","B","C","D","E","@","AB"};
    std::vector<double> test_vec_double = {1,2,3,4,5,0.5,1.5};
    BinarySearchTree<std::string> bst_str;
    BinarySearchTree<double> bst_double;

    for (auto& str : test_vec_str) {
        bst_str.insert(str);
    }
    for (auto& val : test_vec_double) {
        bst_double.insert(val);
    }
    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";

    // Delete any leaf (no children)
    // Leafs are defined as a node that has no children
    // Which nodes do not have children in our test case? Only the tail..
    // We can insert values that will be leaf, such as 1.5, 2.5...
    double test_double = 5.0;
    std::string test_string = "E";

    bst_double.deleteNode(test_double);
    if (bst_double.search(test_double)) {
        string msg="Error, found value: ";
        msg += std::to_string(test_double) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    bst_str.deleteNode(test_string);
    if (bst_str.search(test_string)) {
        string msg="Error, found value: ";
        msg += (test_string) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }
    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";

    // Delete any node with a right child
    test_double = 3.0;
    test_string = "C";

    bst_double.deleteNode(test_double);
    if (bst_double.search(test_double)) {
        string msg="Error, found value: ";
        msg += std::to_string(test_double) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    bst_str.deleteNode(test_string);
    if (bst_str.search(test_string)) {
        string msg="Error, found value: ";
        msg += (test_string) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }
    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";
    // Create tree with a left only
    bst_double.deleteNode(4.0);
    bst_str.deleteNode("D");


    // Delete any node with a left child
    test_double = 2.0;
    test_string = "B";

    bst_double.deleteNode(test_double);
    if (bst_double.search(test_double)) {
        string msg="Error, found value: ";
        msg += std::to_string(test_double) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    bst_str.deleteNode(test_string);
    if (bst_str.search(test_string)) {
        string msg="Error, found value: ";
        msg += (test_string) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }
    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";

    // Delete any node with both left and right child
    test_double = 1.0;
    test_string = "A";

    bst_double.deleteNode(test_double); 
    if (bst_double.search(test_double)) {
        string msg="Error, found value: ";
        msg += std::to_string(test_double) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    bst_str.deleteNode(test_string);
    if (bst_str.search(test_string)) {
        string msg="Error, found value: ";
        msg += (test_string) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }
    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";

    // Delete head case, but build tree back up
    bst_str.insert("A");
    bst_str.insert("B");
    bst_double.insert(1.0);
    bst_double.insert(2.0);

    test_string = "AB";
    test_double = 1.5;
    bst_str.deleteNode(test_string);
    bst_double.deleteNode(test_double);

    if (bst_double.search(test_double)) {
        string msg="Error, found value: ";
        msg += std::to_string(test_double) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_str.search(test_string)) {
        string msg="Error, found value: ";
        msg += (test_string) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }
    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";

    std::cout << "Success - Passed " << __func__ << "\n\n";   
}


void test_BST_leavesCount() {
    std::cout << "Beginning " << __func__ << endl;

    // Create binary tree
    std::vector<string> test_vec_str = {"A","B","C","D","@","AB"};
    std::vector<double> test_vec_double = {1,2,3,4,5,0.5,1.5};
    BinarySearchTree<std::string> bst_str;
    BinarySearchTree<double> bst_double;

    for (auto& str : test_vec_str) {
        bst_str.insert(str);
    }
    for (auto& val : test_vec_double) {
        bst_double.insert(val);
    }

    // Count leaves (includes left and right children leaf)
    if (bst_str.treeLeavesCount() != 3) {
        string msg="Error, Incorrect number of leaves: ";
        msg += (bst_str.treeLeavesCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_double.treeLeavesCount() != 3) {
        string msg="Error, Incorrect number of leaves: ";
        msg += std::to_string(bst_double.treeLeavesCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    // Test head case
    BinarySearchTree<std::string> bst_str2;
    BinarySearchTree<double> bst_double2;
    bst_str2.insert("A");
    bst_double2.insert(1.0);
    if (bst_str2.treeLeavesCount() != 1) {
        string msg="Error, Incorrect number of leaves: ";
        msg += (bst_str2.treeLeavesCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_double2.treeLeavesCount() != 1) {
        string msg="Error, Incorrect number of leaves: ";
        msg += std::to_string(bst_double2.treeLeavesCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    // Test empty tree
    bst_str2.deleteNode("A");
    bst_double2.deleteNode(1.0);
    if (bst_str2.treeLeavesCount() != 0) {
        string msg="Error, Incorrect number of leaves: ";
        msg += (bst_str.treeLeavesCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_double2.treeLeavesCount() != 0) {
        string msg="Error, Incorrect number of leaves: ";
        msg += std::to_string(bst_double.treeLeavesCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    std::cout << "Success - Passed " << __func__ << "\n\n";   
}


void test_BST_nodeCount() {
    std::cout << "Beginning " << __func__ << endl;

    // Create binary tree
    std::vector<string> test_vec_str = {"A","B","C","D","@","AB"};
    std::vector<double> test_vec_double = {1,2,3,4,0.5,1.5};
    BinarySearchTree<std::string> bst_str;
    BinarySearchTree<double> bst_double;

    for (auto& str : test_vec_str) {
        bst_str.insert(str);
    }
    for (auto& val : test_vec_double) {
        bst_double.insert(val);
    }


    // Count nodes (includes left and right children leaf)
    if (bst_str.treeNodeCount() != 6) {
        string msg="Error, Incorrect number of nodes: ";
        msg += (bst_str.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_double.treeNodeCount() != 6) {
        string msg="Error, Incorrect number of nodes: ";
        msg += std::to_string(bst_double.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    // Test head case
    BinarySearchTree<std::string> bst_str2;
    BinarySearchTree<double> bst_double2;
    bst_str2.insert("A");
    bst_double2.insert(1.0);
    if (bst_str2.treeNodeCount() != 1) {
        string msg="Error, Incorrect number of nodes: ";
        msg += (bst_str2.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_double2.treeNodeCount() != 1) {
        string msg="Error, Incorrect number of nodes: ";
        msg += std::to_string(bst_double2.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    // Test empty tree
    BinarySearchTree<std::string> bst_str3;
    BinarySearchTree<double> bst_double3;
    if (bst_str3.treeNodeCount() != 0) {
        string msg="Error, Incorrect number of nodes: ";
        msg += (bst_str3.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    if (bst_double3.treeNodeCount() != 0) {
        string msg="Error, Incorrect number of nodes: ";
        msg += std::to_string(bst_double3.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

    std::cout << "Success - Passed " << __func__ << "\n\n";   
}


void test_BST_recursiveInsert() {
    std::cout << "Beginning " << __func__ << endl;

    // Create binary tree
    std::vector<string> test_vec_str = {"A","B","C","D","@","AB"};
    std::vector<double> test_vec_double = {1,2,3,4,0.5,1.5};
    BinarySearchTree<std::string> bst_str;
    BinarySearchTree<double> bst_double;

    for (auto& str : test_vec_str) {
        bst_str.recursiveInsert(str);
    }
    for (auto& val : test_vec_double) {
        bst_double.recursiveInsert(val);
    }

    std::cout << "Displaying Trees\n";
    bst_double.inorderTraversal();
    std::cout << "\n";
    bst_str.inorderTraversal();
    std::cout << "\n\n";

    if (bst_double. != 0) {
        string msg="Error, Incorrect number of nodes: ";
        msg += std::to_string(bst_double3.treeNodeCount()) + " in BinarySearchTree";
        msg += "\nin " + std::string(__func__);
        throw std::logic_error(msg);
    }

}

}; // End namespace

