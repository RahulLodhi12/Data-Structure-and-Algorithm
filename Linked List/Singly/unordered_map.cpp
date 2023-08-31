#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int, string> hmap; // The unordered_map key can be stored in any order.
    hmap[1] = "Rahul";
    hmap[2] = "Raj";
    hmap[3] = "Raju";

    for(auto i:hmap){
        cout<<i.first<<" "<<i.second<<endl;
    }
    //The time complexity of unordered_map operations is O(1) on average.
}