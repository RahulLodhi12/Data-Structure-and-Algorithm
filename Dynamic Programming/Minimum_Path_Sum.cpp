#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int right,left;
int solve(int i, int j, vector<vector<int>>& grid,int m,int n){
    //base cases
    if(i==m-1 && j==n-1) return grid[i][j];
    if(i==m-1){//only move to right
        return grid[i][j] + solve(i,j+1,grid,m,n); //right
    }
    if(j==n-1){//only move to down
        return grid[i][j] + solve(i+1,j,grid,m,n); //down
    }

    // return min(down,right);
    int down = grid[i][j] + solve(i+1,j,grid,m,n);
    int right = grid[i][j] + solve(i,j+1,grid,m,n);
    return min(down,right);
}


// Approach 2: Using DP
int dp[201][201];
int sollve(int i, int j, vector<vector<int>>& grid, int m, int n){
    //base case
    if(i==m-1 && j==n-1) return grid[i][j];
    if(i==m-1){
        return grid[i][j] + sollve(i,j+1,grid,m,n);
    }
    if(j==n-1){
        return grid[i][j] + sollve(i+1,j,grid,m,n);
    }

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    int down = grid[i][j] + solve(i+1,j,grid,m,n);
    int right = grid[i][j] + solve(i,j+1,grid,m,n);

    dp[i][j] = min(down,right);
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid, int m, int n){
    // int ans = solve(0,0,grid,m,n);

    memset(dp,-1,sizeof(dp));
    int ans = sollve(0,0,grid,m,n);
    return ans;
}

int main(){
    int m;
    int n;
    cin>>m>>n;

    vector<vector<int>> grid(m); // vector<vector<int>> matrix(row);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            grid[i].push_back(t);
        }
    }

    cout<<minPathSum(grid,m,n);

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
}