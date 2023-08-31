#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int pCount=1;
    int boardSum = 0;
    for(int i=0;i<n;i++){
        if(boardSum+arr[i]<=mid){
            boardSum += arr[i];
        }
        else{
            pCount++;
            if(pCount>m || arr[i]>mid){
                return false;
            }
            boardSum = 0; //next student
            boardSum += arr[i];
        }
    }
    return true;
}

int func(int arr[], int n, int k){
    int s=0;
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e=sum;

    int ans=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[]={5,10,30,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;

    cout<<func(arr,n,k);
}