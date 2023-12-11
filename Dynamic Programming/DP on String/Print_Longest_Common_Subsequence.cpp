#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int m, int n, string s1, string s2){
    //base cases
    if(m==0 || n==0) return 0;

    if(s1[m-1] == s2[n-1]) return 1 + solve(m-1,n-1,s1,s2);
    
    int op1 = solve(m,n-1,s1,s2);
    int op2 = solve(m-1,n,s1,s2);

    return max(op1,op2);
}

// Approach 2: Using Tabulation
int dpp[101][101];
string sollve(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0) dpp[i][j] = 0;
        }
    }

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1] == s2[j-1]) dpp[i][j] = 1 + dpp[i-1][j-1];
            else{
                dpp[i][j] = max(dpp[i][j-1], dpp[i-1][j]);
            }
        }
    }
    // return dpp[n1][n2];

    //Code for Print
    int i = n1, j = n2;
    string ans = "";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        else{
            if(dpp[i-1][j] > dpp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int longestCommonSubsequence(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    int ans = solve(n1,n2,s1,s2);

    // int ans = sollve(s1,s2);
    return ans;
}

int main(){
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);

    // cout<<longestCommonSubsequence(s1,s2);

    cout<<sollve(s1,s2);
}