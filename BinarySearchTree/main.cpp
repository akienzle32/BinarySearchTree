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
    
    void insert(string& newVal)
    {
        if (root == nullptr)
        {
            root = new Node(newVal);
            return;
        }
        Node *current = root;
        
        for(;;)
        {
            if (newVal == current->value)
                return;
        
            if (newVal < current->value)
            {
                if (current->left != nullptr)
                    current = current->left; // Think this is where you'd use recursion.
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
    
private:
    Node* root;
};

int main() {
    
    return(0);
}
