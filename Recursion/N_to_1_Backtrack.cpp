#include<iostream>
using namespace std;

void func(int i, int n){
    if(i>n){
        return;
    }
    func(i+1,n);
    cout<<i<<endl;
    // func(i-1,n); Not Allowed
}

int main(){
    int n;
    cin>>n;
    func(1,n);
}