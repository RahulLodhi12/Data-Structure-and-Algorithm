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

void func(node* root, int &cnt){
    if(root==NULL){
        return;
    }

    func(root->left,cnt);
    if(root->left==NULL && root->right==NULL){
        cnt++;
    }
    func(root->right,cnt);
}

int countLeaf(node* root){
    int cnt = 0;
    func(root,cnt);

    return cnt;
}


int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);

    cout<<"Count of Leaf Nodes: "<<countLeaf(root)<<endl;
}