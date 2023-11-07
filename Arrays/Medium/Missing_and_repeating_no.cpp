#include<bits/stdc++.h>
using namespace std;

// Approach: Summation
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    int s1 = 0;
    for(int i=0;i<n;i++){
        s1 += arr[i];
    }
    int s11 = (n*(n+1))/2;
    //x-y = s1-s11
    int val1 = s1-s11; //eq.1

    int s2=0;
    for(int i=0;i<n;i++){
        s2 += arr[i]*arr[i];
    }
    int s22 = (n*(n+1)*(2*n+1))/6;
    //x^2 - y^2 = s2-s22
    int val2 = s2-s22; //eq.2

    //x+y = x^2-y^2/x-y
    int val3 = val2/val1;

    //(x-y) + (x+y)
    int x = (val1+val3)/2;
    int y = val3-x;

    return {y,x};
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

    pair<int,int> ans;
    ans = missingAndRepeating(arr, arr.size());
    cout<<ans.first<<" "<<ans.second<<endl;
}