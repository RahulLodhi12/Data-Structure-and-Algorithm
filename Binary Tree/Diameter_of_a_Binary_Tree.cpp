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

int height(node* root){
    //base case
    if(root==NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;

    return ans;
}

// Approach 1: Brute Force
int diameter1(node* root){
    if(root==NULL){
        return 0;
    }

    int op1 = diameter1(root->left);
    int op2 = diameter1(root->right);
    int op3 = height(root->left) + 1 + height(root->right);
    
    int ans = max(op1, max(op2,op3));

    return ans;
}

//---------xxxx---------xxxxxxx---------------xxxxxxxxxxxxxxx------------------------xxxxxxxxxxxxxxxxxxxxxxxx

pair<int,int> diameterFast(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first; // individual
    int op2 = right.first; // individual
    int op3 = left.second + 1 + right.second; // individual

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3)); // as whole
    ans.second = max(left.second,right.second) + 1; // as whole

    return ans;
}

//Approach 2: Optimal Solution
int diameter2(node* root){
    return diameterFast(root).first;
}

int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);

    cout<<"Diamter of Binary Tree: "<<endl;
    // cout<<diameter1(root);
    cout<<diameter2(root);
}