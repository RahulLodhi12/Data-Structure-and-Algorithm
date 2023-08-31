#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s; // creation of stack (using STL)

    s.push(6);
    s.push(3);
    s.push(7);

    s.pop(); // remove 7 from top

    cout<<s.top()<<endl;

    cout<<s.empty()<<endl; // return 0 or 1

    cout<<s.size()<<endl;

}