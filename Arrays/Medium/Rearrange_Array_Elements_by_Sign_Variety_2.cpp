#include<bits/stdc++.h>
using namespace std;

// Solution:
vector<int> func1(vector<int>& arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int ind = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[ind] = pos[i];
            ind++;
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int ind = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[ind] = neg[i];
            ind++;
        }
    }

    return arr;
}


int main(){
    vector<int> arr = {-1,2,3,4,-3,1};
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> ans = func1(arr,n);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}