#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int k){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {6, 7, 8, 4, 1};
    
    cout<<linearSearch(arr,4)<<endl;
}