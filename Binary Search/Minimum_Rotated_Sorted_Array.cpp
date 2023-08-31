#include<bits/stdc++.h>
using namespace std;

//Approach 1 - Using Linear Search
int func1(int arr[], int n){
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

//Approach 2 - Using Binary Search
int func2(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        if(arr[s]<arr[e]){ //edge case
            return arr[s];
        }

        int mid=s+(e-s)/2;
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return arr[e];
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // cout<<func1(arr,n);

    cout<<func2(arr,n);
}