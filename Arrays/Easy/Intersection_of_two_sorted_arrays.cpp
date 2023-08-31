#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
void intersectionArr1(vector<int>& arr1, vector<int>& arr2){
    vector<int> ans;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> vis(arr2.size(), 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j] && vis[j]==0){
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            else if(arr2[j]>arr1[i]){ // elements are sorted
                break;
            }
        }
    }

    for(auto it: ans){
        cout<<it<<" ";
    }
}

// Approach 2: Optimal Sol(Two Pointer)
vector<int> intersectionArr2(vector<int>& arr1, vector<int>& arr2){
    vector<int> ans;
    int n = arr1.size();
    int m = arr2.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 3, 5, 6, 6, 7};

    intersectionArr1(arr1,arr2);

    // vector<int> ans = intersectionArr2(arr1,arr2);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }
}