#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto it = find(vec.begin(), vec.end(), 4);
    int index = it - vec.begin();
    cout<<index<<endl;
    // cout<<vec[0]<<" "<<vec[3]<<" "<<endl;
    // int n;
    // cin>>n;
    // int val;
    // for(int i=0;i<n;i++){
    //     cin>>val;
    //     vec.push_back(val);
    // }
    
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    for(auto element:vec){
        cout<<element<<" ";
    }

    vec.pop_back();

    cout<<endl;
    for(auto element:vec){
        cout<<element<<" ";
    }
    cout<<endl;

    cout<<accumulate(vec.begin(),vec.end(),0);
}