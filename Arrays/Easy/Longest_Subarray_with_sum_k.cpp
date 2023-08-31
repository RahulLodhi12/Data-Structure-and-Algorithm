#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int subArray1(vector<int>& arr, int k){
    int n = arr.size();
    int len = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //subarray = arr[i...j]
            int sum=0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
                // cout<<sum<<" ";
            }
            if(sum==k){
                len = max(len,j-i+1);
            }
            // cout<<endl;
        }
    }
    return len;
}

// Approach 2: Optimizing the Brute Force Approach (Using two loops)
int subArray2(vector<int>& arr, int k){
    int n = arr.size();
    int len=0;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s+=arr[j];
            if(s==k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}


int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k=5;

    // cout<<subArray1(arr,k);

    cout<<subArray2(arr,k);
}