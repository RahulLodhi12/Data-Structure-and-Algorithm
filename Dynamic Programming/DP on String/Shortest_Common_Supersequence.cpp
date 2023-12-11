#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int n, int m, string s1, string s2){
    //base cases
    if(n==0 || m==0) return 0;


    if(s1[n-1]==s2[m-1]) return 1 + solve(n-1,m-1,s1,s2);

    int op1 = solve(n,m-1,s1,s2);
    int op2 = solve(n-1,m,s1,s2);

    return max(op1,op2);
}


// Approach 2: Using DP
int dp[101][101];
int sollve(int n, int m, string s1, string s2){
    //base cases
    if(n==0 || m==0) return 0;

    //provide
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n-1]==s2[m-1]) return 1 + sollve(n-1,m-1,s1,s2);

    int op1 = sollve(n,m-1,s1,s2);
    int op2 = sollve(n-1,m,s1,s2);

    return dp[n][m] = max(op1,op2);
}

int longestCommonSubsequence(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    // int ans = solve(n1,n2,s1,s2);

    memset(dp,-1,sizeof(dp));
    int ans = sollve(n1,n2,s1,s2);
    return ans;
}

int shortestCommonSupersequence(string s1, string s2){
    int lcs = longestCommonSubsequence(s1,s2);
    return s1.length() + s2.length() - lcs;
}

int main(){
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);

    cout<<shortestCommonSupersequence(s1,s2);
}