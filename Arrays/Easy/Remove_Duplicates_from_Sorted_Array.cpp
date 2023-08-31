#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Brute Force
int removeDup1(int arr[], int n){
    set<int> box;
    for(int i=0;i<n;i++){
        box.insert(arr[i]); // O(N.logN)
    }
    int k = box.size();
    int p=0;
    for(auto it: box){
        arr[p++] = it; // O(N)
    }
    return k;
}

// Approach 2 : Two Pointer
int removeDup2(int arr[], int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main(){
    int arr[] = {1,1,2,2,2,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // int k = removeDup1(arr, n);
    // for(int i=0; i<k; i++){
    //     cout<<arr[i]<<" ";
    // }

    int k = removeDup2(arr, n);
    cout<<k<<endl;
    for(int i=0; i<k; i++){
        cout<<arr[i]<<" ";
    }
}