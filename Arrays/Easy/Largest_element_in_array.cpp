#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Sorting technique
int func1(vector<int>& arr){
    sort(arr.begin(),arr.end());
    
    return arr[arr.size()-1];
}


// Approach 2: Using max variable
int func2(vector<int>& arr){
    int max = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    vector<int> arr = {2,5,1,3,0};

    // cout<<func1(arr);

    cout<<func2(arr);
}