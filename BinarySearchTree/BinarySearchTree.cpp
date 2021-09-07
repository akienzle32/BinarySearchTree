//
//  BinarySearchTree.cpp
//  BinarySearchTree
//
//  Created by Alec Kienzle on 9/6/21.
//

#include <stdio.h>
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
    
std::string BinarySearchTree::getMin(Node* rootPtr) const
{
    if (rootPtr == nullptr)
        return("Null");
        
    if (rootPtr->left == nullptr)
        return(rootPtr->value);
        
    return(getMin(rootPtr->left));
            
}
    
std::string BinarySearchTree::getMax(Node* rootPtr) const
{
    if (rootPtr == nullptr)
        return("Null");
        
    if(rootPtr->right == nullptr)
        return(rootPtr->value);
        
    return(getMax(rootPtr->right));
}
    
Node* BinarySearchTree::insert(Node* root, std::string& newVal)
{
    if (this->root == nullptr)
    {
        root = new Node(newVal);
        this->root = root;
    }
        
    if (newVal == root->value)
        return(root);
        
    if (newVal < root->value)
    {
        if (root->left != nullptr)
            insert(root->left, newVal);
        else
            root->left = new Node(newVal);
    }
    else if (newVal > root->value)
    {
        if (root->right != nullptr)
            insert(root->right, newVal);
        else
            root->right = new Node(newVal);
    }
    return(root);
}
    
bool BinarySearchTree::search(Node* root, std::string val)
{
    if (root == nullptr)
        return(false);
    if (val == root->value)
        return(true);
        
    if (val < root->value)
        return(search(root->left, val));
    else
        return(search(root->right, val));
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
        
    else
    {
        invertTree(current->left);
        invertTree(current->right);
            
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;
    }
}
