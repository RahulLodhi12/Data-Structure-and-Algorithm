#include<bits/stdc++.h>
using namespace std;


int solve(int i, int j, vector<int>& arr){
    //base cases
    if(i>j) return 0; //cost is zero.

    int ans = INT_MIN;
    for(int k=i;k<=j;k++){
        int tempAns = arr[i-1]*arr[k]*arr[j+1] + solve(i,k-1,arr) + solve(k+1,j,arr);
        ans = max(ans,tempAns);
    }
    return ans;
}

int maxCoins(vector<int>& arr){
    int n = arr.size();

    //to handle the out of bound case -> insert 1 at begin and end
    arr.insert(arr.begin(),1);
    arr.insert(arr.end(),1);

    int ans = solve(1,n,arr);
    return ans;
}

int main(){
    int size;
    cin>>size;

    vector<int> arr;

    for(int i=0;i<size;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    cout<<maxCoins(arr);
}