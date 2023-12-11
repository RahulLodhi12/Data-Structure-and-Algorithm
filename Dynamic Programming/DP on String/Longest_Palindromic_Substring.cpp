#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
bool checkPal(int i, int j, string& s){
    //base case
    if(i>=j) return true;

    if(s[i]==s[j]) return checkPal(i+1,j-1,s);
    return false;
}

// Approach 2: Using DP
int dp[1001][1001];
bool checkPall(int i, int j, string& s){
    //base case
    if(i>=j) return true;

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i]==s[j]) return dp[i][j] = checkPall(i+1,j-1,s);
    return false;
}

string longestPalindrome(string& s){
    memset(dp,-1,sizeof(dp));

    int maxLen = 0;
    int sp=-1;
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(checkPall(i,j,s)){
                if(j-i+1 > maxLen){
                    maxLen = j-i+1;
                    sp=i;
                }
            }
        }
    }
    return s.substr(sp,maxLen);
}

int main(){
    string s;
    getline(cin,s);

    cout<<longestPalindrome(s);
}