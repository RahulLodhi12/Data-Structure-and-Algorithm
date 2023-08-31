// Level Order Traversal (Breadth First Search or BFS) of Binary Tree
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node* root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    //base case
    if(data==-1){
        return NULL;
    }

    root = new node(data);

    cout<<"Element for left of "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Element for right of "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}

void preOrderIterative(node* root){
    stack<node*> s;
    node* curr = root;
    s.push(curr);
    while(!s.empty()){
        curr = s.top();
        cout<<curr->data<<" ";
        s.pop();
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
}


int main(){
    node* root = NULL;
    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    root = createTree(root);

    cout<<"Preorder Traversal - Iterative: "<<endl;
    preOrderIterative(root);
}