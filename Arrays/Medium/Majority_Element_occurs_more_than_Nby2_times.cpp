#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int majority1(vector<int>& arr, int n){
    int v = n/2;
    for(int i=0;i<n;i++){
        int num = arr[i];
        int cnt=0;
        for(int j=i;j<n;j++){
            if(num==arr[j]){
                cnt++;
            }
        }
        if(cnt>v){
            return num;
        }
    }
    return -1;
}

// Approach 2: Better Solution(Using map)
int majority2(vector<int>& arr, int n){
    map<int,int> mpp; // declare map


    for(int i=0;i<n;i++){ // storing occurence in map
        mpp[arr[i]] = mpp[arr[i]]+1;  // OR mpp[arr[i]]++;
    }

    // for(auto it : mpp){
    //     cout<<it.first<<" "<<it.second<<"; ";
    // }

    for(auto it: mpp){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;
}

// Approach 3: Optimal Solution(Moore voting algo)
int majority3(vector<int>& arr, int n){
    int el;
    int cnt=0;
    for(int i=0;i<n;i++){ // select a candidate
        if(cnt==0){
            el = arr[i];
            cnt=1;
        }
        else if(el==arr[i]) cnt++;
        else cnt--;
    }

    int c=0;
    for(int i=0;i<n;i++){ // check the selected candidate is a majority element
        if(el==arr[i]) c++;
    }

    if(c>(n/2)) return el; // if yes, then return it.

    return -1;
}

int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    int n = arr.size();

    // cout<<majority1(arr,n);

    cout<<majority2(arr,n);

    // cout<<majority3(arr,n);
}