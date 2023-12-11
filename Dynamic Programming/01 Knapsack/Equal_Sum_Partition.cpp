#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& arr){
    
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    cout<<canPartition(arr);
}