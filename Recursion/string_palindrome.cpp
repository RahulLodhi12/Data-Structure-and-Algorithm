#include<iostream>
using namespace std;

bool stringPalindrome(int i, string &st){
    int n = st.length();
    if(i>=n/2) return true;

    if(st[i] != st[n-i-1]) return false;

    return stringPalindrome(i+1,st);
}

int main(){
    string st;
    cin>>st;
    for(int i=0;i<st.length();i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    cout<<stringPalindrome(0,st)<<endl;
}