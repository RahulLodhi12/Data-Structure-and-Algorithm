#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int j, vector<vector<int>>& tri, int n){
    //base cases
    if(j>=n) return (int)1e9;
    if(i==n-1) return tri[i][j];

    int down = tri[i][j] + solve(i+1,j,tri,n);
    int rightDia = tri[i][j] + solve(i+1,j+1,tri,n);

    return min(down,rightDia);
}


// Approach 2: Using DP
int dp[201][201];
int sollve(int i, int j, vector<vector<int>>& tri, int n){
    //base cases
    if(j>=n) return (int)1e9;
    if(i==n-1) return tri[i][j];

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    int down = tri[i][j] + solve(i+1,j,tri,n);
    int rightDia = tri[i][j] + solve(i+1,j+1,tri,n);

    return dp[i][j] = min(down,rightDia);
}

int minTotal(vector<vector<int>>& tri){
    int n = tri.size(); //row size
    // int ans = solve(0,0,tri,n);

    memset(dp,-1,sizeof(dp));
    int ans = sollve(0,0,tri,n);
    return ans;
}

int main(){
    vector<vector<int>> tri = {{1},
                               {2, 3},
                               {3, 6, 7},
                               {8, 9, 6, 10}};

    cout<<minTotal(tri);
}