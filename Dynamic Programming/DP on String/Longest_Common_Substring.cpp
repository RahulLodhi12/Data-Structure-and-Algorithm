#include<bits/stdc++.h>
using namespace std;

// Approach : Using Tabulation
int dp[1001][1001];
int longestCommonSubstr(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }

    int maxLen=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }

        }
    }
    return maxLen;
}

int main(){
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);

    cout<<longestCommonSubstr(s1,s2);
}