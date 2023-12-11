#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
bool solve(int i, int j, string s, string p){
    //base cases
    if(i<0 && j<0) return true;
    if(i>=0 && j<0) return false;
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k] != '*') return false; 
        }
        return true;
    }

    //if match
    if(p[j]=='?' || s[i]==p[j]) return solve(i-1,j-1,s,p);

    else if(p[j]=='*') return (solve(i,j-1,s,p) || solve(i-1,j,s,p)); //return (empty string OR(||) any string)

    return false;
}


// Approach 2: Using DP
int dp[2001][2001];
bool sollve(int i, int j, string s, string p){
    //base cases
    if(i<0 && j<0) return true;
    if(i>=0 && j<0) return false;
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k] != '*') return false; 
        }
        return true;
    }

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    //if match
    if(p[j]=='?' || s[i]==p[j]) return dp[i][j] = sollve(i-1,j-1,s,p);

    else if(p[j]=='*') return dp[i][j] = (sollve(i,j-1,s,p) || sollve(i-1,j,s,p)); //return (empty string OR(||) any string)

    return false;
}

bool isMatch(string s, string p){
    int n = s.length();
    int m = p.length();

    // bool ans = solve(n-1,m-1,s,p);

    memset(dp,-1,sizeof(dp));
    bool ans = sollve(n-1,m-1,s,p);
    return ans;
}

int main(){
    string s;
    string p;

    getline(cin,s);
    getline(cin,p);

    cout<<isMatch(s,p);
}