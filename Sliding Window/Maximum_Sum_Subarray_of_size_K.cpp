#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int>& arr, int n, int k){
    int i=0;
    int j=0;
    int ans=0;
    int sum=0;
    while(j<n){
        sum += arr[j];
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1 == k){
            ans = max(ans,sum);
            sum -= arr[i];
            j++;
            i++;
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

    cout<<maxSumSubarray(arr,n,k);

}