#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, vector<int>& height, int n){
    //base cases
    if(i==0) return 0;

    int jumpOne = (int)1e9;
    int jumpTwo = (int)1e9;
    if(i-1>=0) jumpOne = abs(height[i] - height[i-1]) + solve(i-1,height,n);
    if(i-2>=0) jumpTwo = abs(height[i] - height[i-2]) + solve(i-2,height,n);

    return min(jumpOne,jumpTwo);
}

int minJump(vector<int>& height, int n){
    int ans = solve(n-1,height,n);
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

    cout<<minJump(height,n);
}