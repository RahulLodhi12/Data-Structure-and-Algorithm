#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int func1(vector<int>& arr, int n){
    int maxPro=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                int pro = arr[j]-arr[i];
                if(pro>maxPro){
                    maxPro = pro;
                }
            }
        }
    }
    return maxPro;
}


// Approach 2: Optimal Solution
int func2(vector<int>& arr, int n){
    int mini = INT_MAX;
    int maxPro=0;
    for(int i=0;i<n;i++){
        // step 1
        if(arr[i]<mini){
            mini = arr[i];
        }
        
        // step 2
        int pro = arr[i]-mini;

        // step 3
        if(pro>maxPro){
            maxPro = pro;
        }
    }
    return maxPro;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    int n = arr.size();

    // cout<<func1(arr,n);

    cout<<func2(arr,n);
}