#include<bits/stdc++.h>
using namespace std;


// Approach 1: Using Recursion
int func(int i, vector<int>& coins, int amt){
    //base case
    if(amt==0) return 1;
    if(i==coins.size()) return 0;

    if(coins[i]>amt){
        return func(i+1,coins,amt);
    }


    int take = func(i,coins,amt-coins[i]);
    int skip = func(i+1,coins,amt);

    return take+skip;
}

int change(vector<int>& coins, int amt){
    int ans = func(0,coins,amt);

    return ans;
}


// Approach 2: Using DP(2-D array)
int dp[301][5001];
int funcc(int i, vector<int>& coins, int amt){
    //base case
    if(amt==0) return 1;
    if(i==coins.size()) return 0;

    if(coins[i]>amt) return funcc(i+1,coins,amt);

    //provide
    if(dp[i][amt] != -1) return dp[i][amt];

    int take = funcc(i,coins,amt-coins[i]);
    int skip = funcc(i+1,coins,amt);

    dp[i][amt] = take+skip;
    return dp[i][amt];
}

int changee(vector<int>& coins, int amt){
    memset(dp,-1,sizeof(dp));

    int ans = funcc(0,coins,amt);

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        coins.push_back(t);
    }

    int amt;
    cin>>amt;

    // cout<<change(coins,amt);

    cout<<changee(coins,amt);
}