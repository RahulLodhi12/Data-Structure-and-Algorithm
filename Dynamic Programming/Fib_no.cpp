#include<bits/stdc++.h>
using namespace std;

// Top-down approach
int fib(int n, int dp[]){
    //base case
    if(n==1 || n==0){
        dp[n] = n;
    }

    if(dp[n] != -1){ // if already calculated and store in dp array then return the value, no need to call the recursive function
        return dp[n];
    }

    dp[n] = fib(n-1,dp) + fib(n-2,dp); //store value in dp array

    return dp[n]; //final answer
}

// Bottom-up approach
int fibb(int n){
    int dp[n+1];

    //base case
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//Space-optimisation
int fibbb(int n){
    int prev1 = 0;
    int prev2 = 1;

    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main(){
    int n;
    cin>>n;
    
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }

    // cout<<fib(n, dp);

    // cout<<fibb(n);

    cout<<fibbb(n);
}