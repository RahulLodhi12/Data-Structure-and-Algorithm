#include<iostream>
using namespace std;

int func(int n){
    if(n==0) return 1;

    return 2*func(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<func(n)<<endl;
}