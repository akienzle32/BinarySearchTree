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
    
    string getMin(Node* rootPtr) const
    {
        string min;
        
        if (root == nullptr)
            return("Null");
        
        while (rootPtr->left != nullptr)
            rootPtr = rootPtr->left;
        
        return(rootPtr->value);
            
    }
    
    string getMax(Node* rootPtr) const
    {
        if (root == nullptr)
            return("Null");
        
        while(rootPtr->right != nullptr)
            rootPtr = rootPtr->right;
        
        return(rootPtr->value);
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
    string fifthVal = "strawberry";
    
    root = bsTree.insert(root, firstVal);
    bsTree.insert(root, secondVal);
    bsTree.insert(root, thirdVal);
    bsTree.insert(root, fourthVal);
    bsTree.insert(root, fifthVal);

    cout << bsTree.getRootVal() << endl;
    cout << bsTree.getMin(root) << endl;
    cout << bsTree.getMax(root) << endl;
    
    
    
    
    return(0);
}
