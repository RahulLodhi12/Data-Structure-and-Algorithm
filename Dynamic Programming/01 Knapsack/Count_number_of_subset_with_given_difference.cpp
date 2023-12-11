#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
int solve(vector<int>& arr, int n, int k){
    //base cases
    if(n==0) return k==0;

    int take=0;
    int skip=0;
    if(arr[n-1]<=k){
        take = solve(arr,n-1,k-arr[n-1]);
        skip = solve(arr,n-1,k);
    }
    if(arr[n-1]>k){
        skip = solve(arr,n-1,k);
    }

    return take + skip;
}

// Approach 2: Using Tabulation
int sollve(vector<int>& arr, int n, int k){
    //create dp matrix
    int dp[n+1][k+1];

    //initialization
    for(int i=0;i<k+1;i++){
        dp[0][i] = 0;
    }

    dp[0][0]=1;

    //iterative
    for(int i=1;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            if(arr[i-1]<=j){
                int take = dp[i-1][j-arr[i-1]];
                int skip = dp[i-1][j];
                dp[i][j] = take+skip;
            }
            if(arr[i-1]>j){
                int skip = dp[i-1][j];
                dp[i][j] = skip;
            }
        }
    }

    //final ans;
    return dp[n][k];
}

int countSubset(vector<int>& arr, int diff, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    if((diff+sum)%2 !=0) return 0;

    int s1 = (diff + sum)/2;

    // int ans = solve(arr,n,s1);
    int ans = sollve(arr,n,s1);
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

    int diff;
    cin>>diff;

    cout<<countSubset(arr,diff,n);
}