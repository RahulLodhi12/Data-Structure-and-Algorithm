#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force(Using set)
void union1(vector<int>& arr1, vector<int>& arr2, int n, int m){
    set<int> st; // In set, keys are stored in sorted order (ascending order by default)
    for(int i=0;i<n;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        st.insert(arr2[i]);
    }
    int k = st.size();
    int ans[k];
    int p=0;
    for(auto it:st){
        ans[p++] = it;
    }

    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }

}


// Approach 2: Optimal Sol(Two Pointer)
vector<int> findUnion(vector<int>& arr1, vector<int>& arr2, int n, int m){
    vector<int> ans;
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){ // case 1 and case 2
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else{ // case 3
            if(ans.size()==0 || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    // remaining elements
    while(i<n){
        if(ans.back()!=arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while(j<m){
        if(ans.back()!=arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int> arr1 = {2,2,3,4,5};
    vector<int> arr2 = {1,1,2,3,4};
    int n = arr1.size();
    int m = arr2.size();

    union1(arr1,arr2,n,m);

    // vector<int> ans = findUnion(arr1,arr2,n,m);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }
}