#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(vector<int>& weight, vector<int>& value, int n, int capacity){
    //base cases
    if(n==0 || capacity==0) return 0; //maxProfit is zero.


    int take=0;
    int skip=0;
    if(weight[n-1]<=capacity){
        take = value[n-1] + solve(weight,value,n-1,capacity-weight[n-1]);
        skip = 0 + solve(weight,value,n-1,capacity);
    }

    if(weight[n-1]>capacity){
        skip = 0 + solve(weight,value,n-1,capacity);
    }

    return max(take,skip);
}


//Approach 2: Using Tabulation
int sollve(vector<int>& weight, vector<int>& value, int n, int w){
    //create dp matrix
    int dp[n+1][w+1];

    //initialzation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }


    //iterative
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(weight[i-1]<=j){
                int take = value[i-1] + dp[i-1][j-weight[i-1]];
                int skip = 0 + dp[i-1][j];
                dp[i][j] = max(take,skip);
            }
            else if(weight[i-1]>j){
                int skip = 0 + dp[i-1][j];
                dp[i][j] = skip;
            }
        }
    }

    return dp[n][w];
}

int knapsack(vector<int>& weight, vector<int>& value, int n, int capacity){
    // int ans = solve(weight,value,n,capacity);

    int ans = sollve(weight,value,n,capacity);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> weight;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        weight.push_back(t);
    }

    vector<int> value;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        value.push_back(t);
    }

    int capacity;
    cin>>capacity;

    cout<<knapsack(weight,value,n,capacity);

}