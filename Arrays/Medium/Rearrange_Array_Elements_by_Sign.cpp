#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
vector<int> func1(vector<int>& arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    for(int i=0;i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    return arr;
}


// Approach 2: Optimal Solution (Two pointer)
vector<int> func2(vector<int> & arr, int n){
    int pInd=0,  nInd=1; // two pointer
    vector<int> temp(n,0); // temp(size, intialized)

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            temp[pInd] = arr[i];
            pInd = pInd+2;
        }
        else{
            temp[nInd] = arr[i];
            nInd = nInd+2;
        }
    }
    return temp;
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // vector<int> ans = func1(arr,n);
    vector<int> ans = func2(arr,n);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}