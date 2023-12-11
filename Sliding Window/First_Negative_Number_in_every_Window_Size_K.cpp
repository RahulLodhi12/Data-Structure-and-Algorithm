#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
vector<int> firstNegative(vector<int>& arr, int n, int k){
    vector<int> ans(n-k+1);
    int p=0;
    for(int i=0;i<=n-k;i++){
        bool flag=false;
        for(int j=i;j<i+k;j++){
            if(arr[j]<0){
                ans[p++] = arr[j];
                flag = true;
                break;
            }
        }
        if(flag==false){
            ans[p++] = 0;
        }
    }
    return ans;
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

    int k;
    cin>>k;

    vector<int> ans = firstNegative(arr,n,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}