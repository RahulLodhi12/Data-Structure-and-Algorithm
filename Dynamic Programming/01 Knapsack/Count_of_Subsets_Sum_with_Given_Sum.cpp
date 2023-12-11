#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int n, vector<int>& arr, int k){
    //base cases
    if(k==0) return 1;
	if(n==0) return 0;

	int take=0;
	int skip=0;
	if(arr[n-1]<=k){
		take = solve(n-1,arr,k-arr[n-1]);
		skip = solve(n-1,arr,k);
	}
	if(arr[n-1]>k){
		skip = solve(n-1,arr,k);
	}

	return take+skip;
}


// Approach 2: Using Tabulation
int sollve(int n, vector<int>& arr, int k){
    //create dp matrix
    int dp[n+1][k+1];

    //initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }

    //iterative
    for(int i=1;i<n+1;i++){
        for(int j=1;j<k+1;j++){
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

int findWays(vector<int>& arr, int k){
    int n = arr.size();
    // int ans = solve(n,arr,k);

    int ans = sollve(n,arr,k);
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

    cout<<findWays(arr,k);
}