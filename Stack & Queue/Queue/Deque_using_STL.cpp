#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> d;

    d.push_front(13);
    d.push_front(32);
    d.push_back(45);

    cout<<"Front: "<<d.front()<<endl;
    cout<<"Rear: "<<d.back()<<endl;

    d.push_back(58);

    cout<<"Front: "<<d.front()<<endl;
    cout<<"Rear: "<<d.back()<<endl;

    d.pop_back();
    d.pop_front();

    cout<<"Front: "<<d.front()<<endl;
    cout<<"Rear: "<<d.back()<<endl;    
}