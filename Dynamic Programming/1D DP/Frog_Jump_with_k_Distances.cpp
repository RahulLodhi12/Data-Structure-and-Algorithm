#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i,vector<int>& height, int n, int k){
    //base cases
    if(i==0) return 0;

    int minSum = (int)1e9;
    for(int jump=1;jump<=k;jump++){
        if(i-jump>=0) minSum = min(minSum, abs(height[i] - height[i-jump]) + solve(i-jump,height,n,k));
    }

    return minSum;
}


// Approach 2: Using DP
// Tommorrow

int minCost(vector<int>& height, int n, int k){
    int ans = solve(n-1,height,n,k);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> height;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        height.push_back(t);
    }

    int k;
    cin>>k;

    cout<<minCost(height,n,k);
}