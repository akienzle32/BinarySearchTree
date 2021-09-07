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
    
    std::string getMin(Node* rootPtr) const;
    
    std::string getMax(Node* rootPtr) const;
    
    Node* insert(Node* root, std::string& newVal);
    
    bool search(Node* root, std::string val);
    
    void freeTree(Node* current);
    
    void invertTree(Node* current);
    
private:
    Node* root;
};


#endif /* BinarySearchTree_h */
