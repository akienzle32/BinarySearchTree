//
//  BinarySearchTree.cpp
//  BinarySearchTree
//
//  Created by Alec Kienzle on 9/6/21.
//

#include <stdio.h>
#include <cstdlib>
#include <string>
#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree() : root(nullptr)
{}
    
std::string BinarySearchTree::getRootVal() const
{
    if (root == nullptr)
        return("Null");
    else
        return(root->value);
}
    
std::string BinarySearchTree::getMinNode(Node* rootPtr) const
{
    if (rootPtr == nullptr)
        return("Null");
        
    if (rootPtr->left == nullptr)
        return(rootPtr->value);
        
    return(getMinNode(rootPtr->left));
            
}
    
std::string BinarySearchTree::getMaxNode(Node* rootPtr) const
{
    if (rootPtr == nullptr)
        return("Null");
        
    if (rootPtr->right == nullptr)
        return(rootPtr->value);
        
    return(getMaxNode(rootPtr->right));
}
    
Node* BinarySearchTree::insert(Node* rootPtr, std::string& newVal)
{
    if (this->root == nullptr)
    {
        rootPtr = new Node(newVal);
        this->root = rootPtr;
    }
        
    if (newVal == rootPtr->value)
        return(rootPtr);
        
    if (newVal < rootPtr->value)
    {
        if (rootPtr->left != nullptr)
            insert(rootPtr->left, newVal);
        else
            rootPtr->left = new Node(newVal);
    }
    else if (newVal > rootPtr->value)
    {
        if (rootPtr->right != nullptr)
            insert(rootPtr->right, newVal);
        else
            rootPtr->right = new Node(newVal);
    }
    return(rootPtr);
}
    
bool BinarySearchTree::search(Node* rootPtr, std::string val)
{
    if (rootPtr == nullptr)
        return(false);
    
    if (val == rootPtr->value)
        return(true);
        
    if (val < rootPtr->value)
        return(search(rootPtr->left, val));
    else
        return(search(rootPtr->right, val));
}

int BinarySearchTree::findHeight(Node* rootPtr)
{
    if (rootPtr == nullptr)
        return 0;
    
    return(1 + std::max(findHeight(rootPtr->left), findHeight(rootPtr->right)));
}

bool BinarySearchTree::isBalanced(Node* rootPtr)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if (rootPtr == nullptr)
        return(true);
    
    leftHeight = findHeight(rootPtr->left);
    rightHeight = findHeight(rootPtr->right);
    
    if (abs(leftHeight - rightHeight) <= 1 and isBalanced(rootPtr->left)
        and isBalanced(rootPtr->right))
        return(true);
    
    return(false);
}
    
void BinarySearchTree::freeTree(Node* current)
{
    if (current == nullptr)
        return;
        
    freeTree(current->left);
    freeTree(current->right);
    free(current);
    root = nullptr;
}
    
void BinarySearchTree::invertTree(Node* current)
{
    if (current == nullptr)
        return;
        
    invertTree(current->left);
    invertTree(current->right);
            
    Node* temp = current->left;
    current->left = current->right;
    current->right = temp;
}
