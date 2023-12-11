#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
int solve(int n, int w, vector<int>& val, vector<int>& wt){
    //base case
    if(w==0 || n==0) return 0;

    int take=0;
    int skip=0;
    if(wt[n-1]<=w){
        take = val[n-1] + solve(n,w-wt[n-1],val,wt);
        skip = 0 + solve(n-1,w,val,wt);
    }
    if(wt[n-1]>w){
        skip = 0 + solve(n-1,w,val,wt);
    }

    return max(take,skip);
}

int unboundedKnapsack(int n, int w, vector<int>& val, vector<int>& wt){
    int ans = solve(n,w,val,wt);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> wt;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        wt.push_back(t);
    }

    vector<int> val;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        val.push_back(t);
    }

    int w;
    cin>>w;

    cout<<unboundedKnapsack(n,w,val,wt);
}