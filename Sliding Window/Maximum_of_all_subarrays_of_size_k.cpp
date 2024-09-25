#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k){
    vector<int>ans;
    list<int>l;
    int i=0,j=0;
    int n = arr.size();
    while(j<n){
        //calc->j
        while(!l.empty() && l.back()<arr[j]){
            l.pop_back();
        }
        l.push_back(arr[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            ans.push_back(l.front());
            if(arr[i]==l.front()) l.pop_front();
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    int k;
    cin>>k;

    vector<int> ans = maxSlidingWindow(arr,k);

    for(auto it: ans){
        cout<<it<<" ";
    }
}
