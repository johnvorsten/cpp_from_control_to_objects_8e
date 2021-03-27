//
//  main.cpp
//  BST_Demo
//
//  Created by ali.berrached on 7/5/19.
//  Copyright © 2019 ali.berrached. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"
int main() {
    BinarySearchTree<int> integerTree;
    
    integerTree.insert(12);
    integerTree.insert(38);
    integerTree.insert(25);
    integerTree.insert(5);
    integerTree.insert(15);
    integerTree.insert(8);
    integerTree.insert(55);
    integerTree.preorderTraversal();
    
    return 0;
}
