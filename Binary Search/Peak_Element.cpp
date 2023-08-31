#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Linear Search
int func1(int arr[], int n){
    if(arr[0]>=arr[1]){
        return arr[0]; // first
    }
    for(int i=1;i<n-1;i++){
        if(arr[i]>=arr[i+1] && arr[i]>=arr[i-1]){
            return arr[i];
        }
    }
    return arr[n-1]; // last
}

// Approach 2 - Using Binary Search
int func2(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        int mid = s+(e-s)/2;
        if(mid==0){ //edge case
            if(arr[0]>arr[1]){
                return arr[0];
            }
            return arr[1];
        }

        if(mid==n-1){ //edge case
            if(arr[n-1]>arr[n-2]){
                return arr[n-1];
            }
            return arr[n-2];
        }

        // check if mid is the peak element
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return arr[mid];
        }

        // if peak present in left-side
        if(arr[mid]<arr[mid-1]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return arr[s];
}

int main(){
    int arr[] = {1,2,1,3,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<func1(arr,n);

    // cout<<func2(arr,n);
}