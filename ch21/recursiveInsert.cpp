#include "BinarySearchTree.hpp"
#include "BinaryTree.hpp"

using namespace std;

template <typename T>
void BinarySearchTree<T>::_recursiveInsert(TreeNode<T>*& parentNodePtr, TreeNode<T>*& newNodePtr) {
      
    /*
    a. Test the head case. If the tree is empty then 
        assign the node to the reference location
    b. If the new value is less than the reference node, 
        then insert the new node into the left side
    c. If the new value is greater than the reference node, 
        then insert the new node into the right side
    */

   if (parentNodePtr == nullptr) {
       // Assign node as root (in head case), or assign the parents pointer at the child
       parentNodePtr = newNodePtr;
   }
   else if (newNodePtr->data > parentNodePtr->data) {
       // Insert newNodePtr to right of parent (recursive search)
       _recursiveInsert(parentNodePtr->right, newNodePtr);
   }
   else if (newNodePtr->data < parentNodePtr->data) {
       // Insert newNodePtr to left of parent (recursive search)
       _recursiveInsert(parentNodePtr->left, newNodePtr);
   }
   else if (newNodePtr->data == parentNodePtr->data) {
       // Signal error
        cout << "The item to be inserted is already ";
        cout << "in the tree -- duplicates are not "
        << "allowed." << endl;
        return;
   }

}

template <typename T>
void BinarySearchTree<T>::recursiveInsert(const T& insertItem) {
    /*inputs
    -------
    Reference location to insert node (Used recursively)
    New node to insert (Created by the public passer function)*/
   
    // Assign data
    TreeNode<T>* newNode = new TreeNode<T>;
    newNode->data = insertItem;
    newNode->left = nullptr;
    newNode->right = nullptr;
    _recursiveInsert(this->root, newNode);

} // end recursiveInsert