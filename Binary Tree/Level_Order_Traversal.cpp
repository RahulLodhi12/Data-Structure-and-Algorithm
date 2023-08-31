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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); //separator

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); // add separator
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);

    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
}