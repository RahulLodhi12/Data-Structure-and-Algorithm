#include<iostream>
using namespace std;

int fib(int n){
    if(n <= 1) return n;

    int last = fib(n-1);
    int slast = fib(n-2);
    return last + slast;
}

int main(){
    int n; cin>>n;
    cout<<fib(n);
}