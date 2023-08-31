#include<bits/stdc++.h>
using namespace std;

void func(int i, int j, int n, vector<vector<int>>& m, vector<string>& ans, string move, vector<vector<int>>& vis){
    //base case
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }

    //down
    if(i+1<n && m[i+1][j]==1 && vis[i+1][j]==0){
        vis[i][j]=1;
        func(i+1,j,n,m,ans,move+'D',vis);
        vis[i][j]=0;
    }

    //left
    if(j-1>=0 && m[i][j-1]==1 && vis[i][j-1]==0){
        vis[i][j]=1;
        func(i,j-1,n,m,ans,move+"L",vis);
        vis[i][j]=0;
    }

    //right
    if(j+1<n && m[i][j+1]==1 && vis[i][j+1]==0){
        vis[i][j]=1;
        func(i,j+1,n,m,ans,move+"R",vis);
        vis[i][j]=0;
    }

    //up
    if(i-1>=0 && m[i-1][j]==1 && vis[i-1][j]==0){
        vis[i][j]=1;
        func(i-1,j,n,m,ans,move+"U",vis);
        vis[i][j]=0;
    }
}

vector<string> findPath(int n, vector<vector<int>>& m){
    vector<string> ans;
    vector<vector<int>> vis(n, vector < int > (n, 0));

    if(m[0][0]==1) 
        func(0,0,n,m,ans,"",vis);

    return ans;
}

int main(){
    int n=4;
    vector<vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<string> ans = findPath(n,m);

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
}