#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int stCount=1;
    int pageSum = 0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum += arr[i];
        }
        else{
            stCount++;
            if(stCount>m || arr[i]>mid){
                return false;
            }
            pageSum = 0; //next student
            pageSum += arr[i];
        }
    }
    return true;
}

int func(int arr[], int n, int m){
    int s=0;
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e=sum;

    int ans=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(arr,n,m,mid)){
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
    int arr[]={5,17,100,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m=4;

    cout<<func(arr,n,m);
}