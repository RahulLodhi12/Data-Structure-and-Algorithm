#include<bits/stdc++.h>
using namespace std;

int multiple(int x, int t){
    int ans=1;
    for(int i=1;i<=t;i++){
        ans = ans*x;
    }
    return ans;
}

// Approach 1 - Using Linear Search
int func1(int n, int m){
    int ans=-1;
    for(int i=1;i<=m;i++){
        int num = multiple(i,n);
        if(num==m){
            ans=i;
        }
    }
    return ans;
}


// Approach 2 - Using Binary Search
int func2(int n, int m){
    int s=0;
    int e=m;
    while(s<=e){
        int mid = s+(e-s)/2;
        int num = multiple(mid,n);
        if(num>m){
            e=mid-1;
        }
        else if(num<m){
            s=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;

    cout<<func1(n,m);

    // cout<<func2(n,m);
}