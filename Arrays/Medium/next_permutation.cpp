#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 2
vector<int> func2(vector<int>& arr){
    next_permutation(arr.begin() , arr.end());
    return arr;
}

int main(){
    vector<int> arr = {1,3,2};

    vector<int> ans = func2(arr);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}