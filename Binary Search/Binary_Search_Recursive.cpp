#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int s, int e, int k){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(k>arr[mid])
            return binarySearch(arr,mid+1,e,k);
        else if(k<arr[mid])
            return binarySearch(arr,s,mid-1,k);
        else
            return mid;
    }
    return -1;
}

int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};

    cout<<binarySearch(arr,0,9,38)<<endl;
}