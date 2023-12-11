#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int j, int m, int n){
    //base case
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;

    int down = solve(i+1,j,m,n);
    int right = solve(i,j+1,m,n);

    return down+right;
}


// Approach 2: Using DP
int dp[101][101];
int sollve(int i, int j, int m, int n){
    //base case
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    int down = solve(i+1,j,m,n);
    int right = solve(i,j+1,m,n);

    dp[i][j] = down+right;
    return dp[i][j];
}

int uniquePath(int m, int n){
    // int ans = solve(0,0,m,n);

    memset(dp,-1,sizeof(dp));
    int ans = sollve(0,0,m,n);
    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;

    cout<<uniquePath(m,n);
}