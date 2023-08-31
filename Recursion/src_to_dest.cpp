#include<iostream>
using namespace std;

void func(int src, int dest){
    cout<<"Source: "<<src<<" "<<"Destination: "<<dest<<endl;
    if(src == dest){
        cout<<"Reached!!"<<endl;
        return;
    }
    func(src+1, dest);
}

int main(){
    int src, dest;
    cout<<"Enter Source: ";
    cin>>src;
    cout<<"Enter Destination: ";
    cin>>dest;
    func(src,dest);
}