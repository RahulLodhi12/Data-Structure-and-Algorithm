#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
bool func1(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                return false;
            }
        }
    }
    return true;
}

// Approach 2: Single Traversal
bool func2(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i]){
            return false;
        }
    }
    return true;
}


int main(){
    vector<int> arr={1,2,2,3,4,4};

    // cout<<func1(arr);

    cout<<func2(arr);
}