#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(int i, int arr[], vector<int> &vec, int n){
    if(i>=n){
        for(auto item: vec)
            cout<<item<<" ";
    cout<<endl;
        return;
    }
    vec.push_back(arr[i]);
    printSubsequences(i+1,arr,vec,n); // Take

    vec.pop_back();
    printSubsequences(i+1,arr,vec,n); // Not Take
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int> vec;
    printSubsequences(0,arr,vec,n);
}