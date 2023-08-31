#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int k, int mid){
    int cowCount=1;
    int lastCow = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-lastCow>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastCow = arr[i];
        }
    }
    return false;
}

int func(vector<int>& arr, int n, int k){
    int s=0;
    int e=arr[n-1]-arr[0];
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr {1,2,8,4,9};
    int k=3;
    int n=arr.size();

    sort(arr.begin(),arr.end());
    cout<<func(arr,n,k);
}