#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
bool solve(vector<int>& arr, int n, int k){
    //base cases
    if(n==0) return false;
    if(k==0) return true;

    bool take = false;
    bool skip = false;
    if(arr[n-1]<=k){
        take = solve(arr,n-1,k-arr[n-1]);
        skip = solve(arr,n-1,k);
    }

    if(arr[n-1]>k){
        skip = solve(arr,n-1,k);
    }

    return take || skip;
}


//Approach 2: Using Tabulation
bool sollve(vector<int>& arr, int n, int k){
    //create dp matrix
    bool dp[n+1][k+1];

    //Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }

    //Iterative
    for(int i=1;i<n+1;i++){
        for(int j=1;j<k+1;j++){
            if(arr[i-1]<=j) {
                int take = dp[i-1][j-arr[i-1]];
                int skip = dp[i-1][j];
                dp[i][j] = take || skip;
            }
            if(arr[i-1]>j){
                int skip = dp[i-1][j];
                dp[i][j] = skip;
            }
        }
    }

    //final ans
    return dp[n][k];
}

bool subsetSumToK(vector<int>& arr, int n, int k){
    // bool ans = solve(arr,n,k);

    bool ans = sollve(arr,n,k);
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

    int k;
    cin>>k;

    cout<<subsetSumToK(arr,n,k);
}