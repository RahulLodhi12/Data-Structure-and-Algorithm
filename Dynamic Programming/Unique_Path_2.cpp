#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int j, vector<vector<int>>& grid,int m,int n){
    //base case
    if(i>=m || j>=n || grid[i][j] == 1) return 0;
    if(i==m-1 && j==n-1) return 1;

    int down = solve(i+1,j,grid,m,n);
    int right = solve(i,j+1,grid,m,n);

    return down+right;
}


// Approach 2: Using DP
int dp[101][101];
int sollve(int i, int j, vector<vector<int>>& grid, int m, int n){
    //base case
    if(i>=m || j>=n || grid[i][j] == 1) return 0;
    if(i==m-1 && j==n-1) return 1;

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    int down = solve(i+1,j,grid,m,n);
    int right = solve(i,j+1,grid,m,n);

    dp[i][j] = down+right;
    return dp[i][j];
}

int uniquePath(vector<vector<int>>& grid, int m, int n){
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

    cout<<uniquePath(grid,m,n);

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
}