#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int p, vector<int>& arr){
    //base cases
    if(i==arr.size() || p==arr.size()) return 0;

    int take = 0;
    int skip = 0;
    if(p==-1 || arr[i]>arr[p])
        take = 1 + solve(i+1,i,arr);
    
    skip = 0 + solve(i+1,p,arr);

    return max(take,skip);
}


// Approach 2: Using Bottom-Up
int sollve(vector<int>& arr){
    int n = arr.size();

    //dp array
    vector<int> dp(n,1);

    int maxLen=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                maxLen = max(maxLen,dp[i]);
            }
        }
    }

    //find max in dp-array
    // int maxLen = 0;
    // for(int i=0;i<n;i++){
    //     maxLen = max(maxLen,dp[i]);
    // }
    // return maxLen;

    return maxLen;
}


int lengthOfLIS(vector<int>& arr){
    // int ans = solve(0,-1,arr);

    int ans = sollve(arr);
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

    cout<<lengthOfLIS(arr);
}