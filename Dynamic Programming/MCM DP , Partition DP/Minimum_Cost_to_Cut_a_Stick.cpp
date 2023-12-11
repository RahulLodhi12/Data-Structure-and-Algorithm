#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
int solve(int i, int j, vector<int>& cuts){
    //base cases
    if(i>j) return 0;

    int ans=INT_MAX;
    for(int k=i;k<=j;k++){
        int tempAns = solve(i,k-1,cuts) + solve(k+1,j,cuts) + cuts[j+1] - cuts[i-1];
        ans = min(ans,tempAns);
    }

    return ans;
}

int minCost(int n, vector<int>& cuts, int size){
    //insert 0 at begin
    cuts.insert(cuts.begin(),0);

    //insert n at end
    cuts.push_back(n);

    //sort cuts array
    sort(cuts.begin(),cuts.end());

    int ans = solve(1,size,cuts);
    return ans;
}

int main(){
    int size;
    cin>>size;

    vector<int> cuts;

    for(int i=0;i<size;i++){
        int t;
        cin>>t;
        cuts.push_back(t);
    }

    int n;
    cin>>n;

    cout<<minCost(n,cuts,size);
}