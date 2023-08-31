#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using bit manipulation(brute force)
void powerSet(vector<int> v, vector<int>& ans){
    int n = v.size();
    for (int num=0; num<(1<<n);num++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                sum+=v[i];
            }
        }
        ans.push_back(sum);
    }
}
// T.C: O(2^n * n)
// S.C: O(2^n * n)

// ------------------------------------------------------------------------------------

// Approach 2: Using Recursion
void subSet(int i, vector<int> v, vector<int>& ans, int sum){
    int n=v.size();
    //base condn.
    if(i==n){
        ans.push_back(sum);
        return;
    }

    //pick
    subSet(i+1,v,ans,sum+v[i]);
    //not pick
    subSet(i+1,v,ans,sum);
}
// T.C: O(2^n)
// S.C: O(2^n)


int main(){
    vector<int> v{2,3};
    vector<int> ans;
    // powerSet(v, ans);
    subSet(0,v,ans,0);

    sort(ans.begin(),ans.end());

    for(auto it:ans){
        cout<<it<<" ";
    }
}