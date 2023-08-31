#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    if(s.find(5) == s.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }
}