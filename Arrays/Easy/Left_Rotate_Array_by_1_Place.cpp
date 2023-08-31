#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
void leftRotate1(vector<int>& arr){
    int n = arr.size();
    int temp[n];
    for(int i=1;i<n;i++){
        temp[i-1] = arr[i];
    }
    temp[n-1]=arr[0];

    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}


// Approach 2: Optimal Sol.
void leftRotate2(vector<int>& arr){
    int n = arr.size();
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5};

    // leftRotate1(arr);

    leftRotate2(arr);
}