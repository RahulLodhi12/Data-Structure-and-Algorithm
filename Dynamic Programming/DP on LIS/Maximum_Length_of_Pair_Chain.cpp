#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int p, vector<vector<int>>& pairs){
    //base cases
    if(i==pairs.size()) return 0;

    int take=0;
    int skip=0;
    if(p==-1 || pairs[i][0] > pairs[p][1]) 
        take = 1 + solve(i+1,i,pairs);

    skip = 0 + solve(i+1,p,pairs);

    return max(take,skip);
}

int findLongestChain(vector<vector<int>>& pairs){
    //Sorting -> You can select pairs in any order.
    sort(pairs.begin(),pairs.end());

    int ans = solve(0,-1,pairs);
    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> pairs(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            int t;
            cin>>t;
            pairs[i].push_back(t);
        }
    }

    cout<<findLongestChain(pairs);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<pairs[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}