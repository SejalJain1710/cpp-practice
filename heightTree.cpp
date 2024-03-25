#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
};

int heightRecursive(node* root) {
    if (root == NULL)
        return 0;
    return max(heightRecursive(root->left), heightRecursive(root->right)) + 1;
}

node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  
    
int main()  
{  
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
      
    cout << "Height of tree is " << heightRecursive(root) << endl;
    return 0;
}