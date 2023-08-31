#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;

    q.push(1);
    q.push(5);
    q.push(7);
    q.push(8);
    q.push(12);
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;

    q.pop();
    q.pop();

    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;

    cout<<"Empty: "<<q.empty()<<endl;
    cout<<"Size: "<<q.size()<<endl;
}