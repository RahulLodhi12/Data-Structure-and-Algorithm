#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int s, int e, int k){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(k>arr[mid])
            s=mid+1;
        else if(k<arr[mid])
            e=mid-1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};

    cout<<binarySearch(arr,0,9,23)<<endl;
}