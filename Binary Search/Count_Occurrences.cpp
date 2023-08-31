#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Linear Search
int func1(int arr[], int n, int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(k==arr[i]){
            cnt++;
        }
    }
    return cnt;
}


// Approach 2 - Using Binary Search
int firstPos(int arr[], int s, int e, int k){
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(k>arr[mid]){
            s=mid+1;
        }
        else if(k<arr[mid]){
            e=mid-1;
        }
        else{
            ans=mid;
            e=mid-1;
        }
    }
    return ans;
}
int lastPos(int arr[], int s, int e, int k){
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(k>arr[mid]){
            s=mid+1;
        }
        else if(k<arr[mid]){
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[]={1, 1, 2, 2, 2, 2, 3};

    cout<<func1(arr,7,2)<<endl;

    int f = firstPos(arr,0,6,4);
    int l = lastPos(arr,0,6,4);
    int formula = l-f+1;
    if(f==-1 && l==-1){
        cout<<"0"<<endl;
    }
    else{
        cout<<formula<<endl;
    }
    
}