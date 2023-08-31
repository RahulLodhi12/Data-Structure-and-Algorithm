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
bool isBalanced1(node* root){
    if(root==NULL){
        return true;
    }

    bool leftAns = isBalanced1(root->left);
    bool rightAns = isBalanced1(root->right);
    
    if(abs(height(root->left)-height(root->right))<=1 && leftAns && rightAns){
        return true;
    }

    return false;
}

//--------xxx----------xxxxx-----------------xxxxxxxxxxxx-------------------xxxxxxxxxx

pair<bool,int> isBalancedFast(node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);

    bool leftAns = left.first; //individual
    bool rightAns = right.first; //individual

    pair<bool,int> ans;
    if((abs(left.first - right.first)<=1) && leftAns && rightAns){ // as whole
        ans.first = true;
    }
    ans.second = max(left.second,right.second) + 1; // as whole

    return ans;
}

//Approach 2: Optimal Solution
int isBalanced2(node* root){
    return isBalancedFast(root).first;
}

int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);

    cout<<"Is Binary Tree Balanced ?? "<<endl;
    // cout<<isBalanced1(root);
    cout<<isBalanced2(root);
}