#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Recursion
unordered_map<int,int> mpp;
bool solve(int cs_ind, int pj, vector<int>& stones){
    //base case
    if(cs_ind == stones.size()-1) return true;

    bool res=false;
    for(int nj=pj-1;nj<=pj+1;nj++){
        if(nj>0){
            int ns =  stones[cs_ind] + nj;
            if(mpp.find(ns) != mpp.end()){// found it
                res = res || solve(mpp[ns],nj,stones);
            }
        }
    }
    return res;
}
bool canCross(vector<int>& stones){
    for(int i=0;i<stones.size();i++){
        mpp[stones[i]] = i;
    }

    int ans = solve(0,0,stones);

    return ans;
}

//Approach 2: Using DP
// Tommorrow

int main(){
    int n;
    cin>>n;
    vector<int> stones;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        stones.push_back(t);
    }

    cout<<canCross(stones);
}