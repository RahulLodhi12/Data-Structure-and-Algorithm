#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int j, vector<int>& arr){
    //base case
    if(i>=j) return 0; //cost is zero.

    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempAns = solve(i,k,arr) + solve(k+1,j,arr) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans,tempAns);
    }

    return ans;
}

int matrixChainMultiplication(vector<int>& arr){
    int n = arr.size();
    int ans = solve(1,n-1,arr);
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

    cout<<matrixChainMultiplication(arr);
}