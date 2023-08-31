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
    cout<<"Enter data: ";
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

int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);
}