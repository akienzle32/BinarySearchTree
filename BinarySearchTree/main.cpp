//
//  main.cpp
//  BinarySearchTree
//
//  Created by Alec Kienzle on 8/30/21.
//

#include <iostream>
#include <string>
#include "BinarySearchTree.h"


int main() {
    using namespace std;
    
    BinarySearchTree bsTree;
    Node* root = nullptr;
    string firstVal = "oranges";
    string secondVal = "apples";
    string thirdVal = "pears";
    string fourthVal = "bananas";
    string fifthVal = "strawberry";
    
    root = bsTree.insert(root, firstVal);
    bsTree.insert(root, secondVal);
    bsTree.insert(root, thirdVal);
    bsTree.insert(root, fourthVal);
    bsTree.insert(root, fifthVal);
    
    cout << "The root node is: " << bsTree.getRootVal() << endl;
    cout << "The max node is: " << bsTree.getMax(root) << endl;
    cout << "The min node is " << bsTree.getMin(root) << "\n\n";

    bsTree.invertTree(root);
    cout << "After inversion, the max node is: " << bsTree.getMax(root) << endl;
    cout << "The min node is: " << bsTree.getMin(root) << endl;
    
    return(0);
}
