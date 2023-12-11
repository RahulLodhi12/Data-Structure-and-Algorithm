#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using DP
int solve(int i, int buy, int limit, vector<int>& prices){
    //base cases
    if(i==prices.size()) return 0;
    if(limit==0) return 0;

    int profit = 0;
    if(buy==1){
        int buyit = -prices[i] + solve(i+1,0,limit,prices);
        int skip = 0 + solve(i+1,1,limit,prices);
        profit = max(buyit,skip);
    }
    else{//buy==0 -> buy not allowed
        int sellit = prices[i] + solve(i+1,1,limit-1,prices);
        int skip = 0 + solve(i+1,0,limit,prices);
        profit = max(sellit,skip);
    }

    return profit;
}

int maxProfit1(vector<int>& prices){
    int buy=1;
    int limit=2;

    int ans = solve(0,buy,limit,prices);
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