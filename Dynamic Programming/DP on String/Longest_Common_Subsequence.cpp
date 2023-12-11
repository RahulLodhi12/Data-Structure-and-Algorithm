#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int n, int m, string s1, string s2){
    //base case
    if(n==0 || m==0) return 0;

    if(s1[n-1]==s2[m-1]) return 1 + solve(n-1,m-1,s1,s2);

    int op1 = solve(n,m-1,s1,s2);
    int op2 = solve(n-1,m,s1,s2);

    return max(op1,op2);
}

// Approach 2: Using DP
int dp[1001][1001]; 
int sollve(int n, int m, string s1, string s2){
    //base case
    if(n==0 || m==0) return 0;

    //provide
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n-1]==s2[m-1]) return 1 + sollve(n-1,m-1,s1,s2);
    
    int op1 = sollve(n,m-1,s1,s2);
    int op2 = sollve(n-1,m,s1,s2);

    return dp[n][m] = max(op1,op2);
}


// Approach 3: Tabulation
int dpp[1001][1001];
int solvee(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dpp[i][j] = 0;
        }
    }

    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=m+1;j++){
            if(s1[i-1] == s2[j-1]){
                dpp[i][j] = 1 + dpp[i-1][j-1];
            }
            else{
                dpp[i][j] = max(dpp[i][j-1], dpp[i-1][j]);
            }
        }
    }

    return dpp[n][m];
}

int longestCommonSubsequence(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    // int ans = solve(n1,n2,s1,s2);

    // memset(dp,-1,sizeof(dp));
    // int ans = sollve(n1,n2,s1,s2);

    int ans = solvee(s1,s2);
    return ans;
}

int main(){
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);

    cout<<longestCommonSubsequence(s1,s2);
}