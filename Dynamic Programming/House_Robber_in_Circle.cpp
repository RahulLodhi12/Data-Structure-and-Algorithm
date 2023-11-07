#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i,int n, vector<int>& nums){
    //base case
    if(i>=n+1) return 0;

    return max(nums[i] + solve(i+2,n,nums), solve(i+1,n,nums)); //max(take,skip)
}
int rob(vector<int>& nums){
    int n = nums.size();
    int case1 = solve(0,n-2,nums);
    int case2 = solve(1,n-1,nums);

    return max(case1,case2);
}

// Approach 2: Using DP
int dp[1001];
int sollve(int i, int n, vector<int>& nums){
    //base case
    if(i>=n+1) return 0;

    //provide
    if(dp[i] != -1) return dp[i];

    int take = nums[i] + sollve(i+2,n,nums);
    int skip = sollve(i+1,n,nums);

    dp[i] = max(take,skip);

    return dp[i];
}
int robb(vector<int>& nums){
    int n = nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);


    memset(dp,-1,sizeof(dp));
    int case1 = sollve(0,n-2,nums);

    memset(dp,-1,sizeof(dp));
    int case2 = sollve(1,n-1,nums);

    return max(case1,case2);
}


int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }

    // cout<<rob(nums);

    cout<<robb(nums);
}