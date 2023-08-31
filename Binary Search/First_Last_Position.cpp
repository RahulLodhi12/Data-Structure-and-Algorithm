#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Naive
vector<int> firstLast(int arr[], int n, int k){
    vector<int> ans;

    // first occ.
    for(int i=0;i<n;i++){
        if(k==arr[i]){
            ans.push_back(i);
            break;
        }
    }

    // last occ.
    for(int i=n-1;i>=0;i--){
        if(k==arr[i]){
            ans.push_back(i);
            break;
        }
    }

    return ans;
}


// Approach 2 - Using Binary Search
int firstPos(int arr[], int s, int e, int k){
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(k>arr[mid]){
            s=mid+1;
        }
            
        else if(k<arr[mid]){
            e=mid-1;
        }
            
        else{
            ans=mid;
            e=mid-1;
        }
    }
    return ans;
}

int lastPos(int arr[], int s, int e, int k){
    int ans=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(k>arr[mid]){
            s=mid+1;
        }
        else if(k<arr[mid]){
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[]={ 1, 3, 5, 5, 5, 5, 67, 123, 125};

    pair<int,int> p;

    // p.first = firstPos(arr,0,8,5);
    // p.second = lastPos(arr,0,8,5);
    // cout<<p.first<<" "<<p.second<<endl;

    vector<int> ans = firstLast(arr,9,5);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}