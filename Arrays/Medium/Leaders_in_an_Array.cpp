#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
vector<int> func1(vector<int>& arr, int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// Approach 2: Optimal Solution
vector<int> func2(vector<int>& arr, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    int n = arr.size();

    // vector<int> ans = func1(arr,n);
    vector<int> ans = func2(arr,n);

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}