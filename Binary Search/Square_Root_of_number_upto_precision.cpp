#include<bits/stdc++.h>
using namespace std;

int func(int n){
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

float precision(int val, int n){
    float pre = 1;
    float fans = val;
    for(int i=1;i<=3;i++){
        pre=pre/10;
        for(float j=fans;j*j<=n;j+=pre){
            fans=j;
        }
    }
    return fans;
}

int main(){
    int n;
    cin>>n;

    int val = func(n);
    cout<<precision(val,n);
}