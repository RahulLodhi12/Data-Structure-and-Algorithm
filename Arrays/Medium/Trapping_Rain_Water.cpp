#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height){
    int n = height.size();
    int leftMax[n];
    int maxLeft = INT_MIN;
    for(int i=0;i<height.size();i++){
        maxLeft = max(maxLeft,height[i]);
        leftMax[i] = maxLeft;
    }

    // for(int i=0;i<n;i++){
    //     cout<<leftMax[i]<<" ";
    // }
    // cout<<endl;
    int rightMax[n];
    int maxRight = INT_MIN;
    for(int i=n-1;i>=0;i--){
        maxRight = max(maxRight,height[i]);
        rightMax[i] = maxRight;
    }

    // for(int i=0;i<n;i++){
    //     cout<<rightMax[i]<<" ";
    // }

    //apply formula
    int totalTrap = 0;
    for(int i=0;i<n;i++){
        totalTrap += min(leftMax[i],rightMax[i]) - height[i];
    }

    return totalTrap;
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

    cout<<trap(height);
}