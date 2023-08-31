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

vector<int> zigZag(node* root){
    vector<int> ans;
    if(root==NULL){
        return {0};
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ds(size);

        for(int i=0;i<size;i++){
            node* temp = q.front(); // take out
            q.pop();
            int ind = leftToRight ? i : (size-i-1);
            ds[ind] = temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        leftToRight = !leftToRight; //direction change
        for(auto it: ds){
            ans.push_back(it);
        }
    }
    return ans;
}

int main(){
    node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createTree(root);

    cout<<"ZigZag Traversal: "<<endl;
    vector<int> fans = zigZag(root);
    for(int i=0;i<fans.size();i++){
        cout<<fans[i]<<" ";
    }
}