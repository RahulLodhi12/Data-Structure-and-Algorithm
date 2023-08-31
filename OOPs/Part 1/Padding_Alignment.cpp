#include<bits/stdc++.h>
using namespace std;

class A{
    int a; // 4 byte           //   4
    char ch; // 1 byte         // 1 + 3(padding)

};

int main(){

    cout<<"Size of Class: "<<sizeof(A)<<endl;
}

/*
Padding is the addition of some empty bytes of memory 
in the structure to naturally align the data members in the memory.
Padding is complier dependent and some kind of greedy.
*/
