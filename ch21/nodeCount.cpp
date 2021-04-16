#include "BinarySearchTree.hpp"
#include "BinaryTree.hpp"

using namespace std;

template <class elemType>
int BinaryTree<elemType>::nodeCount(TreeNode<elemType> *p) const {
    /* Count the number of nodes in a binary tree
    Nodes are defined as any node, and it includes leaves, nodes with only one child, 
    and nodes with two children*/

    if (p == nullptr) {
        return 0;
    }
    else if (p->left == nullptr) {
        // The left item is null, count this node and all right nodes
        return 1 + nodeCount(p->right);
    }
    else if (p->right == nullptr) {
        // The right item is null, count this node and all left nodes
        return 1 + nodeCount(p->left);
    }
    else {
        // Count both left and right nodes with this node
        return 1 + nodeCount(p->left) + nodeCount(p->right);
    }
    
    return 0;
}