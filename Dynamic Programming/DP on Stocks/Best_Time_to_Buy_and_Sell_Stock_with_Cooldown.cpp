#include<bits/stdc++.h>
using namespace std;

int dp[30001][2];
int solve(int i, int buy, vector<int>& prices){
    //base cases
    if(i>=prices.size()) return 0; //profit is zero(0).

    //provide
    if(dp[i][buy] != -1) return dp[i][buy];

    int profit = 0;
    if(buy==1){ //buy is allowed
        int buyit = -prices[i] + solve(i+1,0,prices);
        int skip = 0 + solve(i+1,1,prices);
        profit = max(buyit, skip);
    }
    else{//buy==0 -> buy is not allowed
        int sellit = prices[i] + solve(i+2,1,prices);
        int skip = 0 + solve(i+1,0,prices);
        profit = max(sellit, skip);
    }

    return dp[i][buy] = profit;
}

int maxProfit1(vector<int>& prices){
    int buy = 1;
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,buy,prices);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> prices;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        prices.push_back(t);
    }

    cout<<maxProfit1(prices);

}