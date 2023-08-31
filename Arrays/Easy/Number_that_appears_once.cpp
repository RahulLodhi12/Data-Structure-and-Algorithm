#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int appearOnce1(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        int num = arr[i];
        int cnt=0;
        for(int j=0;j<n;j++){ // linear search
            if(arr[j]==num){
                cnt++;
            }
        }
        if(cnt==1) return num;
    }
    return -1;
}

// Approach 2: Better Solution(Using freq array)
int appearOnce2(vector<int>& arr, int n){
    int maxi = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }

    int freq[maxi+1]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<maxi+1;i++){
        if(freq[i]==1){
            return i;
        }
    }
    return -1;
}

// Approach 3: Optimal Solution(Using XOR)
int appearOnce3(vector<int>& arr, int n){
    int Xor=0;
    for(int i=0;i<n;i++){
        Xor = Xor^arr[i];
    }

    return Xor;
}

int main(){
    vector<int> arr = {1,1,3,7,3};
    int n = arr.size();

    // cout<<appearOnce1(arr,n);

    cout<<appearOnce2(arr,n);

    // cout<<appearOnce3(arr,n);
}