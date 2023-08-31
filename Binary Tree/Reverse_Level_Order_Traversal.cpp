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

void reverseLevelOrderTraversal(node* root){
    vector<int> v;

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        v.push_back(temp->data);
        q.pop();
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }

    reverse(v.begin(),v.end());
    for(auto it:v){
        cout<<it<<" ";
    }
}


int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);

    cout<<"Reverse Level Order Traversal: "<<endl;
    reverseLevelOrderTraversal(root);
}