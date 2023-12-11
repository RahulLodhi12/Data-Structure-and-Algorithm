#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int j, string s1, string s2){
    //base cases
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(s1[i]==s2[j]) return solve(i-1,j-1,s1,s2);

    int insert = 1 + solve(i,j-1,s1,s2);
    int remove = 1 + solve(i-1,j,s1,s2);
    int replace = 1 + solve(i-1,j-1,s1,s2);

    return min({insert,remove,replace});
}

// Approach 2: Using DP


int minDistance(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    int ans = solve(n1-1,n2-1,s1,s2);
    return ans;
}

int main(){
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);

    cout<<minDistance(s1,s2);
}