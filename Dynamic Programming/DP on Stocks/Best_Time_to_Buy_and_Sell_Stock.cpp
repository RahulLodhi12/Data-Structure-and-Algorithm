#include<bits/stdc++.h>
using namespace std;

// Approach 3: Optimal
int maxProfit3(vector<int>& prices){
    int n = prices.size();
    int mini = (int)1e9;
    int maxPro = -1;

    for(int i=0;i<n;i++){
        mini = min(mini,prices[i]);
        maxPro = max(maxPro,prices[i]-mini);
    }

    return maxPro;
}

// Approach 2: Using Extra Array
int maxProfit2(vector<int>& prices){
    int n = prices.size();
    int maxi = -1;
    vector<int> rightMax;
    for(int i=n-1;i>=0;i--){
        maxi = max(maxi,prices[i]);
        rightMax.push_back(maxi);
    }
    reverse(rightMax.begin(),rightMax.end());

    int maxPro = 0;
    for(int i=0;i<n;i++){
        maxPro = max(maxPro,rightMax[i]-prices[i]);
    }

    return maxPro;
}

// Approach 1: Using Nested Looping
int maxProfit1(vector<int>& prices){
    int n = prices.size();
    
    int maxPro = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(prices[j] - prices[i]>maxPro){
                maxPro = prices[j] - prices[i];
            }
        }
    }

    return maxPro;
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

    // cout<<maxProfit1(prices);

    // cout<<maxProfit2(prices);

    cout<<maxProfit3(prices);
}