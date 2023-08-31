#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Linear Search
int func1(int arr[], int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

// Approach 2 - Using Binary Search
int func2(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            e=mid-1;
        }
    }
    return s;
}


int main(){
    int arr[] = {3,4,5,2,1};

    cout<<func1(arr,5)<<endl;

    cout<<func2(arr,5);
}