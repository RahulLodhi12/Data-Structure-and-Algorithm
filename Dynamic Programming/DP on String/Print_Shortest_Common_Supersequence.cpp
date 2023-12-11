#include<bits/stdc++.h>
using namespace std;

// Approach: Using Tabulation
string lcs(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    //Code for Print
    int i=n1, j=n2;
    string ans = "";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans += s1[i-1]; 
                i--;
            }
            else{
                ans += s2[j-1];
                j--;
            }
        }
    }

    //Remaining parts of string s1 and s2
    while(i>0){
        ans += s1[i-1];
        i--;
    }

    while(j>0){
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


string shortestCommonSupersequence(string s1, string s2){
    string ans = lcs(s1,s2);
    return ans;
}

int main(){
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);

    cout<<shortestCommonSupersequence(s1,s2);
}