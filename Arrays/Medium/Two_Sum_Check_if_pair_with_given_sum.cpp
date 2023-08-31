#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
vector<int> twoSum1(vector<int>& arr, int n, int k){
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == k){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1,-1};
}

// Appproach 2: Better Solution(Using map)
vector<int> twoSum2(vector<int>& arr, int n, int k){
    vector<int> ans;
    map<int,int> mpp; //map<key,value> -> map<element,index> -> map[key] = value -> map[element] = index
    for(int i=0;i<n;i++){
        int el = k-arr[i];
        if(mpp.find(el)!=mpp.end()){ // found it. 
            ans.push_back(mpp[el]); //1.found wala;  mpp.find(el) -> indicate first part(element) of map.
            ans.push_back(i);       //2.index(i)
            return ans;
        }
        mpp[arr[i]] = i; // push element in map.(in case of not found)
    }
    return {-1,-1};
}

// Approach 3: Optimal Solution(Using Binary Search)/ Two pointer/ without using map data structure.
vector<int> twoSum3(vector<int>& arr, int n, int k){
    vector<int> ans;
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<j){
        int sum = arr[i]+arr[j];
        if(sum<k){
            i++;
        }
        else if(sum==k){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else{
            j--;
        }
    }
    return {-1,-1};
}

int main(){
    vector<int> arr = {2,6,5,8,11};
    int n = arr.size();
    int k=14;

    // vector<int> ans = twoSum1(arr,n,k);

    vector<int> ans = twoSum2(arr,n,k);

    // vector<int> ans = twoSum3(arr,n,k);

    for(auto it: ans){
        cout<<it<<" ";
    }
}