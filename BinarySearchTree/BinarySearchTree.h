//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by Alec Kienzle on 9/6/21.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <string>

struct Node
{
    Node(std::string& val) : value(val), left(nullptr), right(nullptr)
    {}
    
    std::string value;
    Node* left;
    Node* right;
};
class BinarySearchTree
{
public:
    BinarySearchTree();
    
    std::string getRootVal() const;
    
    std::string getMinNode(Node* rootPtr) const;
    
    std::string getMaxNode(Node* rootPtr) const;
    
    Node* insert(Node* rootPtr, std::string& newVal);
    
    bool search(Node* rootPtr, std::string val);
    
    int findHeight(Node* rootPtr);
    
    bool isBalanced(Node* rootPtr);
    
    void freeTree(Node* current);
    
    void invertTree(Node* current);
    
private:
    Node* root;
};


#endif /* BinarySearchTree_h */
