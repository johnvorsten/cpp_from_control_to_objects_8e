//
//  BinaryTree.h
//  BST_Demo
//
//  Created by ali.berrached on 7/5/19.
//  Copyright © 2019 ali.berrached. All rights reserved.

//

/*Class BinaryTree defines a binary tree (i.e. all properties 
that are common to all binary trees).  It's a virtual class 
that is used primarily to derived class BinarySearchTree 
which is defined in file BinarySearchTree.h

Remember that a binary search tree (BST) is a binary tree 
that is organized in such a way that the keys of all nodes 
in the letf-subtree of every node X are smaller that the 
key of node X and the keys of all nodes in the right-subtree 
of every node X are larger that the key of node X.

The only functions that make a BST different from non-BSTs 
are the insert, delete, and search functions. These functions 
are defined as virtual functions in the class BinaryTree and 
will be implemented in class BinarySearchTree.
*/

#ifndef BinaryTree_h
#define BinaryTree_h
//Header File Binary Tree

#include <iostream>

using namespace std;

//Definition of the Node
template <class elemType>
struct TreeNode
{
    elemType data;
    TreeNode<elemType> *left;
    TreeNode<elemType> *right;
};

//Definition of the class
template <class elemType>
class BinaryTree
{
protected:
    TreeNode<elemType>  *root;
    
public:
    const BinaryTree<elemType>& operator=
    (const BinaryTree<elemType>&);
    //Overload the assignment operator.
    
    bool isEmpty() const;
    //Function to determine whether the binary tree is empty.
    //Postcondition: Returns true if the binary tree is empty;
    //               otherwise, returns false.
    
    void inorderTraversal() const;
    //Function to do an inorder traversal of the binary tree.
    //Postcondition: Nodes are printed in inorder sequence.
    
    void preorderTraversal() const;
    //Function to do a preorder traversal of the binary tree.
    //Postcondition: Nodes are printed in preorder sequence.
    
    void postorderTraversal() const;
    //Function to do a postorder traversal of the binary tree.
    //Postcondition: Nodes are printed in postorder sequence.
    
    int treeHeight() const;
    //Function to determine the height of a binary tree.
    //Postcondition: Returns the height of the binary tree.
    
    int treeNodeCount() const;
    //Function to determine the number of nodes in a
    //binary tree.
    //Postcondition: Returns the number of nodes in the
    //               binary tree.
    
    int treeLeavesCount() const;
    //Function to determine the number of leaves in a
    //binary tree.
    //Postcondition: Returns the number of leaves in the
    //               binary tree.
    
    void destroyTree();
    //Function to destroy the binary tree.
    //Postcondition: Memory space occupied by each node
    //               is deallocated.
    //               root = nullptr;
    
    virtual bool search(const elemType& searchItem) const = 0;
    //Function to determine if searchItem is in the binary
    //tree.
    //Postcondition: Returns true if searchItem is found in
    //               the binary tree; otherwise, returns
    //               false.
    
    virtual void insert(const elemType& insertItem) = 0;
    //Function to insert insertItem in the binary tree.
    //Postcondition: If there is no node in the binary tree
    //               that has the same data field as insertItem, a
    //               new node with the data field set to insertItem is created
    //               and inserted in the binary search tree.
    
    virtual void deleteNode(const elemType& deleteItem) = 0;
    //Function to delete deleteItem from the binary tree
    //Postcondition: If a node with the same data field as
    //               deleteItem is found, it is deleted from
    //               the binary tree.
    //               If the binary tree is empty or
    //               deleteItem is not in the binary tree,
    //               an appropriate message is printed.
    
    BinaryTree(const BinaryTree<elemType>& otherTree);
    //Copy constructor
    
    BinaryTree();
    //Default constructor
    
    ~BinaryTree();
    //Destructor
    
private:
    void copyTree(TreeNode<elemType>* &copiedTreeRoot,
                  TreeNode<elemType>* otherTreeRoot);
    //Makes a copy of the binary tree to which
    //otherTreeRoot points.
    //Postcondition: The pointer copiedTreeRoot points to
    //               the root of the copied binary tree.
    
