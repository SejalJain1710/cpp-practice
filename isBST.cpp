#include <bits/stdc++.h> 
using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;

    node(int data) 
    {
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
}; 

void inorder(vector<int>& v, node* root) {
    if (root != NULL) {
        inorder(v, root -> left);
        v.push_back(root -> data);
        inorder(v, root -> right);
    }
}
    
bool isValidBST(node* root) {
    if (root == NULL)
        return true;
    vector<int> v;
    inorder(v, root);
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] >= v[i+1])
            return false;
    }
    return true;
}

int main()  
{  
    node *root = new node(3);  
    root->left = new node(2);  
    root->right = new node(5);  
    root->left->left = new node(1);  
    root->left->right = new node(4);
      
    if(isValidBST(root))
        cout << "Is BST" << endl;  
    else
        cout << "Not a BST" << endl;  
          
    return 0;  
}