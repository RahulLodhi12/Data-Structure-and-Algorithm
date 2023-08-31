#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int missNo1(vector<int>& arr, int n){
    for(int i=1;i<=n;i++){
        bool flag = 0;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}

// Appraoch 2: Better Solution(Using Hash array)
int missNo2(vector<int>& arr, int n){
    int hash[n+1] = {0}; // hash or freq array

    for(int i=0;i<arr.size();i++){
        hash[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}

// Approach 3.1: Optimal Solution(Summation)
int missNo3_1(vector<int>& arr, int n){
    int s1 = (n*(n+1))/2;
    int s2 = 0;
    for(int i=0;i<arr.size();i++){
        s2 += arr[i];
    }

    return s1-s2;
}


// Appraoch 3.2: Optimal Solution(XOR)
int missNo3_2(vector<int>& arr, int n){
    int x1 = 0;
    int x2 = 0;
    for(int i=0;i<arr.size();i++){
        x2 = x2 ^arr[i];
        x1 = x1^(i+1);
    }
    x1 = x1^n;

    return x1^x2;
}

int main(){
    vector<int> arr = {1,2,4,5};
    int n=5;

    // cout<<missNo1(arr,n);

    // cout<<missNo2(arr,n);

    // cout<<missNo3_1(arr,n);

    cout<<missNo3_2(arr,n);
}