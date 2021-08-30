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
        if (rootPtr == nullptr)
            return("Null");
        
        if (rootPtr->left == nullptr)
            return(rootPtr->value);
        
        return(getMin(rootPtr->left));
            
    }
    
    string getMin2() const
    {
        Node *current = root;
        
        if (current == nullptr)
            return("null");
        
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return(current->value);
    }
    
    string getMax(Node* rootPtr) const
    {
        if (rootPtr == nullptr)
            return("Null");
        
        if(rootPtr->right == nullptr)
            return(rootPtr->value);
        
        return(getMax(rootPtr->right));
    }
    
    string getMax2() const
    {
        Node* current = root;
        
        if (current == nullptr)
            return("null");
        
        while (current->right != nullptr)
            current = current->right;
        return(current->value);
    }
    
    void insert(string& newVal)
    {
        if (root == nullptr)
            root = new Node(newVal);
        
        Node* current = root;
        
        if (newVal == current->value)
            return;
        
        for(;;)
        {
            if (newVal < current->value)
            {
                if (current->left != nullptr)
                    current = current->left;
                else
                {
                    current->left = new Node(newVal);
                    return;
                }
            }
            else if (newVal > current->value)
            {
                if (current->right != nullptr)
                    current = current->right;
                else
                {
                    current->right = new Node(newVal);
                    return;
                }
            }
        }
    }
    
    Node* recursiveInsert(Node* root, string& newVal)
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
                recursiveInsert(root->left, newVal);
            else
                root->left = new Node(newVal);
        }
        else if (newVal > root->value)
        {
            if (root->right != nullptr)
                recursiveInsert(root->right, newVal);
            else
                root->right = new Node(newVal);
        }
        return(root);
    }
    
    void freeTree(Node* current)
    {
        if (current == nullptr)
            return;
        
        freeTree(current->left);
        freeTree(current->right);
        free(current);
        root = nullptr;
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
    
    root = bsTree.recursiveInsert(root, firstVal);
    bsTree.recursiveInsert(root, thirdVal);
    bsTree.recursiveInsert(root, fourthVal);
    bsTree.recursiveInsert(root, fifthVal);

    bsTree.freeTree(root);
    cout << bsTree.getRootVal() << endl;
    //cout << bsTree.getRootVal() << endl;
    //cout << bsTree.getMin(root) << endl;
    //cout << bsTree.getMax(root) << endl;
    
    
    
    
    return(0);
}
