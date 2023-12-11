#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int lcs(int n, int m, string s1, string s2){
    //base cases
    if(n==0 || m==0) return 0;

    if(s1[n-1]==s2[m-1]) return 1 + lcs(n-1,m-1,s1,s2);

    int op1 = lcs(n,m-1,s1,s2);
    int op2 = lcs(n-1,m,s1,s2);

    return max(op1,op2);
}


// Approach 2: Using DP
// Tommorow

int minInsertions(string s){
    string t = s;
    reverse(t.begin(),t.end());
    int n = s.length();

    int lps = lcs(n,n,s,t);
    return n-lps;
}

int main(){
    string s;
    getline(cin,s);

    cout<<minInsertions(s);
}