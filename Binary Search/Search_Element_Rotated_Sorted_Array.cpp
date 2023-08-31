#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Linear Search
int func1(int arr[], int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}

// Approach 2: Using Binary Search
int minArr(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        if(arr[s]<arr[e]){ //edge case
            return s;
        }

        int mid=s+(e-s)/2;
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return e;
}

int binarySearch(int arr[], int s, int e, int k){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]<k){
            s=mid+1;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=10;

    cout<<func1(arr,n,k)<<endl;

    // int minInd = minArr(arr,n);
    // cout<<minInd<<endl;

    // if(k>=arr[minInd] && k<=arr[n-1]){
    //     cout<<binarySearch(arr,minInd,n-1,k);
    // }
    // else{
    //     cout<<binarySearch(arr,0,minInd-1,k);
    // }
}