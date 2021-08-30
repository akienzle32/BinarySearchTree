//
//  main.cpp
//  BinarySearchTree
//
//  Created by Alec Kienzle on 8/30/21.
//

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    Node(string& val) : value(val), left(nullptr), right(nullptr)
    {}
    
    string value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr)
    {}
    
    string getRootVal() const
    {
        if (root == nullptr)
            return("Null");
        else
            return(root->value);
    }
    
    string getLeftVal() const
    {
        return (root->left->value);
    }
    
    string getRightVal() const
    {
        return(root->right->value);
    }
    
    Node* insert(Node* root, string& newVal)
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
            {
                insert(root->left, newVal);
            }
            else
            {
                root->left = new Node(newVal);
            }
        }
        else if (newVal > root->value)
        {
            if (root->right != nullptr)
            {
                insert(root->right, newVal);
            }
            else
            {
                root->right = new Node(newVal);
            }
        }
        return(root);
        
    }
    
private:
    Node* root;
};

int main() {
    
    BinarySearchTree bsTree;
    Node* root = nullptr;
    string firstVal = "oranges";
    string secondVal = "apples";
    string thirdVal = "pears";
    string fourthVal = "bananas";
    
    root = bsTree.insert(root, firstVal);
    bsTree.insert(root, secondVal);
    bsTree.insert(root, thirdVal);

    cout << bsTree.getRootVal() << endl;
    cout << bsTree.getRightVal() << endl;
    
    
    
    
    return(0);
}
