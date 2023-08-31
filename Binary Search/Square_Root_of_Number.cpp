#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Linear Search
int func1(int n){
    int ans=-1;
    for(int i=0;i<=n;i++){
        if(i*i<=n){
            ans=i;
        }
    }
    return ans;
}

// Approach 2 - Using Binary Search
int func2(int n){
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        int num = mid*mid;
        if(num>n){
            e=mid-1;
        }
        else if(num<n){
            ans=mid;
            s=mid+1;
        }
        else{
            return mid;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<func1(n);

    // cout<<func2(n);
}