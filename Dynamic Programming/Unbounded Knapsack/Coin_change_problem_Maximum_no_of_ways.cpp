#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
int solve(int n, vector<int>& coins, int amt){
    //base cases
    if(amt==0) return 1; //1 way
    if(n==0) return 0; //0 way

    int take=0;
    int skip=0;
    if(coins[n-1]<=amt){
        take = solve(n,coins,amt-coins[n-1]);
        skip = solve(n-1,coins,amt);
    }
    if(coins[n-1]>amt){
        skip = solve(n-1,coins,amt);
    }

    return take+skip;
}

int coinChange(vector<int>& coins, int n, int amt){
    int ans = solve(n,coins,amt);
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

    cout<<coinChange(coins,n,amt);
}