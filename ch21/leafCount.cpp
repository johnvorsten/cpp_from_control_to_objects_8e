#include "BinarySearchTree.hpp"
#include "BinaryTree.hpp"

using namespace std;

template <class elemType>
int BinaryTree<elemType>::leavesCount(TreeNode<elemType> *p) const {
    /* Count the number of leaves in a binary tree
    Leaves are defined as any node with no left or right children*/

    if (p == nullptr) {
        return 0;
    }
    else if (p->left == nullptr && p->right == nullptr) {
        return 1;
    }
    else {
        return leavesCount(p->left) + leavesCount(p->right);
    }
    
    return 0;
}