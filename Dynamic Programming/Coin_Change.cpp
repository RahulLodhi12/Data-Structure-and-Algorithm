#include<bits/stdc++.h>
using namespace std;

int dp[10000];


// Approach 1: Using Recursion
int coinChange(vector<int>& coins, int amt){
    int n=coins.size();
    int minCoin = INT_MAX;

    //base case
    if(amt==0){
        return 0;
    }

    for(int i=0;i<n;i++){
        if(amt-coins[i]>=0){
            minCoin = min(minCoin + 0LL, coinChange(coins,amt-coins[i]) + 1LL);
        }
    }

    return minCoin;
}


// Approach 2: Using DP
int coinChangee(vector<int>& coins, int amt){
    int n=coins.size();
    int minCoin = INT_MAX;

    //base case
    if(amt==0){
        dp[amt] = 0;
    }

    //provide
    if(dp[amt] != -1){
        return dp[amt];
    }

    for(int i=0;i<n;i++){
        if(amt-coins[i]>=0){
            minCoin = min(minCoin + 0LL, coinChange(coins,amt-coins[i]) + 1LL);
        }
    }
    dp[amt] = minCoin;
    return dp[amt];
}


// Approach 3: Using DP(Using Tabulation)
int coinnChange(vector<int>& coins, int amt){
    vector<int> dpp(amt+1,amt+1);

    //base case
    dpp[0] = 0;

    for(int i=0;i<coins.size();i++){
        for(int j=coins[i];j<=amt;j++){
            dpp[j] = min(dpp[j],dpp[j-coins[i]]+1);
        }
    }

    return dpp[amt]==amt+1 ? -1 : dpp[amt];
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

    // cout<<coinChange(cost,amt);

    // memset(dp,-1,sizeof(dp));
    // int ans = coinChangee(coins,amt);
    // if(ans==INT_MAX){
    //     cout<<"-1";
    // }
    // else{
    //     cout<<ans;
    // }


    cout<<coinnChange(coins,amt);
    

}