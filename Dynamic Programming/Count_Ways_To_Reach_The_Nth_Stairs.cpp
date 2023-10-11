#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int count(int n, int i){
    //base cases
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }

    return count(n,i+1) + count(n,i+2);
}


// Approach 2: Using Dynamic Programming
int countt(int n, int i, int dp[]){
    //base cases
    if(i==n){
        dp[i] = 1;
    }
    if(i>n){
        dp[i] = 0;
    }

    if(dp[i]!= -1){ // provide dp array stored value
        return dp[i];
    }

    dp[i] = countt(n,i+1,dp) + countt(n,i+2,dp); // store value in dp array

    return dp[i]; //final ans
}

int main(){
    int n;
    cin>>n;

    // cout<<count(n,0); // 0 means starting stair

    int dp[n+2];
    for(int i=0;i<n+2;i++){
        dp[i] = -1;
    }


    cout<<countt(n,0,dp);
}