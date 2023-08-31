#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
void sort012_app1(vector<int>& arr, int n){
    sort(arr.begin(),arr.end());
}

// Approach 2: Better Solution
void sort012_app2(vector<int>& arr, int n){
    int cnt0=0, cnt1=0, cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
        else if(arr[i]==2) cnt2++;
    }

    // Replacing 0s,1s and 2s
    for(int i=0;i<cnt0;i++) arr[i]=0;

    for(int i=cnt0;i<cnt0+cnt1;i++) arr[i]=1;

    for(int i=cnt0+cnt1;i<n;i++) arr[i]=2;
}

// Approach 3: Optimal Solution(Dutch National flag algorithm)
void sort012_app3(vector<int>& arr, int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr={2,0,2,1,1,0};
    int n=arr.size();

    // sort012_app1(arr,n);

    // sort012_app2(arr,n);

    sort012_app3(arr,n);

    for(auto it: arr){
        cout<<it<<" ";
    }
}