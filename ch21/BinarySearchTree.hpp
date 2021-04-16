//
//  BinarySearchTree.h
//  BST_Demo
//
//  Created by ali.berrached on 7/5/19.
//  Copyright © 2019 ali.berrached. All rights reserved.
//
//This header file deined class BinarySearchTree as a subclass of BinaryTree
// It inherent all its properties and implements the search, insert, and deleteNode member functions.

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
//Header File Binary Search Tree


#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

template <class elemType>
class BinarySearchTree: public BinaryTree<elemType>
{
public:
    bool search(const elemType& searchItem) const;
    //Function to determine if searchItem is in the binary
    //search tree.
    //Postcondition: Returns true if searchItem is found in
    //               the binary search tree; otherwise,
    //               returns false.
    
    void insert(const elemType& insertItem);
    //Function to insert insertItem in the binary search tree.
    //Postcondition: If there is no node in the binary search
    //               tree that has the same data as
    //               insertItem, a node with the data
    //               insertItem is created and inserted in the
    //               binary search tree.

    void recursiveInsert(const elemType& insertItem);
    /* Recursively insert item into binary tree*/

    void _recursiveInsert(TreeNode<elemType>*& parentNode, TreeNode<elemType>*& newNode);
    
    void deleteNode(const elemType& deleteItem);
    //Function to delete deleteItem from the binary search tree
    //Postcondition: If a node with the same data as deleteItem
    //               is found, it is deleted from the binary
    //               search tree.
    //               If the binary tree is empty or deleteItem
    //               is not in the binary tree, an appropriate
    //               message is printed.
    
private:
    void deleteFromTree(TreeNode<elemType>* &p);
    //Function to delete the node to which p points is
    //deleted from the binary search tree.
    //Postcondition: The node to which p points is deleted
    //               from the binary search tree.
};


template <class elemType>
bool BinarySearchTree<elemType>::search(const elemType& searchItem) const
{
    TreeNode<elemType> *current;
    bool found = false;
    
    if (this->root == nullptr)
        return false;
    else
    {
        current = this->root;
        
        while (current != nullptr && !found)
        {
            if (current->data == searchItem)
                found = true;
            else if (current->data > searchItem)
                current = current->left;
            else
                current = current->right;
        }//end while
    }//end else
    
    return found;
}//end search

template <class elemType>
void BinarySearchTree<elemType>::insert(const elemType& insertItem)
{
    TreeNode<elemType> *current; //pointer to traverse the tree
    TreeNode<elemType> *trailCurrent; //pointer behind current
    TreeNode<elemType> *newNode;  //pointer to create the node
    
    newNode = new TreeNode<elemType>;
    newNode->data = insertItem;
    newNode->left = nullptr;
    newNode->right = nullptr;
    
    trailCurrent = nullptr;
    
    if (this->root == nullptr)
        this->root = newNode;
    else
    {
        current = this->root;
        
        while (current != nullptr)
        {
            trailCurrent = current;
            
            if (current->data == insertItem)
            {
                cout << "The item to be inserted is already ";
                cout << "in the tree -- duplicates are not "
                << "allowed." << endl;
                return;
            }
            else if (current->data > insertItem)
                current = current->left;
            else
                current = current->right;
        }//end while
        
        if (trailCurrent!= nullptr && trailCurrent->data > insertItem)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}//end insert

template <class elemType>
void BinarySearchTree<elemType>::deleteNode(const elemType& deleteItem)
{
    TreeNode<elemType> *current; //pointer to traverse the tree
    TreeNode<elemType> *trailCurrent; //pointer behind current
    bool found = false;
    
    if (this->root == nullptr)
        cout << "Cannot delete from an empty tree."
        << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;
        
        while (current != nullptr && !found)
        {
            if (current->data == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                
                if (current->data > deleteItem)
                    current = current->left;
                else
                    current = current->right;
            }
        }//end while
        
        if (current == nullptr)
            cout << "The item to be deleted is not in the tree."
            << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->data > deleteItem)
                deleteFromTree(trailCurrent->left);
            else
                deleteFromTree(trailCurrent->right);
        }
        else
            cout << "The item to be deleted is not in the tree."
            << endl;
    }
} //end deleteNode

template <class elemType>
void BinarySearchTree<elemType>::deleteFromTree(TreeNode<elemType>* &p)
{
    TreeNode<elemType> *current; // pointer to traverse the tree
    TreeNode<elemType> *trailCurrent;  // pointer behind current
    TreeNode<elemType> *temp;      // pointer to delete the node
    
    if (p == nullptr)
        cout << "Error: The node to be deleted does not exist."
        << endl;
    // Node to be deleted is a leaf node
    else if (p->left == nullptr && p->right == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    // Node to be deleted has only a right child
    else if (p->left == nullptr)
    {
        temp = p;
        p = temp->right;
        delete temp;
    }
    // Node to be deleted has only a left child
    else if (p->right == nullptr)
    {
        temp = p;
        p = temp->left;
        delete temp;
    }
    else // Node to be deleted has a left child and a right child
    {// replace node with right-most node of left subtree
        current = p->left;  // move left once
        trailCurrent = nullptr;
        
        while (current->right != nullptr) // find right-most node of left subtree
        {
            trailCurrent = current;
            current = current->right;
        }//end while
        
        p->data = current->data;
        
        if (trailCurrent == nullptr) //current did not move;
            //current == p->left; adjust p
            p->left = current->left;
        else
            trailCurrent->right = current->left;
        
        delete current;
    }//end else
} //end deleteFromTree




#endif /* BinarySearchTree_h */