    void destroy(TreeNode<elemType>* &p);
    //Function to destroy the binary tree to which p points.
    //Postcondition: Memory space occupied by each node, in
    //               the binary tree to which p points, is
    //               deallocated.
    //               p = nullptr;
    
    void inorder(TreeNode<elemType> *p) const;
    //Function to do an inorder traversal of the binary
    //tree to which p points.
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in inorder sequence.
    
    void preorder(TreeNode<elemType> *p) const;
    //Function to do a preorder traversal of the binary
    //tree to which p points.
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in preorder
    //               sequence.
    
    void postorder(TreeNode<elemType> *p) const;
    //Function to do a postorder traversal of the binary
    //tree to which p points.
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in postorder
    //               sequence.
    
    int height(TreeNode<elemType> *p) const;
    //Function to determine the height of the binary tree
    //to which p points.
    //Postcondition: Height of the binary tree to which
    //               p points is returned.
    
    int max(int x, int y) const;
    //Function to determine the larger of x and y.
    //Postcondition: Returns the larger of x and y.
    
    int nodeCount(TreeNode<elemType> *p) const;
    //Function to determine the number of nodes in
    //the binary tree to which p points.
    //Postcondition: The number of nodes in the binary
    //               tree to which p points is returned.
    
    int leavesCount(TreeNode<elemType> *p) const;
    //Function to determine the number of leaves in
    //the binary tree to which p points
    //Postcondition: The number of leaves in the binary
    //               tree to which p points is returned.
};

//Definition of member functions

template <class elemType>
BinaryTree<elemType>::BinaryTree() // class constructor
{
    root = nullptr;
}

template <class elemType>
bool BinaryTree<elemType>::isEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void BinaryTree<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void BinaryTree<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void BinaryTree<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int BinaryTree<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int BinaryTree<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int BinaryTree<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}



template <class elemType>
void BinaryTree<elemType>::inorder
(TreeNode<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

template <class elemType>
void BinaryTree<elemType>::preorder
(TreeNode<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->data <<  " ";
        preorder(p->left);
        preorder(p->right);
    }
    else
        cout << "null ";
}

template <class elemType>
void BinaryTree<elemType>::postorder
(TreeNode<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}
/******************************************
 ** functions to perform tree deep copy
 *****************************************/
template <class elemType>
void  BinaryTree<elemType>::copyTree
(TreeNode<elemType>* &copiedTreeRoot,
 TreeNode<elemType>* otherTreeRoot)
{// Helper function for tree deep copying
    // It copies tree rooted at otherTreeRoot into a tree rooted at copiedTreeRoot
    // Used by the class copy constructor and the assignment operator
    
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new TreeNode<elemType>;
        copiedTreeRoot->data = otherTreeRoot->data;
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        copyTree(copiedTreeRoot->right, otherTreeRoot->right);
    }
} //end copyTree

//Class copy constructor with deep copying
template <class elemType>
BinaryTree<elemType>::BinaryTree
(const BinaryTree<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

//Overload the assignment operator for deep coping
template <class elemType>
const BinaryTree<elemType>& BinaryTree<elemType>::
operator=(const BinaryTree<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)   //if the binary tree is not empty,
            //destroy the binary tree
            destroy(root);
        
        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else
    
    return *this;
}
/******************************
 * Class Destructor Functions
 ******************************/
//class Destructor
template <class elemType>
BinaryTree<elemType>::~BinaryTree()
{
    destroy(root);
}

template <class elemType>
void  BinaryTree<elemType>::destroy(TreeNode<elemType>* &p)
{// Helper function for class destructor
    if (p != nullptr)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = nullptr;
    }
}
/*  End of class destructor functions */

template<class elemType>
int BinaryTree<elemType>::height
(TreeNode<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}

template <class elemType>
int BinaryTree<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int BinaryTree<elemType>::nodeCount(TreeNode<elemType> *p) const
{
    cout << "Write the definition of the function nodeCount."
    << endl;
    
    return 0;
}

template <class elemType>
int BinaryTree<elemType>::leavesCount(TreeNode<elemType> *p) const
{
    cout << "Write the definition of the function leavesCount."
    << endl;
    
    return 0;
}
#endif /* BinaryTree_h */

