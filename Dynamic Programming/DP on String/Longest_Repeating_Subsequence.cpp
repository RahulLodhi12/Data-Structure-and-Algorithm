#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
int solve(int i, int j, string s1, string s2){
    //base case
    if(i<0 || j<0) return 0;

    if(s1[i]==s2[j] && i!=j) return 1 + solve(i-1,j-1,s1,s2);

    int op1 = solve(i,j-1,s1,s2);
    int op2 = solve(i-1,j,s1,s2);

    return max(op1,op2);
}

//Approach 2: Tabulation
int dp[1001][1001];
int sollve(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1] && i!=j) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[n][m];
}

int LongestRepeatingSubsequence(string str){
    string s1 = str;
    string s2 = str;

    int n1 = s1.length();
    int n2 = s2.length();

    // int ans = solve(n1-1,n2-1,s1,s2);

    int ans = sollve(s1,s2);
    return ans;
}

int main(){
    string str;

    getline(cin,str);

    cout<<LongestRepeatingSubsequence(str);
}