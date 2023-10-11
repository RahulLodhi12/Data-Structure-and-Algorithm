#include<bits/stdc++.h>
using namespace std;

void permutation(string s, int l, int r){
    //base case
    if(l==r){
        cout<<s<<" ";
        return;
    }

    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        permutation(s,l+1,r);
        swap(s[i],s[l]);
    }
}

int main(){
    string s = "ABB";

    permutation(s,0,2);
}