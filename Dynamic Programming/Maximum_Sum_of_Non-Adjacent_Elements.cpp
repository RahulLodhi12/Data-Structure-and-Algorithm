#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, vector<int>& arr){
    //base case
    if(i>=arr.size()) return 0;

    return max(arr[i] + solve(i+2,arr), solve(i+1,arr)); //max(take,skip)
}


// Approach 2: Using DP
int dp[1001];
int solvee(int i, vector<int>& arr){
    //base case
    if(i>=arr.size()) return 0;

    //provide
    if(dp[i] != -1) return dp[i];

    dp[i] = max(arr[i] + solve(i+2,arr), solve(i+1,arr)); //max(take,skip)

    return dp[i];
}

// Approach 3: Using DP(tabulation)
int dpp[1001];
int sollve(int i, vector<int>& arr){
    //base case
    dpp[0] = arr[0];

    for(int i=1;i<arr.size();i++){
        // int take = arr[i] + dpp[i-2];
        int take = arr[i] + 0;
        if(i>1) take += dpp[i-2];
        int skip = dpp[i-1];
        dpp[i] = max(take,skip);
    }

    return dpp[arr.size()-1];
}

// Approach 4: Space Optimization
int ssolve(vector<int>& arr){
    //base case
    int prev1 = arr[0]; //i-1
    int prev2 = 0;      //i-2

    for(int i=1;i<arr.size();i++){
        int take = arr[i] + 0;
        if(i>1) take += prev2;
        int skip = prev1;
        int curr = max(take,skip);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maxSum(vector<int>& arr){
    memset(dp,-1,sizeof(dp));
    // int ans = solve(0,arr);

    // int ans = solvee(0,arr);

    // int ans = sollve(0,arr);

    int ans = ssolve(arr);

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    cout<<maxSum(arr);
}