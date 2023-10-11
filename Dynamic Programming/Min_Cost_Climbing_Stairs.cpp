#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
int minClimb(vector<int>& cost, int n){
    //base case
    if(n<=1){
        return 0;
    }
    if(n==2){
        return min(cost[0],cost[1]);
    }

    return min(minClimb(cost,n-1) + cost[n-1], minClimb(cost,n-2) + cost[n-2]);
}


//Approach 2: Using D.P
int minClimbb(vector<int>& cost, int n, vector<int>& dp){
    //base case
    if(n<=1){
        dp[n] = 0;
    }
    if(n==2){
        dp[n] = min(cost[0],cost[1]);
    }

    if(dp[n] != -1){
        return dp[n];
    }


    dp[n] = min(minClimbb(cost,n-1,dp)+cost[n-1], minClimbb(cost,n-2,dp)+cost[n-2]);

    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> cost;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cost.push_back(x);
    }

    // cout<<minClimb(cost, n);

    vector<int> dp(n+1,-1);
    cout<<minClimbb(cost,n,dp);
}