#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
void leftRotate1(vector<int>& arr, int k){
    int n=arr.size();
    k = k % n; // Get the effective number of rotations
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i] = arr[i];  // step 1
    }

    for(int i=k;i<n;i++){
        arr[i-k] = arr[i]; // step 2
    }
    for(int i=k+1;i<n;i++){
        arr[i] = temp[i-(k+1)]; // step 3
    }
}

// Approach 2: Reversal Algo.
void reverse(vector<int>& arr, int s, int e){
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void leftRotate2(vector<int>& arr, int k){
    int n=arr.size();
    k = k % n; // Get the effective number of rotations
    
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);

    reverse(arr,0,n-1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k=3;

    cout<<"Before Rotation: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // leftRotate1(arr,k);
    leftRotate2(arr,k);

    cout<<"After Rotation: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}