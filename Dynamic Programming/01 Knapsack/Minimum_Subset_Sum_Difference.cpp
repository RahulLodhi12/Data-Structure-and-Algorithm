#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Tabulation
int solve(vector<int>& arr, int n, int sum){

    //step 1
    //create dp matrix
    bool dp[n+1][sum+1];

    //Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }

    //Iterative
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
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
    // return dp[n][k];

    //step 2 -> traverse last row
    int ans = INT_MAX;
    for(int i=0;i<=sum;i++){
        if(dp[n][i] == true){
            int tempAns = abs(i-(sum-i));
            ans = min(ans,tempAns);
        }
    }

    return ans;
}

int subsetSumToK(vector<int>& arr, int n){

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int ans = solve(arr,n,sum);
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

    cout<<subsetSumToK(arr,n);
}